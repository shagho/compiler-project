#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>

class Error
{
public:
    std::string message;
    int lineNumber;
    int columnNumber;
    Error(std::string message, int lineNumber, int columnNumber)
    {
        this->message = message;
        this->lineNumber = lineNumber;
        this->columnNumber = columnNumber;
    }
};


#endif // ERROR_HPP
