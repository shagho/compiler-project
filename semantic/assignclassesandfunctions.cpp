#include "assignclassesandfunctions.hpp"

assignClassesandfunctions::assignClassesandfunctions()
{

}

assignClassesandfunctions::assignClassesandfunctions(std::unordered_map<std::string, symtab::scope *> scopess, std::vector<Error> errors)
{
    this->scopess = scopess;
    this->errors = errors;
}

void assignClassesandfunctions::enterProgram(Parse::ProgramContext *)
{
    currentScope = &global;
}

void assignClassesandfunctions::enterType_def(Parse::Type_defContext * ctx)
{
    symtab::scope * clas = scopess.at(ctx->ID()[0]->getText());
    clas->setEnclosing_scope(currentScope);
    currentScope = clas;

    if(ctx->superType != nullptr)
    {
        if(scopess.find(ctx->superType->getText()) == scopess.end())
        {
            errors.push_back(Error("superclass doesn't exist", ctx->superType->getLine(), ctx->superType->getCharPositionInLine()));
        }
        else
        {
            dynamic_cast<symtab::class_symbol*>(currentScope)->setSuperClassName(ctx->superType->getText());
            dynamic_cast<symtab::class_symbol*>(currentScope)->setSuperClassScope(dynamic_cast<symtab::class_symbol*>(scopess.at(ctx->superType->getText())));
        }
    }
    save(ctx, currentScope);
}

void assignClassesandfunctions::exitType_def(Parse::Type_defContext * ctx)
{
    if(dynamic_cast<symtab::class_symbol*>(currentScope) != nullptr)
    {
        if(!currentScope->resolve<symtab::methodSymbol>(ctx->ID()[0]->getText()))
            errors.push_back(Error("class constructor is not defined", ctx->ID()[0]->getSymbol()->getLine(), ctx->ID()[0]->getSymbol()->getCharPositionInLine()));
        if(currentScope->resolve<symtab::methodSymbol>(ctx->ID()[0]->getText()) != nullptr)
            if(currentScope->resolve<symtab::methodSymbol>(ctx->ID()[0]->getText())->getReturn_types().size() != 0)
                errors.push_back(Error("class constructor has return value(s)", ctx->ID()[0]->getSymbol()->getLine(), ctx->ID()[0]->getSymbol()->getCharPositionInLine()));
    }

    currentScope = currentScope->getEnclosing_scope();
}

void assignClassesandfunctions::enterStart_func(Parse::Start_funcContext * ctx)
{
    symtab::scope *start = scopess.at("start");
    start->setEnclosing_scope(currentScope);
    symtab::symbol *s = new symtab::symbol(ctx->ID()->getText());
    s->setType(new symtab::type("int", ctx->ID()->getText(), ""));
    start->define(s);
    currentScope->define(dynamic_cast<symtab::functionSymbol*>(start));
    currentScope = start;

    save(ctx, start);
}

void assignClassesandfunctions::exitStart_func(Parse::Start_funcContext *)
{
    currentScope = currentScope->getEnclosing_scope();
}

void assignClassesandfunctions::enterVar_def(Parse::Var_defContext * ctx)
{
    if(isField)
    {
        for(int i = 0; i < ctx->var_val().size(); i++)
        {
            if(dynamic_cast<symtab::class_symbol*>(currentScope)->resolveForClassMembers<symtab::symbol>(ctx->var_val()[i]->ref()->ID()->getText()) != nullptr)
            {
                    errors.push_back(Error("Symbol already defined", ctx->var_val()[i]->ref()->ID()->getSymbol()->getLine(), ctx->var_val()[i]->ref()->ID()->getSymbol()->getCharPositionInLine()));
            }
            else if (dynamic_cast<symtab::class_symbol*>(currentScope)->getSuperClassName() != "")
            {
                if (dynamic_cast<symtab::class_symbol*>(currentScope)->getSuperClassScope()->resolveForClassMembers<symtab::methodSymbol>(ctx->var_val()[i]->ref()->ID()->getText()) != nullptr)
                {
                    errors.push_back(Error("Symbol already defined", ctx->var_val()[i]->ref()->ID()->getSymbol()->getLine(), ctx->var_val()[i]->ref()->ID()->getSymbol()->getCharPositionInLine()));
                }
            }
            else
            {
                if(access_modifier == "")
                {
                    symtab::fieldSymbol *field =new symtab::fieldSymbol(ctx->var_val()[i]->ref()->ID()->getText(), "private");
                    if(ctx->type()->getText() == "int" || ctx->type()->getText() == "string" || ctx->type()->getText() =="float" || ctx->type()->getText() == "bool")
                        field->setType(new symtab::type(ctx->type()->getText(), ctx->var_val()[i]->ref()->ID()->getText(), "foo"));
                    else
                    {
                        if(scopess.find(ctx->type()->getText()) != scopess.end())
                        {
                            field->setDefinedType(ctx->type()->getText());
                            field->setIsDefinedType(true);
                        }
                        else
                        {
                            errors.push_back(Error("undefind type", ctx->type()->getStart()->getLine(), ctx->type()->getStart()->getCharPositionInLine()));
                        }
                    }

                    if(ctx->CONST() != nullptr)
                    {
                        field->setConst_flag(true);
                    }

                    if(ctx->var_val()[i]->ref()->BL().size() != 0)
                    {
                        field->setIsArray(true);
                        field->setDimension(ctx->var_val()[i]->ref()->BL().size());
                    }
                    currentScope->define(field);
                }
                else
                {
                    symtab::fieldSymbol *field =new symtab::fieldSymbol(ctx->var_val()[i]->ref()->ID()->getText(), access_modifier);
                    if(ctx->type()->getText() == "int" || ctx->type()->getText() == "string" || ctx->type()->getText() =="float" || ctx->type()->getText() == "bool")
                        field->setType(new symtab::type(ctx->type()->getText(), ctx->var_val()[i]->ref()->ID()->getText(), "foo"));
                    else
                    {
                        if(scopess.find(ctx->type()->getText()) != scopess.end())
                        {
                            field->setDefinedType(ctx->type()->getText());
                            field->setIsDefinedType(true);
                        }
                        else
                        {
                            errors.push_back(Error("undefind type", ctx->type()->getStart()->getLine(), ctx->type()->getStart()->getCharPositionInLine()));
                        }
                    }
                    if(ctx->CONST() != nullptr)
                    {
                        field->setConst_flag(true);
                    }
                    if(ctx->var_val()[i]->ref()->BL().size() != 0)
                    {
                        field->setIsArray(true);
                        field->setDimension(ctx->var_val()[i]->ref()->BL().size());
                    }
                    currentScope->define(field);
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < ctx->var_val().size(); i++)
        {
            if(currentScope->getSymbol(ctx->var_val()[i]->ref()->ID()->getText()) != nullptr )
            {
                errors.push_back(Error("this variable is defiened", ctx->var_val()[i]->ref()->ID()->getSymbol()->getLine(), ctx->var_val()[i]->ref()->ID()->getSymbol()->getCharPositionInLine()));
            }
            else if (scopess.find(ctx->var_val()[i]->ref()->ID()->getText()) != scopess.end())
            {
                errors.push_back(Error("variable name such class or function name", ctx->var_val()[i]->ref()->ID()->getSymbol()->getLine(), ctx->var_val()[i]->ref()->ID()->getSymbol()->getCharPositionInLine()));
            }
            else
            {
                symtab::symbol *variable =new symtab::symbol(ctx->var_val()[i]->ref()->ID()->getText());
                if(ctx->type()->getText() == "int" || ctx->type()->getText() == "string" || ctx->type()->getText() =="float" || ctx->type()->getText() == "bool")
                    variable->setType(new symtab::type(ctx->type()->getText(), ctx->var_val()[i]->ref()->ID()->getText(), "foo"));
                else
                {
                    if(scopess.find(ctx->type()->getText()) != scopess.end())
                    {
                        variable->setDefinedType(ctx->type()->getText());
                        variable->setIsDefinedType(true);
                    }
                    else
                    {
                        errors.push_back(Error("undefind type", ctx->type()->getStart()->getLine(), ctx->type()->getStart()->getCharPositionInLine()));
                    }
                }
                if(ctx->CONST() != nullptr)
                {
                    variable->setConst_flag(true);
                }

                if(ctx->var_val()[i]->ref()->BL().size() != 0)
                {
                    variable->setIsArray(true);
                    variable->setDimension(ctx->var_val()[i]->ref()->BL().size());
                }

                currentScope->define(variable);
            }
        }
    }
}

void assignClassesandfunctions::exitVar_def(Parse::Var_defContext *)
{
    access_modifier = "";
}

void assignClassesandfunctions::enterField_def(Parse::Field_defContext *)
{
    isField = true;
}

void assignClassesandfunctions::exitField_def(Parse::Field_defContext*)
{
    isField = false;
}

void assignClassesandfunctions::enterMethod_def(Parse::Method_defContext *)
{
    is_method = true;
}

void assignClassesandfunctions::exitMethod_def(Parse::Method_defContext *)
{
    is_method = false;
}

void assignClassesandfunctions::enterAccess_modifier(Parse::Access_modifierContext * ctx)
{
    access_modifier = ctx->getText();
}

void assignClassesandfunctions::enterFun_def(Parse::Fun_defContext * ctx)
{
    if(currentScope->getSymbol(ctx->ID()->getText()) != nullptr)
        errors.push_back(Error("Symbol already defined", ctx->ID()->getSymbol()->getLine(), ctx->ID()->getSymbol()->getCharPositionInLine()));
    else
    {
        if(is_method)
        {
            if(access_modifier != "")
            {
                symtab::methodSymbol *method = new symtab::methodSymbol(ctx->ID()->getText(), currentScope, access_modifier);
                if(ctx->def_ret != nullptr)
                {
                    for(int i = 0; i < ctx->def_ret->array_type().size(); i++)
                    {
                        if(ctx->def_ret->array_type()[i]->type()->getText() == "bool" ||
                           ctx->def_ret->array_type()[i]->type()->getText() == "int"  ||
                           ctx->def_ret->array_type()[i]->type()->getText() == "string" ||
                           ctx->def_ret->array_type()[i]->type()->getText() == "float")
                        {
                            symtab::symbol *s = new symtab::symbol(ctx->def_ret->ID()[i]->getText());
                            s->setType(new symtab::type(ctx->def_ret->array_type()[i]->type()->getText(), ctx->def_ret->ID()[i]->getText(), ""));
                            if(ctx->def_ret->array_type()[i]->BL().size() != 0)
                            {
                                s->setIsArray(true);
                                s->setDimension(ctx->def_ret->array_type()[i]->BL().size());
                            }
                            method->AddReturnTypes(s);
                            method->define(s);
                        }

                        else
                        {
                            if(scopess.find(ctx->def_ret->array_type()[i]->type()->getText()) == scopess.end())
                            {
                                errors.push_back(Error("parameter type is undefined", ctx->def_ret->array_type()[i]->type()->getStart()->getLine(), ctx->def_ret->array_type()[i]->type()->getStart()->getCharPositionInLine()));
                                continue;
                            }

                            symtab::symbol *s = new symtab::symbol(ctx->def_ret->ID()[i]->getText());
                            s->setIsDefinedType(true);
                            s->setDefinedType(ctx->def_ret->ID()[i]->getText());
                            method->AddReturnTypes(s);
                            method->define(s);
                        }

                    }
                }

                if(ctx->def_args()->args_var() != nullptr)
                {
                    for(int i = 0; i < ctx->def_args()->args_var()->array_type().size(); i++)
                    {
                        if(ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "bool" ||
                                ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "int"  ||
                                ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "string" ||
                                ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "float")
                        {
                            symtab::symbol *s = new symtab::symbol(ctx->def_args()->args_var()->ID()[i]->getText());
                            s->setType(new symtab::type(ctx->def_args()->args_var()->array_type()[i]->type()->getText(), ctx->args_var()->ID()[i]->getText(), ""));
                            if(ctx->def_args()->args_var()->array_type()[i]->BL().size() != 0)
                            {
                                s->setIsArray(true);
                                s->setDimension(ctx->def_args()->args_var()->array_type()[i]->BL().size());
                            }

                            if(scopess.find(ctx->def_args()->args_var()->ID()[i]->getText()) != scopess.end() || currentScope->resolve<symtab::functionSymbol>(ctx->def_args()->args_var()->ID()[i]->getText()) != nullptr)
                            {
                                errors.push_back(Error("parameter name is such a class or function name", ctx->def_args()->args_var()->ID()[i]->getSymbol()->getLine(), ctx->def_args()->args_var()->ID()[i]->getSymbol()->getCharPositionInLine()));
                                continue;
                            }

                            method->define(s);
                            method->AddArguments(s);
                        }
                        else
                        {
                            if(scopess.find(ctx->def_args()->args_var()->array_type()[i]->type()->getText()) == scopess.end())
                            {
                                errors.push_back(Error("parameter type is undefined", ctx->def_args()->args_var()->array_type()[i]->type()->getStart()->getLine(), ctx->def_args()->args_var()->array_type()[i]->type()->getStart()->getCharPositionInLine()));
                                continue;
                            }

                            if(scopess.find(ctx->def_args()->args_var()->ID()[i]->getText()) != scopess.end() || currentScope->resolve<symtab::functionSymbol>(ctx->def_args()->args_var()->ID()[i]->getText()) != nullptr)
                            {
                                errors.push_back(Error("parameter name is such a class or function name", ctx->def_args()->args_var()->ID()[i]->getSymbol()->getLine(), ctx->def_args()->args_var()->ID()[i]->getSymbol()->getCharPositionInLine()));
                                continue;
                            }

                            symtab::symbol *s = new symtab::symbol(ctx->def_args()->args_var()->ID()[i]->getText());
                            s->setIsDefinedType(true);
                            s->setDefinedType(ctx->args_var()->ID()[i]->getText());
                            method->AddArguments(s);
                            method->define(s);
                        }
                    }
                }
                currentScope->define(method);
                currentScope = method;
                save(ctx, currentScope);
            }

            else
            {
                symtab::methodSymbol *method = new symtab::methodSymbol(ctx->ID()->getText(), currentScope, "private");
                if(ctx->def_ret != nullptr)
                {
                    for(int i = 0; i < ctx->def_ret->array_type().size(); i++)
                    {
                        if(ctx->def_ret->array_type()[i]->type()->getText() == "bool" ||
                           ctx->def_ret->array_type()[i]->type()->getText() == "int"  ||
                           ctx->def_ret->array_type()[i]->type()->getText() == "string" ||
                           ctx->def_ret->array_type()[i]->type()->getText() == "float")
                        {
                            symtab::symbol *s = new symtab::symbol(ctx->def_ret->ID()[i]->getText());
                            s->setType(new symtab::type(ctx->def_ret->array_type()[i]->type()->getText(), ctx->def_ret->ID()[i]->getText(), ""));
                            if(ctx->def_ret->array_type()[i]->BL().size() != 0)
                            {
                                s->setIsArray(true);
                                s->setDimension(ctx->def_ret->array_type()[i]->BL().size());
                            }
                            method->AddReturnTypes(s);
                            method->define(s);
                        }
                        else
                        {
                            if(scopess.find(ctx->def_ret->array_type()[i]->type()->getText()) == scopess.end())
                            {
                                errors.push_back(Error("parameter type is undefined", ctx->def_ret->array_type()[i]->type()->getStart()->getLine(), ctx->def_ret->array_type()[i]->type()->getStart()->getCharPositionInLine()));
                                continue;
                            }

                            symtab::symbol *s = new symtab::symbol(ctx->def_ret->ID()[i]->getText());
                            s->setIsDefinedType(true);
                            s->setDefinedType(ctx->def_ret->ID()[i]->getText());
                            method->AddReturnTypes(s);
                            method->define(s);
                        }

                    }
                }

                if(ctx->def_args()->args_var() != nullptr)
                {
                    for(int i = 0; i < ctx->def_args()->args_var()->array_type().size(); i++)
                    {
                        if(ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "bool" ||
                                ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "int"  ||
                                ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "string" ||
                                ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "float")
                        {
                            symtab::symbol *s = new symtab::symbol(ctx->def_args()->args_var()->ID()[i]->getText());
                            s->setType(new symtab::type(ctx->def_args()->args_var()->array_type()[i]->type()->getText(), ctx->args_var()->ID()[i]->getText(), ""));
                            if(ctx->def_args()->args_var()->array_type()[i]->BL().size() != 0)
                            {
                                s->setIsArray(true);
                                s->setDimension(ctx->def_args()->args_var()->array_type()[i]->BL().size());
                            }

                            if(scopess.find(ctx->def_args()->args_var()->ID()[i]->getText()) != scopess.end() || currentScope->resolve<symtab::functionSymbol>(ctx->def_args()->args_var()->ID()[i]->getText()) != nullptr)
                            {
                                errors.push_back(Error("parameter name is such a class or function name", ctx->def_args()->args_var()->ID()[i]->getSymbol()->getLine(), ctx->def_args()->args_var()->ID()[i]->getSymbol()->getCharPositionInLine()));
                                continue;
                            }

                            method->define(s);
                            method->AddArguments(s);
                        }
                        else
                        {
                            if(scopess.find(ctx->def_args()->args_var()->array_type()[i]->type()->getText()) == scopess.end())
                            {
                                errors.push_back(Error("parameter type is undefined", ctx->def_args()->args_var()->array_type()[i]->type()->getStart()->getLine(), ctx->def_args()->args_var()->array_type()[i]->type()->getStart()->getCharPositionInLine()));
                                continue;
                            }

                            if(scopess.find(ctx->def_args()->args_var()->ID()[i]->getText()) != scopess.end() || currentScope->resolve<symtab::functionSymbol>(ctx->def_args()->args_var()->ID()[i]->getText()) != nullptr)
                            {
                                errors.push_back(Error("parameter name is such a class or function name", ctx->def_args()->args_var()->ID()[i]->getSymbol()->getLine(), ctx->def_args()->args_var()->ID()[i]->getSymbol()->getCharPositionInLine()));
                                continue;
                            }

                            symtab::symbol *s = new symtab::symbol(ctx->def_args()->args_var()->ID()[i]->getText());
                            s->setIsDefinedType(true);
                            s->setDefinedType(ctx->def_args()->args_var()->ID()[i]->getText());
                            method->AddArguments(s);
                            method->define(s);
                        }
                    }
                }

                currentScope->define(method);
                currentScope = method;
                save(ctx, currentScope);
            }
            is_method = false;
            access_modifier = "";
        }
        else
        {
            symtab::functionSymbol *function = new symtab::functionSymbol(ctx->ID()->getText(), currentScope);
            if(ctx->def_ret != nullptr)
            {
                for(int i = 0; i < ctx->def_ret->array_type().size(); i++)
                {
                    if(ctx->def_ret->array_type()[i]->type()->getText() == "bool" ||
                       ctx->def_ret->array_type()[i]->type()->getText() == "int"  ||
                       ctx->def_ret->array_type()[i]->type()->getText() == "string" ||
                       ctx->def_ret->array_type()[i]->type()->getText() == "float")
                    {
                        symtab::symbol *s = new symtab::symbol(ctx->def_ret->ID()[i]->getText());
                        s->setType(new symtab::type(ctx->def_ret->array_type()[i]->type()->getText(), ctx->def_ret->ID()[i]->getText(), ""));
                        if(ctx->def_ret->array_type()[i]->BL().size() != 0)
                        {
                            s->setIsArray(true);
                            s->setDimension(ctx->def_ret->array_type()[i]->BL().size());
                        }
                        function->AddReturnTypes(s);
                        function->define(s);
                    }
                    else
                    {
                        if(scopess.find(ctx->def_ret->array_type()[i]->type()->getText()) == scopess.end())
                        {
                            errors.push_back(Error("parameter type is undefined", ctx->def_ret->array_type()[i]->type()->getStart()->getLine(), ctx->def_ret->array_type()[i]->type()->getStart()->getCharPositionInLine()));
                            continue;
                        }

                        symtab::symbol *s = new symtab::symbol(ctx->def_ret->ID()[i]->getText());
                        s->setIsDefinedType(true);
                        s->setDefinedType(ctx->def_ret->ID()[i]->getText());
                        function->AddReturnTypes(s);
                        function->define(s);
                    }

                }

            }

            if(ctx->def_args()->args_var() != nullptr)
            {
                for(int i = 0; i < ctx->def_args()->args_var()->array_type().size(); i++)
                {
                    if(ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "bool" ||
                            ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "int"  ||
                            ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "string" ||
                            ctx->def_args()->args_var()->array_type()[i]->type()->getText() == "float")
                    {
                        symtab::symbol *s = new symtab::symbol(ctx->def_args()->args_var()->ID()[i]->getText());
                        s->setType(new symtab::type(ctx->def_args()->args_var()->array_type()[i]->type()->getText(), ctx->args_var()->ID()[i]->getText(), ""));
                        if(ctx->def_args()->args_var()->array_type()[i]->BL().size() != 0)
                        {
                            s->setIsArray(true);
                            s->setDimension(ctx->def_args()->args_var()->array_type()[i]->BL().size());
                        }

                        if(scopess.find(ctx->def_args()->args_var()->ID()[i]->getText()) != scopess.end() || currentScope->resolve<symtab::functionSymbol>(ctx->def_args()->args_var()->ID()[i]->getText()) != nullptr)
                        {
                            errors.push_back(Error("parameter name is such a class or function name", ctx->def_args()->args_var()->ID()[i]->getSymbol()->getLine(), ctx->def_args()->args_var()->ID()[i]->getSymbol()->getCharPositionInLine()));
                            continue;
                        }

                        function->define(s);
                        function->AddArguments(s);
                    }
                    else
                    {
                        if(scopess.find(ctx->def_args()->args_var()->array_type()[i]->type()->getText()) == scopess.end())
                        {
                            errors.push_back(Error("parameter type is undefined", ctx->def_args()->args_var()->array_type()[i]->type()->getStart()->getLine(), ctx->def_args()->args_var()->array_type()[i]->type()->getStart()->getCharPositionInLine()));
                            continue;
                        }

                        if(scopess.find(ctx->def_args()->args_var()->ID()[i]->getText()) != scopess.end() || currentScope->resolve<symtab::functionSymbol>(ctx->def_args()->args_var()->ID()[i]->getText()) != nullptr)
                        {
                            errors.push_back(Error("parameter name is such a class or function name", ctx->def_args()->args_var()->ID()[i]->getSymbol()->getLine(), ctx->def_args()->args_var()->ID()[i]->getSymbol()->getCharPositionInLine()));
                            continue;
                        }

                        symtab::symbol *s = new symtab::symbol(ctx->def_args()->args_var()->ID()[i]->getText());
                        s->setIsDefinedType(true);
                        s->setDefinedType(ctx->def_args()->args_var()->ID()[i]->getText());
                        function->AddArguments(s);
                        function->define(s);
                    }
                }
            }

            currentScope->define(function);
            currentScope = function;
            save(ctx, currentScope);
        }
    }
}

void assignClassesandfunctions::exitFun_def(Parse::Fun_defContext *)
{
    currentScope = currentScope->getEnclosing_scope();
}

/*

//void assignClassesandfunctions::enterDef_args(Parse::Def_argsContext * ctx)
//{
//    if(ctx->args_var() != nullptr)
//    {
//        for(int i = 0; i < ctx->args_var()->array_type().size(); i++)
//        {
//            if(ctx->args_var()->array_type()[i]->type()->getText() == "bool" ||
//                    ctx->args_var()->array_type()[i]->type()->getText() == "int"  ||
//                    ctx->args_var()->array_type()[i]->type()->getText() == "string" ||
//                    ctx->args_var()->array_type()[i]->type()->getText() == "float")
//            {
//                symtab::symbol *s = new symtab::symbol(ctx->args_var()->ID()[i]->getText());
//                s->setType(new symtab::type(ctx->args_var()->array_type()[i]->type()->getText(), ctx->args_var()->ID()[i]->getText(), ""));
//                if(ctx->args_var()->array_type()[i]->BL().size() != 0)
//                {
//                    s->setIsArray(true);
//                    s->setDimension(ctx->args_var()->array_type()[i]->BL().size());
//                }

//                if(scopess.find(ctx->args_var()->ID()[i]->getText()) != scopess.end() || currentScope->resolve<symtab::functionSymbol>(ctx->args_var()->ID()[i]->getText()) != nullptr)
//                {
//                    errors.push_back(Error("parameter name is such a class or function name", ctx->args_var()->ID()[i]->getSymbol()->getLine(), ctx->args_var()->ID()[i]->getSymbol()->getCharPositionInLine()));
//                    continue;
//                }

//                currentScope->define(s);
//                dynamic_cast<symtab::functionSymbol*>(currentScope)->AddArguments(s);
//            }
//            else
//            {
//                if(scopess.find(ctx->args_var()->array_type()[i]->type()->getText()) == scopess.end())
//                {
//                    errors.push_back(Error("parameter type is undefined", ctx->args_var()->array_type()[i]->type()->getStart()->getLine(), ctx->args_var()->array_type()[i]->type()->getStart()->getCharPositionInLine()));
//                    continue;
//                }

//                if(scopess.find(ctx->args_var()->ID()[i]->getText()) != scopess.end() || currentScope->resolve<symtab::functionSymbol>(ctx->args_var()->ID()[i]->getText()) != nullptr)
//                {
//                    errors.push_back(Error("parameter name is such a class or function name", ctx->args_var()->ID()[i]->getSymbol()->getLine(), ctx->args_var()->ID()[i]->getSymbol()->getCharPositionInLine()));
//                    continue;
//                }

//                symtab::symbol *s = new symtab::symbol(ctx->args_var()->ID()[i]->getText());
//                s->setIsDefinedType(true);
//                s->setDefinedType(ctx->args_var()->ID()[i]->getText());
//                dynamic_cast<symtab::functionSymbol*>(currentScope)->AddArguments(s);
//                currentScope->define(s);
//            }
//        }
//    }
//}
*/
void assignClassesandfunctions::enterSwitchCond(Parse::SwitchCondContext * ctx)
{
    symtab::baseScope * s = new symtab::baseScope("switch",currentScope);
    currentScope = s;
    save(ctx, currentScope);
    loop++;
}

void assignClassesandfunctions::exitSwitchCond(Parse::SwitchCondContext *)
{
    currentScope = currentScope->getEnclosing_scope();
    loop--;
}

void assignClassesandfunctions::enterIfBlock(Parse::IfBlockContext * ctx)
{
    symtab::baseScope * s = new symtab::baseScope("ifBlock", currentScope);
    currentScope = s;
    save(ctx, currentScope);
}

void assignClassesandfunctions::exitIfBlock(Parse::IfBlockContext *)
{
    currentScope = currentScope->getEnclosing_scope();
}

void assignClassesandfunctions::enterElseBlock(Parse::ElseBlockContext * ctx)
{
    symtab::baseScope * s = new symtab::baseScope("else", currentScope);
    currentScope = s;
    save(ctx, currentScope);
}

void assignClassesandfunctions::exitElseBlock(Parse::ElseBlockContext *)
{
    currentScope = currentScope->getEnclosing_scope();
}

void assignClassesandfunctions::enterForLoop(Parse::ForLoopContext * ctx)
{
    symtab::baseScope * s = new symtab::baseScope("switch",currentScope);
    currentScope = s;
    save(ctx, currentScope);
    loop++;
}

void assignClassesandfunctions::exitForLoop(Parse::ForLoopContext *)
{
    currentScope = currentScope->getEnclosing_scope();
    loop--;
}

void assignClassesandfunctions::enterWhileLoop(Parse::WhileLoopContext * ctx)
{
    symtab::baseScope * s = new symtab::baseScope("switch",currentScope);
    currentScope = s;
    save(ctx, currentScope);
    loop++;
}

void assignClassesandfunctions::exitWhileLoop(Parse::WhileLoopContext *)
{
    currentScope = currentScope->getEnclosing_scope();
    loop--;
}

void assignClassesandfunctions::enterBreaks(Parse::BreaksContext * ctx)
{
    if(loop == 0)
    {
        errors.push_back(Error("break should be in a loop or switch", ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine()));
    }
}

void assignClassesandfunctions::enterContinues(Parse::ContinuesContext * ctx)
{
    if(loop == 0)
    {
        errors.push_back(Error("break should be in a loop or switch", ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine()));
    }
}

void assignClassesandfunctions::save(antlr4::ParserRuleContext *ctx, symtab::scope *scope)
{
    scopes.put(ctx, scope);
}

std::vector<Error> assignClassesandfunctions::getErrors() const
{
    return errors;
}

std::unordered_map<std::string, symtab::scope *> assignClassesandfunctions::getScopess() const
{
    return scopess;
}

antlr4::tree::ParseTreeProperty<symtab::scope *> assignClassesandfunctions::getScopes() const
{
    return scopes;
}



