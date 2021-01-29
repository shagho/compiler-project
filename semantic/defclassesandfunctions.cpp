#include "defclassesandfunctions.hpp"

defClassesandfunctions::defClassesandfunctions()
{

}

void defClassesandfunctions::enterType_def(Parse::Type_defContext * ctx)
{
    if(scopes.find(ctx->ID()[0]->getText()) != scopes.end())
    {
        errors.push_back(Error("duplicate symbol: ", ctx->ID()[0]->getSymbol()->getLine(), ctx->ID()[0]->getSymbol()->getCharPositionInLine()));
        return;
    }

    symtab::class_symbol *clas = new symtab::class_symbol(ctx->ID()[0]->getText());
    scopes[ctx->ID()[0]->getText()] = clas;
}

void defClassesandfunctions::enterStart_func(Parse::Start_funcContext *)
{
    symtab::functionSymbol * func = new symtab::functionSymbol("start");
    scopes["start"] = func;
}

void defClassesandfunctions::enterFun_def(Parse::Fun_defContext * ctx)
{
    if(!isMethod)
    {
        if(scopes.find(ctx->ID()->getText()) != scopes.end())
        {
            if(dynamic_cast<symtab::class_symbol*>(scopes.at(ctx->ID()->getText())) != nullptr)
                errors.push_back(Error("duplicate symbol: ", ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine()));
            return;
        }
        symtab::functionSymbol * func = new symtab::functionSymbol(ctx->ID()->getText());
        scopes[ctx->ID()->getText()] = func;
    }
}

void defClassesandfunctions::enterMethod_def(Parse::Method_defContext *)
{
    isMethod = true;
}

void defClassesandfunctions::exitMethod_def(Parse::Method_defContext *)
{
    isMethod = false;
}



std::vector<Error> defClassesandfunctions::getErrors() const
{
    return errors;
}

std::unordered_map<std::string, symtab::scope *> defClassesandfunctions::getScopes() const
{
    return scopes;
}
