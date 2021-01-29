#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <antlr4-runtime.h>
#include "codegeneratorutils.hpp"
#include "ExprBaseListener.h"
#include "ExprParser.h"
#include "mathutils.hpp"

class actions : public ExprBaseListener
{
public:
    actions();
    /*///////////////////////////////////////////listener begin//////////////*/

    void exitProgram(ExprParser::ProgramContext * /*ctx*/) override;

    void enterStart_func(ExprParser::Start_funcContext * /*ctx*/) override;
    void exitStart_func(ExprParser::Start_funcContext * /*ctx*/) override;

    void exitVar_def(ExprParser::Var_defContext * /*ctx*/) override;

    void enterFun_def(ExprParser::Fun_defContext * /*ctx*/) override;
    void exitFun_def(ExprParser::Fun_defContext * /*ctx*/) override;

    void exitAssign(ExprParser::AssignContext * /*ctx*/) override;

    void enterEx(ExprParser::ExContext * /*ctx*/) override;
    void exitEx(ExprParser::ExContext * /*ctx*/) override;

    void exitIdentifier(ExprParser::IdentifierContext * /*ctx*/) override;

    void exitCall(ExprParser::CallContext * /*ctx*/) override;

    void exitWrite_atr(ExprParser::Write_atrContext * /*ctx*/) override;

    void exitI_const(ExprParser::I_constContext * /*ctx*/) override;

    void exitF_const(ExprParser::F_constContext * /*ctx*/) override;

    void exitArithmetic1(ExprParser::Arithmetic1Context * /*ctx*/) override;

    void exitArithmetic2(ExprParser::Arithmetic2Context * /*ctx*/) override;

    /*///////////////////////////////////listener end//////////////////////*/
    ~actions() override{}


private:
    std::unordered_map<std::string, Value> variables;
    std::unordered_set<std::string> globalNames;
    std::unordered_set<std::string> localNames;
    std::queue<std::string> infixExpr;
    bool global = true;
    std::string function;
    codeGeneratorUtils code;


    Value getValue(ExprParser::Const_valContext *ctx);
    void declareVariable(std::string ID, Value value);
    void assignVariable(std::string ID, Value value, int line, bool isMathExpr);
    std::string getValue(Value value, bool isMathExpr);
    void assignString(std::string id, Value value, int line);
    void printConstant(ExprParser::Const_valContext *ctx);
    void printVariable(std::string ID);
    std::string getTextWithoutQuotes(ExprParser::Const_valContext *ctx);
    void removeLocalVariables();
    void error(int line, std::string msg);
};

#endif // ACTIONS_HPP
