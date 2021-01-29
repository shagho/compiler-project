#pragma once

#include <string>
#include <type.hpp>
#include <ParserRuleContext.h>


namespace  symtab
{

class symbol
{
public:
    symbol();
    symbol(std::string name);
    bool operator == (const symbol *symbol) const;
    std::string getName() const;
    void setName(const std::string &value);
    antlr4::ParserRuleContext *getDef_Node() const;
    void setDef_Node(antlr4::ParserRuleContext *value);
    virtual ~symbol(){}


    bool getConst_flag() const;
    void setConst_flag(bool value);
    bool is_convertible(symbol *s);

    bool getIsDefinedType() const;
    void setIsDefinedType(bool value);

    std::string getDefinedType() const;
    void setDefinedType(const std::string &value);

    int getDimension() const;
    void setDimension(int value);

    bool getIsArray() const;
    void setIsArray(bool value);

    type *getType() const;
    void setType(type *value);

    bool getIsNull() const;
    void setIsNull(bool value);

private:
    std::string name;
    type *Type = nullptr;
    bool const_flag = false;
    bool isArray = false;
    int dimension = 0;
    antlr4::ParserRuleContext *def_Node;
    bool isDefinedType = false;
    std::string DefinedType = "";
    bool isNull = false;

};

}

