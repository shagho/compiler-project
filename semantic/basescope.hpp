#ifndef BASESCOPE_HPP
#define BASESCOPE_HPP

#include "scope.hpp"
#include "symbol.hpp"
#include <map>
#include <set>
#include <list>
#include <vector>

namespace symtab
{
class baseScope: public scope
{
public:
    baseScope() {}
    baseScope(std::string Name, symtab::scope * enclosing_Scope):scope(enclosing_Scope)
    {
        this->name = Name;
    }
    baseScope(std::string name):name(name){}

    std::string getName() override
    {
        return this->name;
    }
    ~baseScope() = default;
private:
    std::string name;

};

}


#endif // BASESCOPE_HPP
