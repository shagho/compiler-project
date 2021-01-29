
// Generated from /home/navid/Compiler_project/Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitStart_func(ExprParser::Start_funcContext *context) = 0;

    virtual antlrcpp::Any visitFt_def(ExprParser::Ft_defContext *context) = 0;

    virtual antlrcpp::Any visitVar_def(ExprParser::Var_defContext *context) = 0;

    virtual antlrcpp::Any visitType(ExprParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitVar_val(ExprParser::Var_valContext *context) = 0;

    virtual antlrcpp::Any visitFun_def(ExprParser::Fun_defContext *context) = 0;

    virtual antlrcpp::Any visitArgs_var(ExprParser::Args_varContext *context) = 0;

    virtual antlrcpp::Any visitBlock(ExprParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStmt(ExprParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitAssign(ExprParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitVar(ExprParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitRef(ExprParser::RefContext *context) = 0;

    virtual antlrcpp::Any visitExpr(ExprParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitTerm(ExprParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitEx(ExprParser::ExContext *context) = 0;

    virtual antlrcpp::Any visitI_const(ExprParser::I_constContext *context) = 0;

    virtual antlrcpp::Any visitF_const(ExprParser::F_constContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(ExprParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitCall(ExprParser::CallContext *context) = 0;

    virtual antlrcpp::Any visitRead_atr(ExprParser::Read_atrContext *context) = 0;

    virtual antlrcpp::Any visitWrite_atr(ExprParser::Write_atrContext *context) = 0;

    virtual antlrcpp::Any visitHandle_call(ExprParser::Handle_callContext *context) = 0;

    virtual antlrcpp::Any visitParams(ExprParser::ParamsContext *context) = 0;

    virtual antlrcpp::Any visitCond_stmt(ExprParser::Cond_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSwitch_body(ExprParser::Switch_bodyContext *context) = 0;

    virtual antlrcpp::Any visitLoop_stmt(ExprParser::Loop_stmtContext *context) = 0;

    virtual antlrcpp::Any visitConst_val(ExprParser::Const_valContext *context) = 0;

    virtual antlrcpp::Any visitArithmetic1(ExprParser::Arithmetic1Context *context) = 0;

    virtual antlrcpp::Any visitArithmetic2(ExprParser::Arithmetic2Context *context) = 0;

    virtual antlrcpp::Any visitStart(ExprParser::StartContext *context) = 0;


};

