#ifndef TYPEDSYMBOL_HPP
#define TYPEDSYMBOL_HPP

#include "type.hpp"

namespace symtab
{
    class typedSymbol
    {
        virtual symtab::type getType() = 0;
        virtual void setType(symtab::type type) = 0;
        virtual ~typedSymbol();
    };
}

#endif // TYPEDSYMBOL_HPP
