#ifndef PARAMETER_SYMBOL_HPP
#define PARAMETER_SYMBOL_HPP

#include "symbol.hpp"

namespace symtab
{
    class parameterSymbol:public symbol
    {
    public:
        parameterSymbol(std::string name) :symbol(name){}
        ~parameterSymbol();
    };
}

#endif // PARAMETER_SYMBOL_HPP
