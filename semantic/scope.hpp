#pragma once

#include <string>
#include <list>
#include <set>
#include "symbol.hpp"
#include <map>
#include <utility>


namespace symtab
{
    class scope
    {
    public:
        scope(scope *s): enclosing_scope(s) {}
        scope(){}
        virtual std::string getName(void) = 0;
        void define(symbol *sym);
        template<typename T>
        T *resolve(std::string name)
        {
            symbol *sym = symbols[name];
            if(sym != nullptr)
                if(dynamic_cast<T*>(sym) != nullptr)
                    return dynamic_cast<T*>(sym);
            if(getEnclosing_scope() != nullptr)
            {
                auto f = getEnclosing_scope();
                return f->resolve<T>(name);
            }
            return nullptr;
        }
        symbol *getSymbol(std::string name) const;
        int getNumberOfSymbols();
        virtual ~scope() = default;
        scope *getEnclosing_scope() const;
        void setEnclosing_scope(scope *value);

        std::unordered_map<std::string, symbol *> getSymbols() const;

        std::string getObjectName() const;
        void setObjectName(const std::string &value);

    protected:
        scope *enclosing_scope = nullptr;
        std::unordered_map<std::string, symbol *> symbols;
        std::string objectName;
    };
}
