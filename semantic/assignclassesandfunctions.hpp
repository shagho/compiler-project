#ifndef ASSIGNCLASSESANDFUNCTIONS_HPP
#define ASSIGNCLASSESANDFUNCTIONS_HPP

#include <unordered_map>
#include <string>
#include "Parse.h"
#include "basescope.hpp"
#include "Lexe.h"
#include "ParseBaseListener.h"
#include "classsymbol.hpp"
#include "function_symbol.hpp"
#include "basescope.hpp"
#include "field_symbol.hpp"
#include "method_symbol.hpp"
#include <tree/ParseTreeProperty.h>
#include "error.hpp"

class assignClassesandfunctions : public ParseBaseListener
{
public:
    assignClassesandfunctions();
    assignClassesandfunctions(std::unordered_map<std::string, symtab::scope *> scopess, std::vector<Error> errors);

    /*///////////////////overrideLisetener//////////////////////////////*/
    void enterProgram(Parse::ProgramContext * /*ctx*/) override;
//    void exitProgram(Parse::ProgramContext * /*ctx*/) override;

//    void enterStart_func(Parse::Start_funcContext * /*ctx*/) override;
//    void exitStart_func(Parse::Start_funcContext * /*ctx*/) override;

    void enterType_def(Parse::Type_defContext * /*ctx*/) override;
    void exitType_def(Parse::Type_defContext * /*ctx*/) override;

    void enterStart_func(Parse::Start_funcContext * /*ctx*/) override;
    void exitStart_func(Parse::Start_funcContext * /*ctx*/) override;

//    void enterComponent(Parse::ComponentContext * /*ctx*/) override;
//    void exitComponent(Parse::ComponentContext * /*ctx*/) override;

    void enterVar_def(Parse::Var_defContext * /*ctx*/) override;
    void exitVar_def(Parse::Var_defContext * /*ctx*/) override;

    void enterField_def(Parse::Field_defContext * /*ctx*/) override;
    void exitField_def(Parse::Field_defContext * /*ctx*/) override;

    void enterMethod_def(Parse::Method_defContext * /*ctx*/) override;
    void exitMethod_def(Parse::Method_defContext * /*ctx*/) override;

    void enterAccess_modifier(Parse::Access_modifierContext * /*ctx*/) override;
//    void exitAccess_modifier(Parse::Access_modifierContext * /*ctx*/) override;

//    void enterType(Parse::TypeContext * /*ctx*/) override;
//    void exitType(Parse::TypeContext * /*ctx*/) override;

//    void enterVar_val(Parse::Var_valContext * /*ctx*/) override;
//    void exitVar_val(Parse::Var_valContext * /*ctx*/) override;

    void enterFun_def(Parse::Fun_defContext * /*ctx*/) override;
    void exitFun_def(Parse::Fun_defContext * /*ctx*/) override;

//    void enterDef_args(Parse::Def_argsContext * /*ctx*/) override;
//    void exitDef_args(Parse::Def_argsContext * /*ctx*/) override;

//    void enterIfElseCond(Parse::IfElseCondContext * /*ctx*/) override;
//    void exitIfElseCond(Parse::IfElseCondContext * /*ctx*/) override;

    void enterSwitchCond(Parse::SwitchCondContext * /*ctx*/) override;
    void exitSwitchCond(Parse::SwitchCondContext * /*ctx*/) override;

    void enterIfBlock(Parse::IfBlockContext * /*ctx*/) override;
    void exitIfBlock(Parse::IfBlockContext * /*ctx*/) override;

    void enterElseBlock(Parse::ElseBlockContext * /*ctx*/) override;
    void exitElseBlock(Parse::ElseBlockContext * /*ctx*/) override;

    void enterForLoop(Parse::ForLoopContext * /*ctx*/) override;
    void exitForLoop(Parse::ForLoopContext * /*ctx*/) override;

    void enterWhileLoop(Parse::WhileLoopContext * /*ctx*/) override;
    void exitWhileLoop(Parse::WhileLoopContext * /*ctx*/) override;

    void enterBreaks(Parse::BreaksContext * /*ctx*/) override;
//    void exitBreaks(Parse::BreaksContext * /*ctx*/) override;

    void enterContinues(Parse::ContinuesContext * /*ctx*/) override;
//    void exitContinues(Parse::ContinuesContext * /*ctx*/) override;


    /*//////////////////////////////////////////////////////////////////*/
    void save(antlr4::ParserRuleContext *ctx, symtab::scope *scope);
    std::vector<Error> getErrors() const;

    std::unordered_map<std::string, symtab::scope *> getScopess() const;

    antlr4::tree::ParseTreeProperty<symtab::scope *> getScopes() const;

private:
    symtab::scope * currentScope;
    symtab::baseScope global;
    antlr4::tree::ParseTreeProperty<symtab::scope *> scopes;
    std::unordered_map<std::string, symtab::scope *> scopess;
    std::vector<Error> errors;
    bool isField = false;
    bool is_method = false;
    std::string access_modifier = "";
    int loop = 0;
};

#endif // ASSIGNCLASSESANDFUNCTIONS_HPP
