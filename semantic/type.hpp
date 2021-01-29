#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <unordered_map>

namespace symtab
{
enum types
{
    t_int = 4,
    t_float = 8,
    t_nil = 1,
    t_bool = 1,
    t_string = 0,
};

const std::unordered_map <std::string, types > type_map =
    {
        { "string"    , types::t_string },
        { "bool"      , types::t_bool   },
        { "int"       , types::t_int    },
        { "float"     , types::t_float  },
        { "nil"       , types::t_nil    }
    };

const std::unordered_map <types,std::string > type_map_1 =
    {
        { types::t_string   ,  "string"  },
        { types::t_bool     ,  "bool"    },
        { types::t_int      ,  "int"     },
        { types::t_float    ,  "float"   },
        { types::t_nil      ,  "nil"     }
    };

    class type
    {
    public:
        type();
        type(std::string  type, std::string name,std::string const_value);
        virtual ~type() = default;
        std::string getName() const;
        void setName(const std::string &value);


        types getType() const;
        void setType(const types &value);

        int getSize() const;
        void setSize(int value);

        std::string getConst_value() const;
        void setConst_value(const std::string &value);

        std::string getTypeString() const;

    private:
        types Type;
        std::string Name = "";
        int size = 0;
        std::string const_value = "";

    };



}


#endif // TYPE_HPP
