#ifndef DEFCLASSESANDFUNCTIONS_HPP
#define DEFCLASSESANDFUNCTIONS_HPP

#include <unordered_map>
#include <string>
#include "Parse.h"
#include "Lexe.h"
#include "ParseBaseListener.h"
#include "scope.hpp"
#include "classsymbol.hpp"
#include "function_symbol.hpp"
#include "error.hpp"



class defClassesandfunctions: public ParseBaseListener
{
public:
    defClassesandfunctions();
    void enterType_def(Parse::Type_defContext * /*ctx*/) override;
    void enterStart_func(Parse::Start_funcContext * /*ctx*/) override;
//    void enterFt_def(Parse::Ft_defContext * /*ctx*/) override;
    void enterFun_def(Parse::Fun_defContext * /*ctx*/) override;
    void enterMethod_def(Parse::Method_defContext * /*ctx*/) override;
    void exitMethod_def(Parse::Method_defContext * /*ctx*/) override;

    std::vector<Error> getErrors() const;
    virtual~defClassesandfunctions() override{}

    std::unordered_map<std::string, symtab::scope *> getScopes() const;

private:
    std::unordered_map<std::string, symtab::scope *> scopes;
    std::vector<Error> errors;
    bool isMethod = false;
};

#endif // DEFCLASSESANDFUNCTIONS_HPP
