#include "value.hpp"

Value::Value(std::string content, VarType type)
{
    this->content = content;
    this->type = type;
}
