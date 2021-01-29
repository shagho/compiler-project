
// Generated from /home/navid/Compiler_project/Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprVisitor.h"


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExprBaseVisitor : public ExprVisitor {
public:

  virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStart_func(ExprParser::Start_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFt_def(ExprParser::Ft_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_def(ExprParser::Var_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(ExprParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_val(ExprParser::Var_valContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFun_def(ExprParser::Fun_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgs_var(ExprParser::Args_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(ExprParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(ExprParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(ExprParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar(ExprParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRef(ExprParser::RefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(ExprParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(ExprParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEx(ExprParser::ExContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitI_const(ExprParser::I_constContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitF_const(ExprParser::F_constContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(ExprParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall(ExprParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRead_atr(ExprParser::Read_atrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWrite_atr(ExprParser::Write_atrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandle_call(ExprParser::Handle_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParams(ExprParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond_stmt(ExprParser::Cond_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitch_body(ExprParser::Switch_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop_stmt(ExprParser::Loop_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_val(ExprParser::Const_valContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmetic1(ExprParser::Arithmetic1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmetic2(ExprParser::Arithmetic2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStart(ExprParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }


};

