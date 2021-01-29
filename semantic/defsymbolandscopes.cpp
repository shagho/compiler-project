#include "defsymbolandscopes.hpp"
#include <regex>

defSymbolandScopes::defSymbolandScopes()
{

}

void defSymbolandScopes::enterProgram(Parse::ProgramContext *)
{
    currentScope = &global;
}

void defSymbolandScopes::exitProgram(Parse::ProgramContext *)
{
    currentScope = currentScope->getEnclosing_scope();
}

void defSymbolandScopes::enterType_def(Parse::Type_defContext *ctx)
{
    if(!currentScope->resolve<symtab::symbol>(ctx->ID()[0]->getText()))
    {
        symtab::class_symbol *clas = new symtab::class_symbol(ctx->ID()[0]->getText());
        clas->setEnclosing_scope(currentScope);
        if(!ctx->superType->getText().empty())
        {
            if(currentScope->resolve<symtab::symbol>(ctx->superType->getText()))
            {
                clas->setSuperClassName(ctx->superType->getText());
            }
            else
            {
                std::cout << "semantic issue:in line " <<ctx->superType->getLine()
                          << "and column " <<ctx->superType->getCharPositionInLine()
                          << " : undeclared class" << std::endl;
            }

        }
        currentScope->define(clas);
        save(ctx, clas);
        currentScope = clas;
    }
    else
    {
        std::cout << "semantic issue:in line " <<ctx->ID()[0]->getSymbol()->getLine()
                  << "and column " <<ctx->ID()[0]->getSymbol()->getCharPositionInLine()
                  << " : it's defined before" << std::endl;
    }

}

void defSymbolandScopes::exitType_def(Parse::Type_defContext *)
{
    currentScope = currentScope->getEnclosing_scope();
}


void defSymbolandScopes::enterField_def(Parse::Field_defContext * ctx)
{
    auto variable = ctx->var_def();
    for(int i = 0; i < variable->var_val().size(); i++)
    {
        if (dynamic_cast<symtab::class_symbol*>(currentScope)->resolveForClassMembers<symtab::methodSymbol>(variable->var_val()[i]->ref()->ID()->getText()) != nullptr)
        {
            errors.push_back(Error("it's defined before as method", variable->var_val()[i]->ref()->ID()->getSymbol()->getLine(), variable->var_val()[i]->ref()->ID()->getSymbol()->getCharPositionInLine()));
        }
        else if(dynamic_cast<symtab::class_symbol*>(currentScope)->resolveForClassMembers<symtab::fieldSymbol>(variable->var_val()[i]->ref()->ID()->getText()) == nullptr)
        {
            if(!variable->CONST()->getText().empty() && variable->var_val()[i]->ASM()->getText().empty())
            {
                errors.push_back(Error("they have const value but didn't initialize", variable->var_val()[i]->ref()->ID()->getSymbol()->getLine(), variable->var_val()[i]->ref()->ID()->getSymbol()->getCharPositionInLine()));
            }
            if(ctx)
            {
                symtab::fieldSymbol *field =new symtab::fieldSymbol(variable->var_val()[i]->ref()->ID()->getText(), accessModifer);
                field->setType(new symtab::type(variable->type()->getText(), variable->var_val()[i]->ref()->ID()->getText(), "foo"));
                if(!variable->CONST()->getText().empty())
                {
                    field->setConst_flag(true);
                }
                currentScope->define(field);
            }
            else
            {
                symtab::fieldSymbol *field =new symtab::fieldSymbol(variable->var_val()[i]->ref()->ID()->getText(), "private");
                field->setType(new symtab::type(variable->type()->getText(), variable->var_val()[i]->ref()->ID()->getText(), "foo"));
                if(!variable->CONST()->getText().empty())
                {
                    field->setConst_flag(true);
                }
                currentScope->define(field);
            }
        }
        else
        {
            errors.push_back(Error("it's defined before", variable->var_val()[i]->ref()->ID()->getSymbol()->getLine(), variable->var_val()[i]->ref()->ID()->getSymbol()->getCharPositionInLine()));
        }
    }
}


antlrcpp::Any defSymbolandScopes::visitRef(Parse::RefContext *ctx)
{

}

antlrcpp::Any defSymbolandScopes::visitRelational2Op(Parse::Relational2OpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol s = visit(ctx->expr()[0]);
        symtab::symbol p = visit(ctx->expr()[1]);
        if(s == nullptr || p == nullptr)
            return nullptr;
        symtab::symbol BOOL("foo");
        BOOL.setType(new symtab::type("bool", "foo", "foo"));
        if(s.is_convertible(&p) || p.is_convertible(&s))
            return BOOL;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + " isn't convertible to " + ctx->expr()[1]->getText() + "and vice versa", ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    return nullptr;
}

antlrcpp::Any defSymbolandScopes::visitNull(Parse::NullContext *ctx)
{
    symtab::symbol s("foo");
    s.setType(new symtab::type("nil", "foo", "nil"));
    return s;
}

antlrcpp::Any defSymbolandScopes::visitUnaryOp(Parse::UnaryOpContext *ctx)
{
    symtab::symbol expr = visit(ctx->expr());
    if(expr == nullptr)
        return nullptr;
    if(ctx->unary_op()->UNARY_OP()->getText() == "~")
    {
        symtab::symbol s("foo");
        symtab::type Type("int", "foo", "foo");
        s.setType(&Type);
        if(expr.is_convertible(&s))
            return s;
        else
            errors.push_back(Error("Expression" + ctx->expr()->getText() + "is not convertible to int", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
    }

    if(ctx->unary_op()->getText() == "!")
    {
        symtab::symbol s("foo");
        symtab::type Type("bool", "foo", "foo");
        s.setType(&Type);
        if(expr.is_convertible(&s))
            return s;
        else
            errors.push_back(Error("Expression" + ctx->expr()->getText() + "is not convertible to bool", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
    }

    if(ctx->unary_op()->getText() == "-")
    {
        symtab::symbol s("foo");
        symtab::type Type("float", "foo", "foo");
        s.setType(&Type);
        if(expr.is_convertible(&s))
            return s;
        else
            errors.push_back(Error("Expression" + ctx->expr()->getText() + "is not convertible to float", ctx->expr()->getStart()->getLine(), ctx->expr()->getStart()->getCharPositionInLine()));
    }

    return nullptr;
}

antlrcpp::Any defSymbolandScopes::visitRelational13Op(Parse::Relational13OpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol s = visit(ctx->expr()[0]);
        symtab::symbol p = visit(ctx->expr()[1]);
        if(s == nullptr || p == nullptr)
            return nullptr;
        symtab::symbol BOOL("foo");
        BOOL.setType(new symtab::type("bool", "foo", "foo"));
        if(s.is_convertible(&p) || p.is_convertible(&s))
            return BOOL;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + " isn't convertible to " + ctx->expr()[1]->getText() + "and vice versa", ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    return nullptr;
}

antlrcpp::Any defSymbolandScopes::visitLogicalOp(Parse::LogicalOpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol s = visit(ctx->expr()[0]);
        symtab::symbol p = visit(ctx->expr()[1]);
        if(s == nullptr || p == nullptr)
            return nullptr;
        symtab::symbol BOOL("foo");
        BOOL.setType(new symtab::type("bool", "foo", "foo"));
        if(s.is_convertible(&BOOL) && p.is_convertible(&BOOL))
            return BOOL;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + " and " + ctx->expr()[1]->getText() + " are not convertible to bool", ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    return nullptr;
}

//antlrcpp::Any defSymbolandScopes::visitAllocateOp(Parse::AllocateOpContext *ctx)
//{
//    symtab::symbol *s = currentScope->resolve<symtab::class_symbol>(ctx->handle_call()->ID()->getText());
//    if(s == nullptr)
//    {
//        errors.push_back(Error("undefined variable: ", ctx->handle_call()->ID()->getSymbol()->getLine(), ctx->handle_call()->ID()->getSymbol()->getCharPositionInLine()));
//        return nullptr;
//    }

//    if(dynamic_cast<symtab::class_symbol*>(s)->resolveForClassMembers<symtab::methodSymbol>(s->getName()) == nullptr)
//    {
//        if(!ctx->handle_call()->params()->isEmpty())
//        {
//            errors.push_back(Error("this class dosen't constructor with these arguments:", ctx->handle_call()->params()->getStart()->getLine(), ctx->handle_call()->params()->getStart()->getCharPositionInLine()));
//            return nullptr;
//        }

//    }

//    if(dynamic_cast<symtab::class_symbol*>(s)->resolveForClassMembers<symtab::methodSymbol>(s->getName()) != nullptr)
//    {
//        if(!ctx->handle_call()->params()->isEmpty())
//        {
//            auto param = ctx->handle_call()->params();
//            while(param != nullptr)
//            {
//                symbol
//            }
//        }
//    }
//    return s;
//}

antlrcpp::Any defSymbolandScopes::visitParenthesisOp(Parse::ParenthesisOpContext *ctx)
{
    return visit(ctx->expr());
}

antlrcpp::Any defSymbolandScopes::visitBitwiseOp(Parse::BitwiseOpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol s = visit(ctx->expr()[0]);
        symtab::symbol p = visit(ctx->expr()[1]);
        if(s == nullptr || p == nullptr)
            return nullptr;
        symtab::symbol INT("foo");
        INT.setType(new symtab::type("int", "foo", "foo"));
        if(s.is_convertible(&INT) && p.is_convertible(&INT))
            return INT;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + " and " + ctx->expr()[1]->getText() + " are not convertible to int", ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    return nullptr;
}

antlrcpp::Any defSymbolandScopes::visitArithmetic2Op(Parse::Arithmetic2OpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol s = visit(ctx->expr()[0]);
        symtab::symbol p = visit(ctx->expr()[1]);
        if(s == nullptr || p == nullptr)
            return nullptr;
        if(s.is_convertible(&p))
            return p;
        else if (p.is_convertible(&s))
            return s;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + "is not convertible to " + ctx->expr()[1]->getText(), ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    return nullptr;
}

antlrcpp::Any defSymbolandScopes::visitArithmetic1Op(Parse::Arithmetic1OpContext *ctx)
{
    if(ctx != nullptr)
    {
        symtab::symbol s = visit(ctx->expr()[0]);
        symtab::symbol p = visit(ctx->expr()[1]);
        if(s == nullptr || p == nullptr)
            return nullptr;
        if(s.is_convertible(&p))
            return p;
        else if (p.is_convertible(&s))
            return s;
        else
            errors.push_back(Error("Expression " + ctx->expr()[0]->getText() + "is not convertible to " + ctx->expr()[1]->getText(), ctx->expr()[0]->getStart()->getLine(), ctx->expr()[0]->getStart()->getCharPositionInLine()));
    }
    return nullptr;
}

antlrcpp::Any defSymbolandScopes::visitReadFunc(Parse::ReadFuncContext* /*ctx*/)
{
    symtab::symbol s("foo");
    s.setType(new symtab::type("string", "read", "foo"));
    return s;
}

antlrcpp::Any defSymbolandScopes::visitConstValOp(Parse::ConstValOpContext *ctx)
{
    if(ctx != nullptr)
    {
        if(ctx->const_val()->BOOL_CONST() != nullptr)
        {
            symtab::symbol s("foo");
            s.setType(new symtab::type("bool", "foo", ctx->const_val()->getText()));
            return s;
        }

        if(ctx->const_val()->INT_CONST() != nullptr)
        {
            symtab::symbol s("foo");
            s.setType(new symtab::type("int", "foo", ctx->const_val()->getText()));
            return s;
        }

        if(ctx->const_val()->REAL_CONST() != nullptr)
        {
            symtab::symbol s("foo");
            s.setType(new symtab::type("float", "foo", ctx->const_val()->getText()));
            return s;
        }

        if(ctx->const_val()->STRING_CONST() != nullptr)
        {
            symtab::symbol s("foo");
            s.setType(new symtab::type("string", "foo", ctx->const_val()->getText()));
            return s;
        }
    }
    return nullptr;
}



void defSymbolandScopes::save(antlr4::ParserRuleContext *ctx, symtab::scope *scope)
{
    scopes.put(ctx, scope);
}

std::vector<Error> defSymbolandScopes::getErrors() const
{
    return errors;
}


