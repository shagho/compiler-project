#ifndef TYPECHECKER_HPP
#define TYPECHECKER_HPP

#include <unordered_map>
#include <antlr4-runtime.h>
#include <string>
#include "Parse.h"
#include "basescope.hpp"
#include "Lexe.h"
#include "ParseBaseVisitor.h"
#include "classsymbol.hpp"
#include "function_symbol.hpp"
#include "basescope.hpp"
#include "field_symbol.hpp"
#include "method_symbol.hpp"
#include <tree/ParseTreeProperty.h>
#include "error.hpp"
#include <ParserRuleContext.h>
#include "ParseVisitor.h"

class typeChecker: public ParseBaseVisitor
{
public:
    typeChecker(antlr4::tree::ParseTreeProperty<symtab::scope *> scopes,
    std::unordered_map<std::string, symtab::scope *> scopess,
    std::vector<Error> errors);

    /*//////////////////////////visitors_functions/////////////////////////////*/
    antlrcpp::Any visitStart_func(Parse::Start_funcContext *context) override;

    antlrcpp::Any visitType_def(Parse::Type_defContext *context) override;

    antlrcpp::Any visitVar_def(Parse::Var_defContext *ctx) override;

    antlrcpp::Any visitFun_def(Parse::Fun_defContext *ctx) override;

    antlrcpp::Any visitDestructs(Parse::DestructsContext *ctx) override;

    antlrcpp::Any visitAssign(Parse::AssignContext *ctx) override;

    antlrcpp::Any visitVar(Parse::VarContext *ctx) override;

    antlrcpp::Any visitRef(Parse::RefContext *ctx) override;

    antlrcpp::Any visitRelational2Op(Parse::Relational2OpContext *context) override;

    antlrcpp::Any visitNull(Parse::NullContext *context) override;

    antlrcpp::Any visitUnaryOp(Parse::UnaryOpContext *ctx) override;

    antlrcpp::Any visitRelational13Op(Parse::Relational13OpContext *ctx) override;

    antlrcpp::Any visitLogicalOp(Parse::LogicalOpContext *ctx) override;

    antlrcpp::Any visitAllocateOp(Parse::AllocateOpContext *ctx) override;

    antlrcpp::Any visitConstValOp(Parse::ConstValOpContext *ctx) override;

    antlrcpp::Any visitBitwiseOp(Parse::BitwiseOpContext *ctx) override;

    antlrcpp::Any visitArithmetic2Op(Parse::Arithmetic2OpContext *ctx) override;

    antlrcpp::Any visitArithmetic1Op(Parse::Arithmetic1OpContext *ctx) override;

    antlrcpp::Any visitParenthesisOp(Parse::ParenthesisOpContext *ctx) override;

    antlrcpp::Any visitDotClall(Parse::DotClallContext *ctx) override;

    antlrcpp::Any visitReadFunc(Parse::ReadFuncContext *context) override;

    antlrcpp::Any visitWriteFunc(Parse::WriteFuncContext *ctx) override;

    antlrcpp::Any visitIfElseCond(Parse::IfElseCondContext *ctx) override;

    antlrcpp::Any visitSwitchCond(Parse::SwitchCondContext *ctx) override;

    antlrcpp::Any visitIfBlock(Parse::IfBlockContext *ctx) override;

    antlrcpp::Any visitElseBlock(Parse::ElseBlockContext *ctx) override;

    antlrcpp::Any visitForLoop(Parse::ForLoopContext *ctx) override;

    antlrcpp::Any visitWhileLoop(Parse::WhileLoopContext *context) override;

    /*//////////////////////////////////////////////////////////////////////////////*/
    symtab::symbol* scope_call(antlr4::ParserRuleContext *ctx);

    std::vector<Error> getErrors() const;

private:
    symtab::scope * currentScope;
    antlr4::tree::ParseTreeProperty<symtab::scope *> scopes;
    std::unordered_map<std::string, symtab::scope *> scopess;
    std::vector<Error> errors;
    symtab::symbol *INT= new symtab::symbol("int");
    symtab::symbol *FLOAT = new symtab::symbol("float");
    symtab::symbol *STRING = new symtab::symbol("string");
    symtab::symbol *BOOL = new symtab::symbol("bool");
    symtab::symbol *NIL = new symtab::symbol("nil");
    bool isField = false;
    bool is_method = false;
    std::string access_modifier = "";
};

#endif // TYPECHECKER_HPP
