#include "mathutils.hpp"




Value mathUtils::eval(std::string type,std::queue<std::string> infix, std::unordered_set<std::string> globalNames, std::unordered_map<std::string, Value> variables, codeGeneratorUtils &code)
{
    std::queue<std::string> rpn = infixToRpn(intTodouble(infix));
    std::stack<std::string> Stack;
    while (not rpn.empty())
    {
        std::string item = rpn.front();
        rpn.pop();
        if(item == "+")
        {
            std::string tmp1 = Stack.top();Stack.pop();
            std::string tmp2 = Stack.top();Stack.pop();
            code.add_double(tmp1, tmp2);
            Stack.push("%" + std::to_string(code.reg - 1));
        }

        else if (item == "-")
        {
            std::string tmp1 = Stack.top();Stack.pop();
            std::string tmp2 = Stack.top();Stack.pop();
            code.sub_double(tmp2, tmp1);
            Stack.push("%" + std::to_string(code.reg - 1));
        }

        else if (item == "*")
        {
            std::string tmp1 = Stack.top();Stack.pop();
            std::string tmp2 = Stack.top();Stack.pop();
            code.mul_double(tmp1, tmp2);
            Stack.push("%" + std::to_string(code.reg - 1));
        }

        else if (item == "/")
        {
            std::string tmp1 = Stack.top();Stack.pop();
            std::string tmp2 = Stack.top();Stack.pop();
            code.dive_double(tmp2, tmp1);
            Stack.push("%" + std::to_string(code.reg - 1));
        }

        else
        {
            if(isNumeric(item))
                Stack.push(item);
            else
                handleVariable(item,Stack, variables, globalNames, code);
        }
    }
    rpn = infixToRpn(infix);

    if(type == "int")
    {
        code.fptosi(Stack.top());Stack.pop();
        return Value("%" + std::to_string(code.reg - 1), VarType::INT);
    }

    if(type == "float")
        return Value("%" + std::to_string(code.reg - 1), VarType::FLOAT);

    if(AllValuesAreInt(rpn, variables))
    {
        code.fptosi(Stack.top());Stack.pop();
        return Value("%" + std::to_string(code.reg - 1), VarType::INT);
    }

    return Value("%" + std::to_string(code.reg - 1), VarType::FLOAT);
}

bool mathUtils::isNumeric(const std::string &str)
{
    try
    {
        std::stod(str);
    }
    catch (...)
    {
        return false;
    }
    return true;
}

std::queue<std::string> mathUtils::infixToRpn(std::queue<std::string> infix)
{
    std::stack<std::string> Stack;
    std::queue<std::string> rpn;

    std::queue<std::string> e = infix;

    while(!e.empty())
    {
        std::string item = e.front();
        e.pop();
        if(item == "+" || item == "-" || item == "*" || item == "/")
        {
            while(!Stack.empty() and prec(item) <= prec(Stack.top()))
            {
                rpn.push(Stack.top());
                Stack.pop();
            }
            Stack.push(item);
        }

        else if (item == "(")
        {
            Stack.push(item);
        }

        else if(item == ")")
        {
            while(!Stack.empty() and Stack.top() != "(")
            {
                rpn.push(Stack.top());
                Stack.pop();
            }
            Stack.pop();
        }

        else
        {
            rpn.push(item);
        }

    }

    while (!Stack.empty())
    {
        rpn.push(Stack.top());
        Stack.pop();
    }
    return rpn;

}

bool mathUtils::isInt(std::string s)
{
    try
    {
        std::stoi(s);
    }
    catch (...)
    {
        return false;
    }
    return true;
}

std::queue<std::string> mathUtils::intTodouble(std::queue<std::string> ints)
{
    std::queue<std::string> doubles;
    std::queue<std::string> in = ints;
    while(!in.empty())
    {
        std::string item = in.front();
        in.pop();
        if(isInt(item) && item.find(".") != 1)
            doubles.push(std::to_string(double(std::stoi(item))));
        else
            doubles.push(item);
    }
    return doubles;
}

void mathUtils::handleVariable(std::string item, std::stack<std::string> &Stack, std::unordered_map<std::string, Value> variables, std::unordered_set<std::string> globalNames, codeGeneratorUtils &code)
{
    if(variables.find(item) != variables.end())
    {
        Value value = variables.at(item);
        if(value.type == VarType::INT)
        {
            code.load_i32(item, globalNames);
            code.sitofp("%" + std::to_string(code.reg - 1));
        }
        else
            code.load_double(item, globalNames);
        Stack.push("%" + std::to_string(code.reg - 1));
    }
    else
    {
        throw("unknown variable: " + item);
    }
}

bool mathUtils::AllValuesAreInt(std::queue<std::string> values, std::unordered_map<std::string, Value> variables)
{
    std::queue<std::string> vals = values;
    while(!vals.empty())
    {
        std::string item = vals.front();vals.pop();
        if(isNumeric(item))
        {
            if(!isInt(item) || item.find(".") == 1)
                    return false;
            else if(variables.find(item) != variables.end())
                if(variables.at(item).type != VarType::INT)
                    return false;
        }
    }
    return true;
}

int mathUtils::prec(std::string c)
{
    if(c == "*" || c == "/")
        return 2;
    else if(c == "+" || c == "-")
        return 1;
    return -1;
}
