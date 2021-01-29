#include "classsymbol.hpp"

symtab::class_symbol::class_symbol(std::string name): baseScope(name), symbol (name){setObjectName("class_symbol");}

antlr4::ParserRuleContext *symtab::class_symbol::getDefNode() const
{
    return defNode;
}

void symtab::class_symbol::setDefNode(antlr4::ParserRuleContext *value)
{
    defNode = value;
}

std::string symtab::class_symbol::getSuperClassName() const
{
    return superClassName;
}

void symtab::class_symbol::setSuperClassName(const std::string &value)
{
    superClassName = value;
}

symtab::class_symbol *symtab::class_symbol::getSuperClassScope()
{
    return SuperClassScope;
}

void *symtab::class_symbol::setSuperClassScope(symtab::class_symbol *super)
{
    SuperClassScope = super;
}

std::string symtab::class_symbol::getAccess_modifier() const
{
    return access_modifier;
}

void symtab::class_symbol::setAccess_modifier(const std::string &value)
{
    access_modifier = value;
}
