#include "function_symbol.hpp"

symtab::functionSymbol::functionSymbol(std::string name, symtab::scope *s): symbol(name), scope(s){setObjectName("functionSymbol");}

std::string symtab::functionSymbol::getName()
{
    return symbol::getName();
}

symtab::functionSymbol::functionSymbol(std::string name):symbol(name), scope(nullptr){setObjectName("functionSymbol");}

std::vector<symtab::symbol *> symtab::functionSymbol::getReturn_types() const
{
    return return_types;
}

void symtab::functionSymbol::setReturn_types(const std::vector<symtab::symbol *> &value)
{
    return_types = value;
}

void symtab::functionSymbol::AddReturnTypes(symtab::symbol *s)
{
    return_types.push_back(s);
}

std::vector<symtab::symbol *> symtab::functionSymbol::getArguments() const
{
    return arguments;
}

void symtab::functionSymbol::setArguments(const std::vector<symtab::symbol *> &value)
{
    arguments = value;
}

void symtab::functionSymbol::AddArguments(symtab::symbol *s)
{
    arguments.push_back(s);
}
