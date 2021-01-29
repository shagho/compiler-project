#include "typechecker.hpp"

typeChecker::typeChecker(antlr4::tree::ParseTreeProperty<symtab::scope *> scopes, std::unordered_map<std::string, symtab::scope *> scopess, std::vector<Error> errors)
{
    this->scopes = scopes;
    this->scopess = scopess;
    this->errors = errors;
    INT->setType(new symtab::type("int", "int", ""));
    STRING->setType(new symtab::type("string", "string", ""));
    FLOAT->setType(new symtab::type("float", "float", ""));
    BOOL->setType(new symtab::type("bool", "bool", ""));
    NIL->setType(new symtab::type("nil", "nil", ""));
}

symtab::symbol* typeChecker::scope_call(antlr4::ParserRuleContext *ctx)
{
    currentScope = scopes.get(ctx);
    visitChildren(ctx);
    currentScope = currentScope->getEnclosing_scope();
    return nullptr;
}

std::vector<Error> typeChecker::getErrors() const
{
    return errors;
}

antlrcpp::Any typeChecker::visitStart_func(Parse::Start_funcContext *context)
{
    return scope_call(context);
}

antlrcpp::Any typeChecker::visitType_def(Parse::Type_defContext *context)
{
    return scope_call(context);
}

antlrcpp::Any typeChecker::visitVar_def(Parse::Var_defContext *ctx)
{
    if(ctx->CONST() != nullptr)
    {
        for(int i = 0; i < ctx->var_val().size(); i++)
        {
            if(ctx->var_val()[i]->expr() == nullptr)
            {
                errors.push_back(Error("this symbol should be intialized", ctx->var_val()[i]->ref()->getStart()->getLine(), ctx->var_val()[i]->ref()->getStart()->getCharPositionInLine()));
            }
        }
    }
    return visitChildren(ctx);
}

antlrcpp::Any typeChecker::visitFun_def(Parse::Fun_defContext *ctx)
{
    return scope_call(ctx);
}

antlrcpp::Any typeChecker::visitDestructs(Parse::DestructsContext *ctx)
{
    symtab::symbol *s = currentScope->resolve<symtab::symbol>(ctx->ID()->getText());
    if(s == nullptr)
    {
        errors.push_back(Error("this symbol isn't defined", ctx->ID()->getSymbol()->getLine(), ctx->ID()->getSymbol()->getCharPositionInLine()));
        symtab::symbol *s = new symtab::symbol("null");
        s->setIsNull(true);
        return s;
    }

    else
    {
        if(!s->getIsArray() || s->getDefinedType() == "")
        {
            errors.push_back(Error("this symbol isn't an array or a class", ctx->ID()->getSymbol()->getLine(), ctx->ID()->getSymbol()->getCharPositionInLine()));
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }

        if(s->getDefinedType() != "")
        {
            if(scopess.find(s->getDefinedType()) == scopess.end())
            {
                errors.push_back(Error("symbol type isn't defined", ctx->ID()->getSymbol()->getLine(), ctx->ID()->getSymbol()->getCharPositionInLine()));
                symtab::symbol *s = new symtab::symbol("null");
                s->setIsNull(true);
                return s;            }

            if(s->getDimension() != ctx->BL().size())
            {
                errors.push_back(Error("dimensions are not the same", ctx->ID()->getSymbol()->getLine(), ctx->ID()->getSymbol()->getCharPositionInLine()));
                symtab::symbol *s = new symtab::symbol("null");
                s->setIsNull(true);
                return s;            }
        }

        if(s->getIsArray())
        {
            if(s->getDimension() != ctx->BL().size())
            {
                errors.push_back(Error("dimensions are not the same", ctx->ID()->getSymbol()->getLine(), ctx->ID()->getSymbol()->getCharPositionInLine()));
                symtab::symbol *s = new symtab::symbol("null");
                s->setIsNull(true);
                return s;            }
        }
    }
    symtab::symbol *r = new symtab::symbol("null");
    r->setIsNull(true);
    return r;
}

antlrcpp::Any typeChecker::visitAssign(Parse::AssignContext *ctx)
{
    if(ctx->var().size() == 1)
    {
        symtab::symbol *s = visit(ctx->var()[0]);
        symtab::symbol *r = visit(ctx->expr());
        if(s->getIsNull() || r->getIsNull())
        {
            errors.push_back(Error("symbol isn't convertible to other symbol", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }
        if(!r->is_convertible(s))
        {
            errors.push_back(Error("symbol isn't convertible to other symbol", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }

    }

    else
    {
        symtab::symbol *s = visit(ctx->expr());
        if(s->getIsNull())
            return s;
        if(dynamic_cast<symtab::functionSymbol*>(s) == nullptr)
        {
            errors.push_back(Error("symbol isn't a function", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }

        if(dynamic_cast<symtab::functionSymbol*>(s)->getReturn_types().size() != ctx->var().size())
        {
            errors.push_back(Error("function signature isn't compatible with arguments", ctx->var()[0]->getStart()->getLine(), ctx->var()[0]->getStart()->getCharPositionInLine()));
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }

        for(int i = 0; i < ctx->var().size(); i++)
        {
            symtab::symbol *r = visit(ctx->var()[i]);
            if(!dynamic_cast<symtab::functionSymbol*>(s)->getReturn_types()[i]->is_convertible(r))
            {
                errors.push_back(Error("paramter is not convertible", ctx->var()[i]->getStart()->getLine(), ctx->var()[i]->getStart()->getCharPositionInLine()));
                symtab::symbol *s = new symtab::symbol("null");
                s->setIsNull(true);
                return s;
            }
        }
    }
    return visitChildren(ctx);
}

antlrcpp::Any typeChecker::visitVar(Parse::VarContext *ctx)
{
    if(ctx->SUPER() != nullptr || ctx->THIS() != nullptr)
    {
        if(dynamic_cast<symtab::methodSymbol*>(currentScope) == nullptr)
        {
            errors.push_back(Error("this or super illegal use", ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine()));
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }

        if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope()) == nullptr)
        {
            errors.push_back(Error("this or super illegal use", ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine()));
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }

        if(ctx->SUPER() != nullptr)
        {
           if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope() == nullptr)
           {
               errors.push_back(Error("this class haven't super class", ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine()));
               symtab::symbol *s = new symtab::symbol("null");
               s->setIsNull(true);
               return s;
           }
           if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope() != nullptr)
           {
               symtab::symbol *t = nullptr;
               symtab::scope *p = nullptr;
               for(int i = 0; i < ctx->ref().size(); i++)
               {
                   symtab::symbol *s = visit(ctx->ref()[i]);
                   if(s->getIsNull())
                       return s;
                   if(i == 0)
                   {
                        if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope()->resolveForClassMembers<symtab::fieldSymbol>(s->getName()) == nullptr)
                        {
                            errors.push_back(Error("this field dosen't exist", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                            symtab::symbol *s = new symtab::symbol("null");
                            s->setIsNull(true);
                            return s;
                        }

                        if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope()->resolveForClassMembers<symtab::fieldSymbol>(s->getName()) != nullptr)
                        {
                            symtab::fieldSymbol *field = dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope()->resolveForClassMembers<symtab::fieldSymbol>(s->getName());
                            if(field->getAccessPointString() == "private")
                            {
                                errors.push_back(Error("this field is private", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                symtab::symbol *s = new symtab::symbol("null");
                                s->setIsNull(true);
                                return s;
                            }

                            if(field->getDefinedType() != "")
                            {
                                p = scopess.at(field->getDefinedType());
                                t = nullptr;
                            }

                            if(field->getDefinedType() == "")
                            {
                                t = field;
                                p = nullptr;
                            }

                            if(s->getDimension() != field->getDimension())
                            {
                                errors.push_back(Error("field dimension isn't match", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                symtab::symbol *s = new symtab::symbol("null");
                                s->setIsNull(true);
                                return s;
                            }

                            if(i == (int(ctx->ref().size()) - 1))
                            {
                                if(t != nullptr)
                                    return t;
                                return dynamic_cast<symtab::class_symbol*>(p);
                            }

                        }
                   }

                   else
                   {
                       if(p != nullptr)
                       {
                           symtab::fieldSymbol *r = dynamic_cast<symtab::class_symbol*>(p)->resolveForClassMembers<symtab::fieldSymbol>(s->getName());
                           if(r == nullptr )
                           {
                               errors.push_back(Error("this field dosen't exist", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                               symtab::symbol *s = new symtab::symbol("null");
                               s->setIsNull(true);
                               return s;
                           }

                           else if(r != nullptr)
                           {
                               if(r->getAccessPointString() == "private" || r->getAccessPointString() == "protected")
                               {
                                   errors.push_back(Error("this field is private", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                   symtab::symbol *s = new symtab::symbol("null");
                                   s->setIsNull(true);
                                   return s;
                               }

                               if(r->getDefinedType() != "")
                               {
                                   p = scopess.at(r->getDefinedType());
                                   dynamic_cast<symtab::class_symbol*>(p)->setAccess_modifier(r->getAccessPointString());
                                   t = nullptr;
                               }

                               if(r->getDefinedType() == "")
                               {
                                   t = r;
                                   p = nullptr;
                               }

                               if(i == ctx->ref().size() - 1)
                               {
                                   if(t != nullptr)
                                       return t;
                                   return dynamic_cast<symtab::class_symbol*>(p);
                               }
                           }
                       }

                       else if(t != nullptr)
                       {
                           if(i < ctx->ref().size() - 1)
                           {
                               errors.push_back(Error("this field isn't a type", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                               symtab::symbol *s = new symtab::symbol("null");
                               s->setIsNull(true);
                               return s;
                           }

//                           if(s->getDimension() != t->getDimension())
//                           {
//                               errors.push_back(Error("field dimension isn't match", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
//                               return nullptr;
//                           }

                           if(i == ctx->ref().size() - 1)
                           {
                               errors.push_back(Error("this field isn't a type", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                               symtab::symbol *s = new symtab::symbol("null");
                               s->setIsNull(true);
                               return s;
                           }
                       }
                   }
               }
           }

        }

        if(ctx->THIS() != nullptr)
        {
            symtab::symbol *t = nullptr;
            symtab::scope *p = nullptr;
            for(int i = 0; i < ctx->ref().size(); i++)
            {
                symtab::symbol *s = visit(ctx->ref()[i]);
                if(s->getIsNull())
                    return s;
                if(i == 0)
                {
                    if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->resolveForClassMembers<symtab::fieldSymbol>(s->getName()) == nullptr)
                    {
                        if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope() == nullptr || dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope()->resolveForClassMembers<symtab::fieldSymbol>(s->getName()) == nullptr)

                        {
                            errors.push_back(Error("this field dosen't exist", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                            symtab::symbol *s = new symtab::symbol("null");
                            s->setIsNull(true);
                            return s;
                        }
                    }

                    if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->resolveForClassMembers<symtab::fieldSymbol>(s->getName()) != nullptr)
                    {
                        symtab::fieldSymbol *field = dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->resolveForClassMembers<symtab::fieldSymbol>(s->getName());
//                        if(field->getAccessPointString() == "private")
//                        {
//                            errors.push_back(Error("this field is private", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
//                            symtab::symbol *s = new symtab::symbol("null");
//                            s->setIsNull(true);
//                            return s;
//                        }

                        if(field->getDefinedType() != "")
                        {
                            p = scopess.at(field->getDefinedType());
                            dynamic_cast<symtab::class_symbol*>(p)->setAccess_modifier(field->getAccessPointString());
                            t = nullptr;
                        }

                        if(field->getDefinedType() == "")
                        {
                            t = field;
                            p = nullptr;
                        }

                        if(s->getDimension() != field->getDimension())
                        {
                            errors.push_back(Error("field dimension isn't match", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                            return nullptr;
                        }

                        if(i == (int(ctx->ref().size()) - 1))
                        {
                            if(t != nullptr)
                                return t;
                            return dynamic_cast<symtab::class_symbol*>(p);
                        }
                    }

                    else if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope() != nullptr)
                    {
                        if(dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope()->resolveForClassMembers<symtab::fieldSymbol>(s->getName()) != nullptr)
                        {
                            symtab::fieldSymbol *field = dynamic_cast<symtab::class_symbol*>(currentScope->getEnclosing_scope())->getSuperClassScope()->resolveForClassMembers<symtab::fieldSymbol>(s->getName());
                            if(field->getAccessPointString() == "private")
                            {
                                errors.push_back(Error("this field is private", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                symtab::symbol *s = new symtab::symbol("null");
                                s->setIsNull(true);
                                return s;
                            }

                            if(field->getDefinedType() != "")
                            {
                                p = scopess.at(field->getDefinedType());
                                dynamic_cast<symtab::class_symbol*>(p)->setAccess_modifier(field->getAccessPointString());
                                t = nullptr;
                            }

                            if(field->getDefinedType() == "")
                            {
                                t = field;
                                p = nullptr;
                            }

                            if(s->getDimension() != field->getDimension())
                            {
                                errors.push_back(Error("field dimension isn't match", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                return nullptr;
                            }

                            if(i == (int(ctx->ref().size()) - 1))
                            {
                                if(t != nullptr)
                                    return t;
                                return dynamic_cast<symtab::class_symbol*>(p);
                            }
                        }
                    }
                }

                else
                {
                    if(p != nullptr)
                    {
                        symtab::fieldSymbol *r = dynamic_cast<symtab::class_symbol*>(p)->resolveForClassMembers<symtab::fieldSymbol>(s->getName());
                        if(r == nullptr )
                        {
                            errors.push_back(Error("this field dosen't exist", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                            symtab::symbol *s = new symtab::symbol("null");
                            s->setIsNull(true);
                            return s;
                        }

                        else if(r != nullptr)
                        {
                            if(r->getAccessPointString() == "private" || r->getAccessPointString() == "protected")
                            {
                                errors.push_back(Error("this field is private or protected", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                symtab::symbol *s = new symtab::symbol("null");
                                s->setIsNull(true);
                                return s;
                            }

                            if(r->getDefinedType() != "")
                            {
                                p = scopess.at(r->getDefinedType());
                                dynamic_cast<symtab::class_symbol*>(p)->setAccess_modifier(r->getAccessPointString());
                                t = nullptr;
                            }

                            if(r->getDefinedType() == "")
                            {
                                t = r;
                                p = nullptr;
                            }

                            if(i == ctx->ref().size() - 1)
                            {
                                if(t != nullptr)
                                    return t;
                                return dynamic_cast<symtab::class_symbol*>(p);
                            }
                        }
                    }

                    else if(t != nullptr)
                    {
                        if(i < ctx->ref().size() - 1)
                        {
                            errors.push_back(Error("this field isn't a type", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                            symtab::symbol *s = new symtab::symbol("null");
                            s->setIsNull(true);
                            return s;
                        }

//                        if(s->getDimension() != t->getDimension())
//                        {
//                            errors.push_back(Error("field dimension isn't match", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
//                            return nullptr;
//                        }

                        if(i == ctx->ref().size() - 1)
                        {
                            errors.push_back(Error("this field isn't a type", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                            symtab::symbol *s = new symtab::symbol("null");
                            s->setIsNull(true);
                            return s;
                        }
                    }
                }
            }
        }
    }

    else
    {
        symtab::symbol *t = nullptr;
        symtab::scope *p = nullptr;
        for(int i = 0; i < ctx->ref().size(); i++)
        {
            symtab::symbol *s = visit(ctx->ref()[i]);

            if(s->getIsNull())
                return s;
            if(i == 0)
            {
                   if(currentScope->resolve<symtab::symbol>(s->getName()) == nullptr)
                   {
                       errors.push_back(Error("this value dosen't exist", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                       s->setIsNull(true);
                       return s;
                   }
                   symtab::symbol *r = currentScope->resolve<symtab::symbol>(s->getName());
                   if(r != nullptr)
                   {
                       if(r->getDimension() != s->getDimension())
                       {
                           errors.push_back(Error("dimensions are not same", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                           s->setIsNull(true);
                           return s;
                       }

                       if(r->getDefinedType() != "")
                       {
                           p = scopess.at(r->getDefinedType());
                           t = nullptr;
                       }

                       if(r->getDefinedType() == "")
                       {
                           p = nullptr;
                           t = r;
                       }

                       if(i == ctx->ref().size() - 1)
                       {
                           if(p != nullptr)
                               return dynamic_cast<symtab::class_symbol*>(p);
                           return t;
                       }
                   }
            }

            else
            {
                    if(p != nullptr)
                    {
                        symtab::fieldSymbol * r = dynamic_cast<symtab::class_symbol*>(p)->resolveForClassMembers<symtab::fieldSymbol>(s->getName());
                        symtab::fieldSymbol * d = nullptr;
                        if(dynamic_cast<symtab::class_symbol*>(p)->getSuperClassScope() != nullptr)
                            d = dynamic_cast<symtab::class_symbol*>(p)->getSuperClassScope()->resolveForClassMembers<symtab::fieldSymbol>(s->getName());
                        if(r == nullptr && d == nullptr)
                        {
                            errors.push_back(Error("this field doesn't exist", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                            s->setIsNull(true);
                            return s;
                        }

                        if(r != nullptr)
                        {
                            if(r->getAccessPointString() == "private" || r->getAccessPointString() == "protected")
                            {
                                errors.push_back(Error("this field is private or protected", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                s->setIsNull(true);
                                return s;
                            }

                            if(r->getDimension() != s->getDimension())
                            {
                                errors.push_back(Error("dimensions are not same", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                s->setIsNull(true);
                                return s;
                            }

                            if(r->getDefinedType() != "")
                            {
                                p = scopess.at(r->getDefinedType());
                                t = nullptr;
                            }

                            if(r->getDefinedType() == "")
                            {
                                p = nullptr;
                                t = r;
                            }
                        }

                        if(d != nullptr)
                        {
                            if(d->getAccessPointString() == "private")
                            {
                                errors.push_back(Error("this field is private", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                s->setIsNull(true);
                                return s;
                            }

                            if(d->getDimension() != s->getDimension())
                            {
                                errors.push_back(Error("dimensions are not same", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                                s->setIsNull(true);
                                return s;
                            }

                            if(d->getDefinedType() != "")
                            {
                                p = scopess.at(d->getDefinedType());
                                t = nullptr;
                            }

                            if(d->getDefinedType() == "")
                            {
                                p = nullptr;
                                t = d;
                            }
                        }

                        if(i == (ctx->ref().size() -1))
                        {
                            if(t != nullptr)
                                return t;
                            return dynamic_cast<symtab::class_symbol*>(p);
                        }
                    }

                    else if(t != nullptr)
                    {
                        if(i < (ctx->ref().size() - 1))
                        {
                            errors.push_back(Error("this field isn't a type", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                            s->setIsNull(true);
                            return s;
                        }

                        if(i == (ctx->ref().size() - 1))
                        {
                            errors.push_back(Error("this field isn't a type", ctx->ref()[i]->getStart()->getLine(), ctx->ref()[i]->getStart()->getCharPositionInLine()));
                            symtab::symbol *s = new symtab::symbol("null");
                            s->setIsNull(true);
                            return s;
                        }
                    }
            }
        }
    }
    symtab::symbol *s = new symtab::symbol("null");
    s->setIsNull(true);
    return s;
    ;
}

antlrcpp::Any typeChecker::visitRef(Parse::RefContext *ctx)
{
    symtab::symbol *s = new symtab::symbol(ctx->ID()->getText());
    s->setDimension(ctx->expr().size());
    for(int i = 0; i < ctx->expr().size(); i++)
    {
        symtab::symbol *d = visit(ctx->expr()[i]);
        if(d == nullptr)
            return nullptr;
        if(!d->is_convertible(INT))
        {
            errors.push_back(Error("array index should be int", ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine()));
            s->setIsNull(true);
            return s;
        }
    }
    return s;
}

antlrcpp::Any typeChecker::visitRelational2Op(Parse::Relational2OpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol *s = visit(ctx->expr()[0]);
        symtab::symbol *p = visit(ctx->expr()[1]);
        if(s->getIsNull() || p->getIsNull())
        {
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }
        if(s->is_convertible(p) || p->is_convertible(s))
            return BOOL;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + " isn't convertible to " + ctx->expr()[1]->getText() + "and vice versa", ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    symtab::symbol *s = new symtab::symbol("null");
    s->setIsNull(true);
    return s;
}

antlrcpp::Any typeChecker::visitNull(Parse::NullContext *context)
{
    return NIL;
}

antlrcpp::Any typeChecker::visitUnaryOp(Parse::UnaryOpContext *ctx)
{
    symtab::symbol *expr = visit(ctx->expr());
    if(expr->getIsNull())
    {
        symtab::symbol *s = new symtab::symbol("null");
        s->setIsNull(true);
        return s;
    }
    if(ctx->unary_op()->getText() == "~")
    {
        if(expr->is_convertible(INT))
            return INT;
        else
            errors.push_back(Error("Expression" + ctx->expr()->getText() + "is not convertible to int", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
    }

    if(ctx->unary_op()->getText() == "!")
    {
        if(expr->is_convertible(BOOL))
            return BOOL;
        else
            errors.push_back(Error("Expression" + ctx->expr()->getText() + "is not convertible to bool", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
    }

    if(ctx->unary_op()->getText() == "-")
    {
        if(expr->is_convertible(FLOAT))
            return FLOAT;
        else
            errors.push_back(Error("Expression" + ctx->expr()->getText() + "is not convertible to float", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
    }

    symtab::symbol *s = new symtab::symbol("null");
    s->setIsNull(true);
    return s;
}

antlrcpp::Any typeChecker::visitRelational13Op(Parse::Relational13OpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol *s = visit(ctx->expr()[0]);
        symtab::symbol *p = visit(ctx->expr()[1]);
        if(s->getIsNull() || p->getIsNull())
        {
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }
        if(s->is_convertible(p) || p->is_convertible(s))
            return BOOL;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + " isn't convertible to " + ctx->expr()[1]->getText() + "and vice versa", ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    symtab::symbol *s = new symtab::symbol("null");
    s->setIsNull(true);
    return s;
}

antlrcpp::Any typeChecker::visitLogicalOp(Parse::LogicalOpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol *s = visit(ctx->expr()[0]);
        symtab::symbol *p = visit(ctx->expr()[1]);
        if(s->getIsNull() || p->getIsNull())
        {
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }

        if(s->is_convertible(BOOL) && p->is_convertible(BOOL))
            return BOOL;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + " and " + ctx->expr()[1]->getText() + " are not convertible to bool", ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    symtab::symbol *s = new symtab::symbol("null");
    s->setIsNull(true);
    return s;
}

antlrcpp::Any typeChecker::visitAllocateOp(Parse::AllocateOpContext *ctx)
{
    if(scopess.find(ctx->handle_call()->ID()->getText()) == scopess.end())
    {
        errors.push_back(Error("Undefined symbol", ctx->handle_call()->getStart()->getLine(), ctx->handle_call()->getStart()->getCharPositionInLine()));
        symtab::symbol *s = new symtab::symbol("null");
        s->setIsNull(true);
        return s;
    }
    return scopess.at(ctx->handle_call()->ID()->getText());
}

antlrcpp::Any typeChecker::visitConstValOp(Parse::ConstValOpContext *ctx)
{
        if(ctx != nullptr)
        {
            if(ctx->const_val()->BOOL_CONST() != nullptr)
            {

                BOOL->setType(new symtab::type("bool", "bool", ctx->const_val()->getText()));
                return BOOL;
            }

            if(ctx->const_val()->INT_CONST() != nullptr)
            {
                INT->setType(new symtab::type("int", "int", ctx->const_val()->getText()));
                return INT;
            }

            if(ctx->const_val()->REAL_CONST() != nullptr)
            {
                FLOAT->setType(new symtab::type("float", "float", ctx->const_val()->getText()));
                return FLOAT;
            }

            if(ctx->const_val()->STRING_CONST() != nullptr)
            {
                STRING->setType(new symtab::type("string", "string", ctx->const_val()->getText()));
                return STRING;
            }
        }
        symtab::symbol *s = new symtab::symbol("null");
        s->setIsNull(true);
        return s;
}

antlrcpp::Any typeChecker::visitBitwiseOp(Parse::BitwiseOpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol *s = visit(ctx->expr()[0]);
        symtab::symbol *p = visit(ctx->expr()[1]);
        if(s->getIsNull() || p->getIsNull())
        {
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }
        if(s->is_convertible(INT) && p->is_convertible(INT))
            return INT;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + " and " + ctx->expr()[1]->getText() + " are not convertible to int", ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    symtab::symbol *s = new symtab::symbol("null");
    s->setIsNull(true);
    return s;
}

antlrcpp::Any typeChecker::visitArithmetic2Op(Parse::Arithmetic2OpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol *s = visit(ctx->expr()[0]);
        symtab::symbol *p = visit(ctx->expr()[1]);
        if(s->getIsNull() || p->getIsNull())
        {
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }

        if(s->is_convertible(p))
            return p;
        else if (p->is_convertible(s))
            return s;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + "isn't convertible to " + ctx->expr()[1]->getText() + " and vice versa", ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    symtab::symbol *s = new symtab::symbol("null");
    s->setIsNull(true);
    return s;
}

antlrcpp::Any typeChecker::visitArithmetic1Op(Parse::Arithmetic1OpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol *s = visit(ctx->expr()[0]);
        symtab::symbol *p = visit(ctx->expr()[1]);
        if(s->getIsNull() || p->getIsNull())
        {
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }
        if(s->is_convertible(p))
            return p;
        else if (p->is_convertible(s))
            return s;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + "is not convertible to " + ctx->expr()[1]->getText(), ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    symtab::symbol *s = new symtab::symbol("null");
    s->setIsNull(true);
    return s;
}

antlrcpp::Any typeChecker::visitParenthesisOp(Parse::ParenthesisOpContext *ctx)
{
    return visit(ctx->expr());
}

antlrcpp::Any typeChecker::visitDotClall(Parse::DotClallContext *ctx)
{
    if(ctx->var() != nullptr)
    {
        symtab::symbol *s = visit(ctx->var());
        if(s->getIsNull())
            return s;

        if(dynamic_cast<symtab::class_symbol*>(s) == nullptr)
        {
            errors.push_back(Error("variable isn't a class", ctx->var()->getStart()->getLine(), ctx->var()->getStart()-> getCharPositionInLine()));
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }

        if(dynamic_cast<symtab::class_symbol*>(s) != nullptr)
        {
            symtab::methodSymbol * method = dynamic_cast<symtab::class_symbol*>(s)->resolveForClassMembers<symtab::methodSymbol>(ctx->handle_call()->ID()->getText());

            if(dynamic_cast<symtab::class_symbol*>(s)->resolveForClassMembers<symtab::methodSymbol>(ctx->handle_call()->ID()->getText()) == nullptr)
            {
                if(dynamic_cast<symtab::class_symbol*>(s)->getSuperClassScope() != nullptr)
                {
                    method = dynamic_cast<symtab::class_symbol*>(s)->getSuperClassScope()->resolveForClassMembers<symtab::methodSymbol>(ctx->handle_call()->ID()->getText());

                    if(method == nullptr)
                    {
                        errors.push_back(Error("this symbol hasn't method with this name", ctx->handle_call()->ID()->getSymbol()->getLine(), ctx->handle_call()->ID()->getSymbol()->getCharPositionInLine()));
                        symtab::symbol *s = new symtab::symbol("null");
                        s->setIsNull(true);
                        return s;
                    }

                    if(method->getAccessPointString() == "private")
                    {
                        errors.push_back(Error("method is private or protected", ctx->handle_call()->ID()->getSymbol()->getLine(), ctx->handle_call()->ID()->getSymbol()->getCharPositionInLine()));
                        symtab::symbol *s = new symtab::symbol("null");
                        s->setIsNull(true);
                        return s;
                    }
                }
            }

            if(method == nullptr)
            {
                errors.push_back(Error("this symbol hasn't method with this name", ctx->handle_call()->ID()->getSymbol()->getLine(), ctx->handle_call()->ID()->getSymbol()->getCharPositionInLine()));
                symtab::symbol *s = new symtab::symbol("null");
                s->setIsNull(true);
                return s;
            }

            if(method != nullptr)
            {
                if(method->getAccessPointString() == "private" || method->getAccessPointString() == "protected")
                {
                    errors.push_back(Error("method is private or protected", ctx->handle_call()->ID()->getSymbol()->getLine(), ctx->handle_call()->ID()->getSymbol()->getCharPositionInLine()));
                    symtab::symbol *s = new symtab::symbol("null");
                    s->setIsNull(true);
                    return s;
                }

                auto f = method->getArguments();

                if(ctx->handle_call()->params() == nullptr && f.size() != 0)
                {
                    errors.push_back(Error("method parameters are not matching", ctx->handle_call()->params()->getStart()->getLine(), ctx->handle_call()->params()->getStart()->getCharPositionInLine()));
                    symtab::symbol *s = new symtab::symbol("null");
                    s->setIsNull(true);
                    return s;
                }

                if(ctx->handle_call()->params() != nullptr && f.size() == 0)
                {
                    errors.push_back(Error("method parameters are not matching", ctx->handle_call()->params()->getStart()->getLine(), ctx->handle_call()->params()->getStart()->getCharPositionInLine()));
                    symtab::symbol *s = new symtab::symbol("null");
                    s->setIsNull(true);
                    return s;
                }

                if(ctx->handle_call()->params() != nullptr)
                {
                    if(ctx->handle_call()->params()->expr().size() != f.size())
                    {
                        errors.push_back(Error("method parameters are not matching", ctx->handle_call()->params()->getStart()->getLine(), ctx->handle_call()->params()->getStart()->getCharPositionInLine()));
                        symtab::symbol *s = new symtab::symbol("null");
                        s->setIsNull(true);
                        return s;
                    }

                    else if (ctx->handle_call()->params()->expr().size() == f.size())
                    {
                        for(int i = 0; i < f.size(); i++)
                        {
                            symtab::symbol *symbol = visit(ctx->handle_call()->params()->expr()[i]);
                            if(symbol->getIsNull())
                                return symbol;

                            if(!symbol->is_convertible(f[i]))
                            {
                                errors.push_back(Error("method parameters are not matching", ctx->handle_call()->params()->expr()[i]->getStart()->getLine(), ctx->handle_call()->params()->expr()[i]->getStart()->getCharPositionInLine()));
                                symtab::symbol *s = new symtab::symbol("null");
                                s->setIsNull(true);
                                return s;
                            }
                        }

                        return method;
                    }
                }
            }
        }
    }

    else
    {
        symtab::scope *s = scopess.at(ctx->handle_call()->ID()->getText());
        if(s == nullptr || dynamic_cast<symtab::functionSymbol*>(s) == nullptr)
        {
            symtab::symbol *s = new symtab::symbol("null");
            s->setIsNull(true);
            return s;
        }
        else
        {
            auto f = dynamic_cast<symtab::functionSymbol*>(s)->getArguments();
            if(ctx->handle_call()->params() == nullptr && f.size() != 0)
            {
                errors.push_back(Error("method parameters are not matching", ctx->handle_call()->params()->getStart()->getLine(), ctx->handle_call()->params()->getStart()->getCharPositionInLine()));
                symtab::symbol *s = new symtab::symbol("null");
                s->setIsNull(true);
                return s;
            }

            if(ctx->handle_call()->params() != nullptr && f.size() == 0)
            {
                errors.push_back(Error("method parameters are not matching", ctx->handle_call()->params()->getStart()->getLine(), ctx->handle_call()->params()->getStart()->getCharPositionInLine()));
                symtab::symbol *s = new symtab::symbol("null");
                s->setIsNull(true);
                return s;
            }

            if(ctx->handle_call()->params() != nullptr)
            {
                if(ctx->handle_call()->params()->expr().size() != f.size())
                {
                    errors.push_back(Error("function parameters are not matching", ctx->handle_call()->params()->getStart()->getLine(), ctx->handle_call()->params()->getStart()->getCharPositionInLine()));
                    symtab::symbol *s = new symtab::symbol("null");
                    s->setIsNull(true);
                    return s;
                }

                else if(ctx->handle_call()->params()->expr().size() == f.size())
                {
                    for(int i = 0; i < f.size(); i++)
                    {
                        symtab::symbol *symbol = visit(ctx->handle_call()->params()->expr()[i]);
                        if(symbol->getIsNull())
                            return symbol;
                        if(!symbol->is_convertible(f[i]))
                        {
                            errors.push_back(Error("function parameters are not matching", ctx->handle_call()->params()->expr()[i]->getStart()->getLine(), ctx->handle_call()->params()->expr()[i]->getStart()->getCharPositionInLine()));
                            return nullptr;
                        }
                    }

                    return dynamic_cast<symtab::functionSymbol*>(s);
                }


            }
        }
    }

    symtab::symbol *s = new symtab::symbol("null");
    s->setIsNull(true);
    return s;
}

antlrcpp::Any typeChecker::visitReadFunc(Parse::ReadFuncContext *context)
{
    return STRING;
}

antlrcpp::Any typeChecker::visitWriteFunc(Parse::WriteFuncContext *ctx)
{
    return INT;
}

antlrcpp::Any typeChecker::visitIfElseCond(Parse::IfElseCondContext *ctx)
{
    return visitChildren(ctx);
}
antlrcpp::Any typeChecker::visitSwitchCond(Parse::SwitchCondContext *ctx)
{
    symtab::symbol * s = visit(ctx->var());
    if(s->getIsNull())
        return s;
    if(!s->is_convertible(INT))
    {
        errors.push_back(Error("swich condition isn't convertible to int", ctx->var()->getStart()->getLine(), ctx->var()->getStart()->getCharPositionInLine()));
        symtab::symbol *s = new symtab::symbol("null");
        s->setIsNull(true);
        return s;
    }
    visit(ctx->switch_body());
    symtab::symbol *r = new symtab::symbol("null");
    r->setIsNull(true);
    return r;
}

antlrcpp::Any typeChecker::visitIfBlock(Parse::IfBlockContext *ctx)
{
    symtab::symbol *s = visit(ctx->expr());
    if(s->getIsNull())
        return s;

    if(!s->is_convertible(BOOL))
    {
        errors.push_back(Error("if condition isn't convrtible to bool", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
        symtab::symbol *s = new symtab::symbol("null");
        s->setIsNull(true);
        return s;
    }
    if(ctx->block() != nullptr)
       return visit(ctx->block());
    if(ctx->stmt() != nullptr)
       return visit(ctx->stmt());
    symtab::symbol *r = new symtab::symbol("null");
    r->setIsNull(true);
    return r;
}

antlrcpp::Any typeChecker::visitElseBlock(Parse::ElseBlockContext *ctx)
{
    if(ctx->block() != nullptr)
       return visit(ctx->block());
    if(ctx->stmt() != nullptr)
       return visit(ctx->stmt());
}

antlrcpp::Any typeChecker::visitForLoop(Parse::ForLoopContext *ctx)
{
    symtab::symbol *s = visit(ctx->expr());
    if(s->getIsNull())
        return nullptr;

    if(!s->is_convertible(BOOL))
    {
        errors.push_back(Error("for condition isn't convertible to bool", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
        symtab::symbol *s = new symtab::symbol("null");
        s->setIsNull(true);
        return s;
    }

    return visitChildren(ctx);
    symtab::symbol *r = new symtab::symbol("null");
    r->setIsNull(true);
    return r;

}

antlrcpp::Any typeChecker::visitWhileLoop(Parse::WhileLoopContext *context)
{
    symtab::symbol *s = visit(context->expr());

    if(s->getIsNull())
        return s;

    if(!s->is_convertible(BOOL))
    {
        errors.push_back(Error("while condition isn't convertible to bool", context->expr()->getStart()->getLine(), context->expr()->getStart()->getCharPositionInLine()));
        symtab::symbol *s = new symtab::symbol("null");
        s->setIsNull(true);
        return s;
    }
    if(context->block() != nullptr)
       return  visit(context->block());

    if(context->stmt() != nullptr)
       return  visit(context->stmt());
}


