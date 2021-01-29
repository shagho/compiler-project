#ifndef VALUE_HPP
#define VALUE_HPP

#include <string>

enum VarType
{
    STRING,
    INT,
    FLOAT
};

class Value
{
public:
    Value(std::string content, VarType type);
    std::string content;
    VarType type;

};

#endif // VALUE_HPP
