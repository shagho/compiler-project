#pragma once

#include <ParserRuleContext.h>
#include "scope.hpp"
#include "basescope.hpp"
#include "method_symbol.hpp"

namespace symtab
{
    class class_symbol: public baseScope, public symbol
    {
    public:
        class_symbol(std::string name);
        ~class_symbol() {}
        antlr4::ParserRuleContext *getDefNode() const;
        void setDefNode(antlr4::ParserRuleContext *value);

        std::string getSuperClassName() const;
        void setSuperClassName(const std::string &value);
        class_symbol *getSuperClassScope();
        void *setSuperClassScope(class_symbol* super);

        template<typename T>
        T *resolveForClassMembers(std::string name)
        {
            symbol *s = getSymbol(name);
            if(s == nullptr)
                return nullptr;
            if(dynamic_cast<T*>(s) != nullptr)
                return dynamic_cast<T*>(s);
            return nullptr;
        }

        std::string getAccess_modifier() const;
        void setAccess_modifier(const std::string &value);

    private:
        antlr4::ParserRuleContext *defNode;
        std::string superClassName = "";
        class_symbol* SuperClassScope = nullptr;
        std::string access_modifier = "";
    };



}
