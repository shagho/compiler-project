#include "field_symbol.hpp"

symtab::access symtab::fieldSymbol::getAccess_point() const
{
    return access_point;
}

void symtab::fieldSymbol::setAccess_point(const symtab::access &value)
{
    access_point = value;
}

std::string symtab::fieldSymbol::getAccessPointString()
{
    return acc_inverse.at(getAccess_point());
}
