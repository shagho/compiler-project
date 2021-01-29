#include "symbol.hpp"

symtab::symbol::symbol(std::string name)
{
    this->name = name;
}

bool symtab::symbol::operator ==(const symtab::symbol *symbol) const
{
    if (this == symbol)
        return true;
    if(this->name == symbol->name)
        return true;
    return false;
}


std::string symtab::symbol::getName() const
{
    return name;
}

antlr4::ParserRuleContext *symtab::symbol::getDef_Node() const
{
    return def_Node;
}

void symtab::symbol::setDef_Node(antlr4::ParserRuleContext *value)
{
    def_Node = value;
}

bool symtab::symbol::getConst_flag() const
{
    return const_flag;
}

void symtab::symbol::setConst_flag(bool value)
{
    const_flag = value;
}

bool symtab::symbol::is_convertible(symtab::symbol *s)
{
    if(dimension != 0)
        return false;
    if(this->getDefinedType() != s->getDefinedType())
        return false;

    if(this->getDefinedType() == "" && s->getDefinedType() == "")
    {
        if(Type == nullptr || s->Type == nullptr)
            return false;
        if(Type->getTypeString() == "int")
        {
            if(s->Type->getTypeString() == "int")
                return true;
            else if(s->Type->getTypeString() == "float")
                return true;
            else if(s->Type->getTypeString() == "bool")
                return true;
            else if(s->Type->getTypeString() == "string")
                return true;
            else return false;
        }

        if(Type->getTypeString() == "float")
        {
            if(s->Type->getTypeString() == "float")
                return true;
            else return false;
        }

        if(Type->getTypeString() == "bool")
        {
            if(s->Type->getTypeString() == "int")
                return true;
            else if(s->Type->getTypeString() == "bool")
                return true;
            else return false;
        }
        if(Type->getTypeString() == "string")
        {
            if(s->Type->getTypeString() == "string")
                return true;
            else return false;
        }
    }
    if(this->getDefinedType() == s->getDefinedType())
        return true;

    return false;
}

bool symtab::symbol::getIsDefinedType() const
{
    return isDefinedType;
}

void symtab::symbol::setIsDefinedType(bool value)
{
    isDefinedType = value;
}

std::string symtab::symbol::getDefinedType() const
{
    return DefinedType;
}

void symtab::symbol::setDefinedType(const std::string &value)
{
    DefinedType = value;
}

int symtab::symbol::getDimension() const
{
    return dimension;
}

void symtab::symbol::setDimension(int value)
{
    dimension = value;
}

bool symtab::symbol::getIsArray() const
{
    return isArray;
}

void symtab::symbol::setIsArray(bool value)
{
    isArray = value;
}

symtab::type *symtab::symbol::getType() const
{
    return Type;
}

void symtab::symbol::setType(symtab::type *value)
{
    Type = value;
}

bool symtab::symbol::getIsNull() const
{
    return isNull;
}

void symtab::symbol::setIsNull(bool value)
{
    isNull = value;
}

void symtab::symbol::setName(const std::string &value)
{
    name = value;
}
