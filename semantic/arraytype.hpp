#ifndef ARRAYTYPE_HPP
#define ARRAYTYPE_HPP

#include "type.hpp"

namespace symtab
{
    class arrayType
    {
    public:
        arrayType();
        arrayType(type elem);
        arrayType(type elem, int numElm);
        std::string getName();
        int getSize();
        std::string getType();
    private:
       type Type;
       int number_of_elem = 0;
    };

    arrayType::arrayType(type elem)
    {
        this->Type = elem;
    }

    arrayType::arrayType(type elem, int num)
    {
        this->Type = elem;
        this->number_of_elem = num;
    }

    std::string arrayType::getName()
    {
        return Type.getName();
    }

    int arrayType::getSize()
    {
        return Type.getSize();
    }

    std::string arrayType::getType()
    {
        return Type.getTypeString();
    }


}


#endif // ARRAYTYPE_HPP
