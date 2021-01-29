#include "method_symbol.hpp"

symtab::methodSymbol::methodSymbol(std::string name, symtab::scope *s, std::string access): functionSymbol(name, s) { this -> accessPoint = acc.at(access);setObjectName("method");}

symtab::access symtab::methodSymbol::getAccessPoint() const
{
    return accessPoint;
}

void symtab::methodSymbol::setAccessPoint(const symtab::access &value)
{
    accessPoint = value;
}

std::string symtab::methodSymbol::getAccessPointString()
{
    return acc_inverse.at(accessPoint);
}
