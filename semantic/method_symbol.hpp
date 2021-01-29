#pragma once

#include "function_symbol.hpp"
#include "field_symbol.hpp"

namespace symtab
{
class methodSymbol: public functionSymbol
{
public:
    methodSymbol(std::string name, scope *s, std::string access);
    ~methodSymbol() {}
    access getAccessPoint() const;
    void setAccessPoint(const access &value);
    std::string getAccessPointString();

private:
    access accessPoint;
};
}


