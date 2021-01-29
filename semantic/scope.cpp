#include "scope.hpp"

void symtab::scope::define(symtab::symbol *sym)
{
    symbols.insert(std::pair<std::string, symbol*>(sym->getName(), sym));
}

symtab::symbol *symtab::scope::getSymbol(std::string name) const
{
    if(symbols.find(name) != symbols.end())
        return symbols.at(name);
    return nullptr;
}


int symtab::scope::getNumberOfSymbols()
{
    return int(symbols.size());
}

symtab::scope *symtab::scope::getEnclosing_scope() const
{
    return enclosing_scope;
}

void symtab::scope::setEnclosing_scope(symtab::scope *value)
{
    enclosing_scope = value;
}

std::unordered_map<std::string, symtab::symbol *> symtab::scope::getSymbols() const
{
    return symbols;
}

std::string symtab::scope::getObjectName() const
{
    return objectName;
}

void symtab::scope::setObjectName(const std::string &value)
{
    objectName = value;
}
