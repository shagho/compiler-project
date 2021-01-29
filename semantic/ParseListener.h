
// Generated from /home/navid/Compiler_project/Parse.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "Parse.h"


/**
 * This interface defines an abstract listener for a parse tree produced by Parse.
 */
class  ParseListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(Parse::ProgramContext *ctx) = 0;
  virtual void exitProgram(Parse::ProgramContext *ctx) = 0;

  virtual void enterStart_func(Parse::Start_funcContext *ctx) = 0;
  virtual void exitStart_func(Parse::Start_funcContext *ctx) = 0;

  virtual void enterFt_def(Parse::Ft_defContext *ctx) = 0;
  virtual void exitFt_def(Parse::Ft_defContext *ctx) = 0;

  virtual void enterType_def(Parse::Type_defContext *ctx) = 0;
  virtual void exitType_def(Parse::Type_defContext *ctx) = 0;

  virtual void enterComponent(Parse::ComponentContext *ctx) = 0;
  virtual void exitComponent(Parse::ComponentContext *ctx) = 0;

  virtual void enterField_def(Parse::Field_defContext *ctx) = 0;
  virtual void exitField_def(Parse::Field_defContext *ctx) = 0;

  virtual void enterMethod_def(Parse::Method_defContext *ctx) = 0;
  virtual void exitMethod_def(Parse::Method_defContext *ctx) = 0;

  virtual void enterAccess_modifier(Parse::Access_modifierContext *ctx) = 0;
  virtual void exitAccess_modifier(Parse::Access_modifierContext *ctx) = 0;

  virtual void enterVar_def(Parse::Var_defContext *ctx) = 0;
  virtual void exitVar_def(Parse::Var_defContext *ctx) = 0;

  virtual void enterType(Parse::TypeContext *ctx) = 0;
  virtual void exitType(Parse::TypeContext *ctx) = 0;

  virtual void enterVar_val(Parse::Var_valContext *ctx) = 0;
  virtual void exitVar_val(Parse::Var_valContext *ctx) = 0;

  virtual void enterFun_def(Parse::Fun_defContext *ctx) = 0;
  virtual void exitFun_def(Parse::Fun_defContext *ctx) = 0;

  virtual void enterDef_args(Parse::Def_argsContext *ctx) = 0;
  virtual void exitDef_args(Parse::Def_argsContext *ctx) = 0;

  virtual void enterArgs_var(Parse::Args_varContext *ctx) = 0;
  virtual void exitArgs_var(Parse::Args_varContext *ctx) = 0;

  virtual void enterBlock(Parse::BlockContext *ctx) = 0;
  virtual void exitBlock(Parse::BlockContext *ctx) = 0;

  virtual void enterAssignS(Parse::AssignSContext *ctx) = 0;
  virtual void exitAssignS(Parse::AssignSContext *ctx) = 0;

  virtual void enterFuncCallS(Parse::FuncCallSContext *ctx) = 0;
  virtual void exitFuncCallS(Parse::FuncCallSContext *ctx) = 0;

  virtual void enterCondS(Parse::CondSContext *ctx) = 0;
  virtual void exitCondS(Parse::CondSContext *ctx) = 0;

  virtual void enterLoopS(Parse::LoopSContext *ctx) = 0;
  virtual void exitLoopS(Parse::LoopSContext *ctx) = 0;

  virtual void enterBreaks(Parse::BreaksContext *ctx) = 0;
  virtual void exitBreaks(Parse::BreaksContext *ctx) = 0;

  virtual void enterContinues(Parse::ContinuesContext *ctx) = 0;
  virtual void exitContinues(Parse::ContinuesContext *ctx) = 0;

  virtual void enterDestructs(Parse::DestructsContext *ctx) = 0;
  virtual void exitDestructs(Parse::DestructsContext *ctx) = 0;

  virtual void enterAssign(Parse::AssignContext *ctx) = 0;
  virtual void exitAssign(Parse::AssignContext *ctx) = 0;

  virtual void enterVar(Parse::VarContext *ctx) = 0;
  virtual void exitVar(Parse::VarContext *ctx) = 0;

  virtual void enterRef(Parse::RefContext *ctx) = 0;
  virtual void exitRef(Parse::RefContext *ctx) = 0;

  virtual void enterArray_type(Parse::Array_typeContext *ctx) = 0;
  virtual void exitArray_type(Parse::Array_typeContext *ctx) = 0;

  virtual void enterRelational2Op(Parse::Relational2OpContext *ctx) = 0;
  virtual void exitRelational2Op(Parse::Relational2OpContext *ctx) = 0;

  virtual void enterNull(Parse::NullContext *ctx) = 0;
  virtual void exitNull(Parse::NullContext *ctx) = 0;

  virtual void enterUnaryOp(Parse::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(Parse::UnaryOpContext *ctx) = 0;

  virtual void enterFUncCallExpr(Parse::FUncCallExprContext *ctx) = 0;
  virtual void exitFUncCallExpr(Parse::FUncCallExprContext *ctx) = 0;

  virtual void enterRelational13Op(Parse::Relational13OpContext *ctx) = 0;
  virtual void exitRelational13Op(Parse::Relational13OpContext *ctx) = 0;

  virtual void enterLogicalOp(Parse::LogicalOpContext *ctx) = 0;
  virtual void exitLogicalOp(Parse::LogicalOpContext *ctx) = 0;

  virtual void enterAllocateOp(Parse::AllocateOpContext *ctx) = 0;
  virtual void exitAllocateOp(Parse::AllocateOpContext *ctx) = 0;

  virtual void enterConstValOp(Parse::ConstValOpContext *ctx) = 0;
  virtual void exitConstValOp(Parse::ConstValOpContext *ctx) = 0;

  virtual void enterBitwiseOp(Parse::BitwiseOpContext *ctx) = 0;
  virtual void exitBitwiseOp(Parse::BitwiseOpContext *ctx) = 0;

  virtual void enterArithmetic2Op(Parse::Arithmetic2OpContext *ctx) = 0;
  virtual void exitArithmetic2Op(Parse::Arithmetic2OpContext *ctx) = 0;

  virtual void enterArithmetic1Op(Parse::Arithmetic1OpContext *ctx) = 0;
  virtual void exitArithmetic1Op(Parse::Arithmetic1OpContext *ctx) = 0;

  virtual void enterVarExpr(Parse::VarExprContext *ctx) = 0;
  virtual void exitVarExpr(Parse::VarExprContext *ctx) = 0;

  virtual void enterListExpr(Parse::ListExprContext *ctx) = 0;
  virtual void exitListExpr(Parse::ListExprContext *ctx) = 0;

  virtual void enterParenthesisOp(Parse::ParenthesisOpContext *ctx) = 0;
  virtual void exitParenthesisOp(Parse::ParenthesisOpContext *ctx) = 0;

  virtual void enterDotClall(Parse::DotClallContext *ctx) = 0;
  virtual void exitDotClall(Parse::DotClallContext *ctx) = 0;

  virtual void enterReadFunc(Parse::ReadFuncContext *ctx) = 0;
  virtual void exitReadFunc(Parse::ReadFuncContext *ctx) = 0;

  virtual void enterWriteFunc(Parse::WriteFuncContext *ctx) = 0;
  virtual void exitWriteFunc(Parse::WriteFuncContext *ctx) = 0;

  virtual void enterList(Parse::ListContext *ctx) = 0;
  virtual void exitList(Parse::ListContext *ctx) = 0;

  virtual void enterHandle_call(Parse::Handle_callContext *ctx) = 0;
  virtual void exitHandle_call(Parse::Handle_callContext *ctx) = 0;

  virtual void enterSwitch_body(Parse::Switch_bodyContext *ctx) = 0;
  virtual void exitSwitch_body(Parse::Switch_bodyContext *ctx) = 0;

  virtual void enterParams(Parse::ParamsContext *ctx) = 0;
  virtual void exitParams(Parse::ParamsContext *ctx) = 0;

  virtual void enterIfElseCond(Parse::IfElseCondContext *ctx) = 0;
  virtual void exitIfElseCond(Parse::IfElseCondContext *ctx) = 0;

  virtual void enterSwitchCond(Parse::SwitchCondContext *ctx) = 0;
  virtual void exitSwitchCond(Parse::SwitchCondContext *ctx) = 0;

  virtual void enterIfBlock(Parse::IfBlockContext *ctx) = 0;
  virtual void exitIfBlock(Parse::IfBlockContext *ctx) = 0;

  virtual void enterElseBlock(Parse::ElseBlockContext *ctx) = 0;
  virtual void exitElseBlock(Parse::ElseBlockContext *ctx) = 0;

  virtual void enterForLoop(Parse::ForLoopContext *ctx) = 0;
  virtual void exitForLoop(Parse::ForLoopContext *ctx) = 0;

  virtual void enterWhileLoop(Parse::WhileLoopContext *ctx) = 0;
  virtual void exitWhileLoop(Parse::WhileLoopContext *ctx) = 0;

  virtual void enterConst_val(Parse::Const_valContext *ctx) = 0;
  virtual void exitConst_val(Parse::Const_valContext *ctx) = 0;

  virtual void enterRelational1(Parse::Relational1Context *ctx) = 0;
  virtual void exitRelational1(Parse::Relational1Context *ctx) = 0;

  virtual void enterRelational2(Parse::Relational2Context *ctx) = 0;
  virtual void exitRelational2(Parse::Relational2Context *ctx) = 0;

  virtual void enterRelational3(Parse::Relational3Context *ctx) = 0;
  virtual void exitRelational3(Parse::Relational3Context *ctx) = 0;

  virtual void enterArithmetic1(Parse::Arithmetic1Context *ctx) = 0;
  virtual void exitArithmetic1(Parse::Arithmetic1Context *ctx) = 0;

  virtual void enterArithmetic2(Parse::Arithmetic2Context *ctx) = 0;
  virtual void exitArithmetic2(Parse::Arithmetic2Context *ctx) = 0;

  virtual void enterLogical(Parse::LogicalContext *ctx) = 0;
  virtual void exitLogical(Parse::LogicalContext *ctx) = 0;

  virtual void enterUnary_op(Parse::Unary_opContext *ctx) = 0;
  virtual void exitUnary_op(Parse::Unary_opContext *ctx) = 0;

  virtual void enterBitwise(Parse::BitwiseContext *ctx) = 0;
  virtual void exitBitwise(Parse::BitwiseContext *ctx) = 0;

  virtual void enterStart(Parse::StartContext *ctx) = 0;
  virtual void exitStart(Parse::StartContext *ctx) = 0;


};

