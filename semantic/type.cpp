#include "type.hpp"

symtab::type::type(std::string type, std::string name, std::string const_value)
{
    this->Name = name;
    this->Type = type_map.find(type)->second;
    if(type_map.find(type) != type_map.end())
    {
        if(type_map.at(type) == 0)
            size = 2*int(const_value.size())+1;
        else
            size = type_map.at(type) == 0;
    }
}

std::string symtab::type::getName() const
{
    return Name;
}

void symtab::type::setName(const std::string &value)
{
    Name = value;
}

symtab::types symtab::type::getType() const
{
    return Type;
}

void symtab::type::setType(const symtab::types &value)
{
    Type = value;
}

int symtab::type::getSize() const
{
    return size;
}

void symtab::type::setSize(int value)
{
    size = value;
}

std::string symtab::type::getConst_value() const
{
    return const_value;
}

void symtab::type::setConst_value(const std::string &value)
{
    const_value = value;
}

std::string symtab::type::getTypeString() const
{
    return type_map_1.at(Type);
}
