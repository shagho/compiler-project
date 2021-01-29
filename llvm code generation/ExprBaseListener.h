
// Generated from /home/navid/Compiler_project/Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprListener.h"


/**
 * This class provides an empty implementation of ExprListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ExprBaseListener : public ExprListener {
public:

  virtual void enterProgram(ExprParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(ExprParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStart_func(ExprParser::Start_funcContext * /*ctx*/) override { }
  virtual void exitStart_func(ExprParser::Start_funcContext * /*ctx*/) override { }

  virtual void enterFt_def(ExprParser::Ft_defContext * /*ctx*/) override { }
  virtual void exitFt_def(ExprParser::Ft_defContext * /*ctx*/) override { }

  virtual void enterVar_def(ExprParser::Var_defContext * /*ctx*/) override { }
  virtual void exitVar_def(ExprParser::Var_defContext * /*ctx*/) override { }

  virtual void enterType(ExprParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(ExprParser::TypeContext * /*ctx*/) override { }

  virtual void enterVar_val(ExprParser::Var_valContext * /*ctx*/) override { }
  virtual void exitVar_val(ExprParser::Var_valContext * /*ctx*/) override { }

  virtual void enterFun_def(ExprParser::Fun_defContext * /*ctx*/) override { }
  virtual void exitFun_def(ExprParser::Fun_defContext * /*ctx*/) override { }

  virtual void enterArgs_var(ExprParser::Args_varContext * /*ctx*/) override { }
  virtual void exitArgs_var(ExprParser::Args_varContext * /*ctx*/) override { }

  virtual void enterBlock(ExprParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(ExprParser::BlockContext * /*ctx*/) override { }

  virtual void enterStmt(ExprParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(ExprParser::StmtContext * /*ctx*/) override { }

  virtual void enterAssign(ExprParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(ExprParser::AssignContext * /*ctx*/) override { }

  virtual void enterVar(ExprParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(ExprParser::VarContext * /*ctx*/) override { }

  virtual void enterRef(ExprParser::RefContext * /*ctx*/) override { }
  virtual void exitRef(ExprParser::RefContext * /*ctx*/) override { }

  virtual void enterExpr(ExprParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ExprParser::ExprContext * /*ctx*/) override { }

  virtual void enterTerm(ExprParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(ExprParser::TermContext * /*ctx*/) override { }

  virtual void enterEx(ExprParser::ExContext * /*ctx*/) override { }
  virtual void exitEx(ExprParser::ExContext * /*ctx*/) override { }

  virtual void enterI_const(ExprParser::I_constContext * /*ctx*/) override { }
  virtual void exitI_const(ExprParser::I_constContext * /*ctx*/) override { }

  virtual void enterF_const(ExprParser::F_constContext * /*ctx*/) override { }
  virtual void exitF_const(ExprParser::F_constContext * /*ctx*/) override { }

  virtual void enterIdentifier(ExprParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(ExprParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterCall(ExprParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(ExprParser::CallContext * /*ctx*/) override { }

  virtual void enterRead_atr(ExprParser::Read_atrContext * /*ctx*/) override { }
  virtual void exitRead_atr(ExprParser::Read_atrContext * /*ctx*/) override { }

  virtual void enterWrite_atr(ExprParser::Write_atrContext * /*ctx*/) override { }
  virtual void exitWrite_atr(ExprParser::Write_atrContext * /*ctx*/) override { }

  virtual void enterHandle_call(ExprParser::Handle_callContext * /*ctx*/) override { }
  virtual void exitHandle_call(ExprParser::Handle_callContext * /*ctx*/) override { }

  virtual void enterParams(ExprParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(ExprParser::ParamsContext * /*ctx*/) override { }

  virtual void enterCond_stmt(ExprParser::Cond_stmtContext * /*ctx*/) override { }
  virtual void exitCond_stmt(ExprParser::Cond_stmtContext * /*ctx*/) override { }

  virtual void enterSwitch_body(ExprParser::Switch_bodyContext * /*ctx*/) override { }
  virtual void exitSwitch_body(ExprParser::Switch_bodyContext * /*ctx*/) override { }

  virtual void enterLoop_stmt(ExprParser::Loop_stmtContext * /*ctx*/) override { }
  virtual void exitLoop_stmt(ExprParser::Loop_stmtContext * /*ctx*/) override { }

  virtual void enterConst_val(ExprParser::Const_valContext * /*ctx*/) override { }
  virtual void exitConst_val(ExprParser::Const_valContext * /*ctx*/) override { }

  virtual void enterArithmetic1(ExprParser::Arithmetic1Context * /*ctx*/) override { }
  virtual void exitArithmetic1(ExprParser::Arithmetic1Context * /*ctx*/) override { }

  virtual void enterArithmetic2(ExprParser::Arithmetic2Context * /*ctx*/) override { }
  virtual void exitArithmetic2(ExprParser::Arithmetic2Context * /*ctx*/) override { }

  virtual void enterStart(ExprParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(ExprParser::StartContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

