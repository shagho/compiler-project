#ifndef FUNCTION_SYMBOL_HPP
#define FUNCTION_SYMBOL_HPP

#include "scope.hpp"

namespace symtab
{
    class functionSymbol: public symbol, public scope
    {
    public:
        functionSymbol(std::string name, scope *s);
        std::string getName() override;
        functionSymbol(std::string name);

        ~functionSymbol() override{}
        std::vector<symtab::symbol *> getReturn_types() const;
        void setReturn_types(const std::vector<symtab::symbol *> &value);
        void AddReturnTypes(symtab::symbol* s);
        std::vector<symtab::symbol *> getArguments() const;
        void setArguments(const std::vector<symtab::symbol *> &value);
        void AddArguments(symbol *s);

    protected:
        std::vector<symtab::symbol *> return_types;
        std::vector<symtab::symbol *> arguments;
    };


}


#endif // FUNCTION_SYMBOL_HPP
