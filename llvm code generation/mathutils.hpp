#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

#include "value.hpp"
#include "codegeneratorutils.hpp"
#include <queue>
#include <unordered_map>

namespace mathUtils
{
Value eval(std::string type, std::queue <std::string> infix, std::unordered_set<std::string> globalNames,
           std::unordered_map<std::string, Value> variables, codeGeneratorUtils & code);

bool AllValuesAreInt(std::queue<std::string> values, std::unordered_map<std::string, Value> variables);

void handleVariable(std::string item, std::stack<std::string> &Stack,
                    std::unordered_map<std::string, Value> variables,
                    std::unordered_set<std::string> globalNames, codeGeneratorUtils & code);

std::queue<std::string> intTodouble(std::queue<std::string> ints);

bool isInt(std::string s);

bool isNumeric(const std::string &str);

std::queue <std::string> infixToRpn(std::queue<std::string> infix);

int prec(std::string c);


}


#endif // MATHUTILS_HPP
