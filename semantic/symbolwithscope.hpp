#ifndef SYMBOLWITHSCOPE_HPP
#define SYMBOLWITHSCOPE_HPP

#include "basescope.hpp"

namespace symtab
{
    class symbol_with_scope: public baseScope
    {
    public:
        symbol_with_scope(std::string name): baseScope(name){}
        virtual ~symbol_with_scope();
        std::string getSuperClassName() const;
        void setSuperClassName(const std::string &value);


    private:
        std::string superClassName;
    };

    std::string symbol_with_scope::getSuperClassName() const
    {
        return superClassName;
    }

    void symbol_with_scope::setSuperClassName(const std::string &value)
    {
        superClassName = value;
    }

}






#endif // SYMBOLWITHSCOPE_HPP
