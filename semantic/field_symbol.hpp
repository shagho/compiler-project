#ifndef FIELD_SYMBOL_HPP
#define FIELD_SYMBOL_HPP

#include "symbol.hpp"

namespace symtab
{
    enum access
    {
        a_public,
        a_private,
        a_protected
    };

    const std::unordered_map<std::string, access> acc =
    {
        {"public", access::a_public},
        {"private", access::a_private},
        {"protected", access::a_protected}
    };

    const std::unordered_map<access, std::string> acc_inverse =
    {
        {access::a_public, "public"},
        {access::a_private, "private"},
        {access::a_protected, "protected"}
    };

    class fieldSymbol:public symbol
    {
    public:
        fieldSymbol(std::string name, std::string access): symbol(name){ this ->access_point = acc.at(access);}
        ~fieldSymbol() = default;
        access getAccess_point() const;
        void setAccess_point(const access &value);
        std::string getAccessPointString();

    private:
        access access_point;
    };
}



#endif // FIELD_SYMBOL_HPP
