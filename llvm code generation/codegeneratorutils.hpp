#ifndef CODEGENERATORUTILS_HPP
#define CODEGENERATORUTILS_HPP

#include <stack>
#include <unordered_set>
#include <string>

class codeGeneratorUtils
{
public:
    codeGeneratorUtils();
    int reg = 1;
    std::string header_text = "";
    std::string main_text = "";
    std::string buffer = "";
    int str_i = 0;
    int main_reg = 1;
    int br = 0;
    std::stack<int> *br_stack = new std::stack<int>;
    std::string generate();
    void function_start(std::string id);
    void function_end();
    void call(std::string id);
    void print(std::string text);
    void printf_i32(std::string id, std::unordered_set<std::string> globalNames);
    void printf_double(std::string id, std::unordered_set<std::string> globalNames);
    void printf_string(std::string id, int length, std::unordered_set<std::string> globalNames, std::string function);
    void scanf_i32(std::string id, std::unordered_set<std::string> globalNames);
    void scnaf_double(std::string id, std::unordered_set<std::string> globalNames);
    void declare_i32(std::string id, bool global);
    void declare_double(std::string id, bool global);
    void assign_i32(std::string id, std::string value, std::unordered_set<std::string> *globalNames);
    void assign_double(std::string id, std::string value, std::unordered_set<std::string> *globalNames);
    void assign_string(std::string id, std::string text, bool global, std::string function);
    void add_i32(std::string val1, std::string val2);
    void add_double(std::string val1, std::string val2);
    void mul_i32(std::string val1, std::string val2);
    void mul_double(std::string val1, std::string val2);
    void sub_i32(std::string val1, std::string val2);
    void sub_double(std::string val1, std::string val2);
    void dive_i32(std::string val1, std::string val2);
    void dive_double(std::string val1, std::string val2);
    void load_i32(std::string id, std::unordered_set<std::string> globalNames);
    void load_double(std::string id, std::unordered_set<std::string> globalNames);
    void sitofp(std::string id);
    void fptosi(std::string id);
    void formatBuffer();
    void formatMainText();
    ~codeGeneratorUtils(){}


};

#endif // CODEGENERATORUTILS_HPP
