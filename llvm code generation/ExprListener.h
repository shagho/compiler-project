
// Generated from /home/navid/Compiler_project/Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ExprParser.
 */
class  ExprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(ExprParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(ExprParser::ProgramContext *ctx) = 0;

  virtual void enterStart_func(ExprParser::Start_funcContext *ctx) = 0;
  virtual void exitStart_func(ExprParser::Start_funcContext *ctx) = 0;

  virtual void enterFt_def(ExprParser::Ft_defContext *ctx) = 0;
  virtual void exitFt_def(ExprParser::Ft_defContext *ctx) = 0;

  virtual void enterVar_def(ExprParser::Var_defContext *ctx) = 0;
  virtual void exitVar_def(ExprParser::Var_defContext *ctx) = 0;

  virtual void enterType(ExprParser::TypeContext *ctx) = 0;
  virtual void exitType(ExprParser::TypeContext *ctx) = 0;

  virtual void enterVar_val(ExprParser::Var_valContext *ctx) = 0;
  virtual void exitVar_val(ExprParser::Var_valContext *ctx) = 0;

  virtual void enterFun_def(ExprParser::Fun_defContext *ctx) = 0;
  virtual void exitFun_def(ExprParser::Fun_defContext *ctx) = 0;

  virtual void enterArgs_var(ExprParser::Args_varContext *ctx) = 0;
  virtual void exitArgs_var(ExprParser::Args_varContext *ctx) = 0;

  virtual void enterBlock(ExprParser::BlockContext *ctx) = 0;
  virtual void exitBlock(ExprParser::BlockContext *ctx) = 0;

  virtual void enterStmt(ExprParser::StmtContext *ctx) = 0;
  virtual void exitStmt(ExprParser::StmtContext *ctx) = 0;

  virtual void enterAssign(ExprParser::AssignContext *ctx) = 0;
  virtual void exitAssign(ExprParser::AssignContext *ctx) = 0;

  virtual void enterVar(ExprParser::VarContext *ctx) = 0;
  virtual void exitVar(ExprParser::VarContext *ctx) = 0;

  virtual void enterRef(ExprParser::RefContext *ctx) = 0;
  virtual void exitRef(ExprParser::RefContext *ctx) = 0;

  virtual void enterExpr(ExprParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ExprParser::ExprContext *ctx) = 0;

  virtual void enterTerm(ExprParser::TermContext *ctx) = 0;
  virtual void exitTerm(ExprParser::TermContext *ctx) = 0;

  virtual void enterEx(ExprParser::ExContext *ctx) = 0;
  virtual void exitEx(ExprParser::ExContext *ctx) = 0;

  virtual void enterI_const(ExprParser::I_constContext *ctx) = 0;
  virtual void exitI_const(ExprParser::I_constContext *ctx) = 0;

  virtual void enterF_const(ExprParser::F_constContext *ctx) = 0;
  virtual void exitF_const(ExprParser::F_constContext *ctx) = 0;

  virtual void enterIdentifier(ExprParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(ExprParser::IdentifierContext *ctx) = 0;

  virtual void enterCall(ExprParser::CallContext *ctx) = 0;
  virtual void exitCall(ExprParser::CallContext *ctx) = 0;

  virtual void enterRead_atr(ExprParser::Read_atrContext *ctx) = 0;
  virtual void exitRead_atr(ExprParser::Read_atrContext *ctx) = 0;

  virtual void enterWrite_atr(ExprParser::Write_atrContext *ctx) = 0;
  virtual void exitWrite_atr(ExprParser::Write_atrContext *ctx) = 0;

  virtual void enterHandle_call(ExprParser::Handle_callContext *ctx) = 0;
  virtual void exitHandle_call(ExprParser::Handle_callContext *ctx) = 0;

  virtual void enterParams(ExprParser::ParamsContext *ctx) = 0;
  virtual void exitParams(ExprParser::ParamsContext *ctx) = 0;

  virtual void enterCond_stmt(ExprParser::Cond_stmtContext *ctx) = 0;
  virtual void exitCond_stmt(ExprParser::Cond_stmtContext *ctx) = 0;

  virtual void enterSwitch_body(ExprParser::Switch_bodyContext *ctx) = 0;
  virtual void exitSwitch_body(ExprParser::Switch_bodyContext *ctx) = 0;

  virtual void enterLoop_stmt(ExprParser::Loop_stmtContext *ctx) = 0;
  virtual void exitLoop_stmt(ExprParser::Loop_stmtContext *ctx) = 0;

  virtual void enterConst_val(ExprParser::Const_valContext *ctx) = 0;
  virtual void exitConst_val(ExprParser::Const_valContext *ctx) = 0;

  virtual void enterArithmetic1(ExprParser::Arithmetic1Context *ctx) = 0;
  virtual void exitArithmetic1(ExprParser::Arithmetic1Context *ctx) = 0;

  virtual void enterArithmetic2(ExprParser::Arithmetic2Context *ctx) = 0;
  virtual void exitArithmetic2(ExprParser::Arithmetic2Context *ctx) = 0;

  virtual void enterStart(ExprParser::StartContext *ctx) = 0;
  virtual void exitStart(ExprParser::StartContext *ctx) = 0;


};

