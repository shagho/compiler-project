
// Generated from /home/navid/Compiler_project/Parse.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ParseVisitor.h"


/**
 * This class provides an empty implementation of ParseVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ParseBaseVisitor : public ParseVisitor {
public:

  virtual antlrcpp::Any visitProgram(Parse::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStart_func(Parse::Start_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFt_def(Parse::Ft_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_def(Parse::Type_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent(Parse::ComponentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitField_def(Parse::Field_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_def(Parse::Method_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccess_modifier(Parse::Access_modifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_def(Parse::Var_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(Parse::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_val(Parse::Var_valContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFun_def(Parse::Fun_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDef_args(Parse::Def_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgs_var(Parse::Args_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(Parse::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignS(Parse::AssignSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCallS(Parse::FuncCallSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondS(Parse::CondSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopS(Parse::LoopSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreaks(Parse::BreaksContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinues(Parse::ContinuesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDestructs(Parse::DestructsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(Parse::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar(Parse::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRef(Parse::RefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_type(Parse::Array_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelational2Op(Parse::Relational2OpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNull(Parse::NullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOp(Parse::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFUncCallExpr(Parse::FUncCallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelational13Op(Parse::Relational13OpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalOp(Parse::LogicalOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllocateOp(Parse::AllocateOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstValOp(Parse::ConstValOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitwiseOp(Parse::BitwiseOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmetic2Op(Parse::Arithmetic2OpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmetic1Op(Parse::Arithmetic1OpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarExpr(Parse::VarExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListExpr(Parse::ListExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesisOp(Parse::ParenthesisOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDotClall(Parse::DotClallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadFunc(Parse::ReadFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWriteFunc(Parse::WriteFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList(Parse::ListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandle_call(Parse::Handle_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitch_body(Parse::Switch_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParams(Parse::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfElseCond(Parse::IfElseCondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchCond(Parse::SwitchCondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfBlock(Parse::IfBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElseBlock(Parse::ElseBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForLoop(Parse::ForLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileLoop(Parse::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_val(Parse::Const_valContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelational1(Parse::Relational1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelational2(Parse::Relational2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelational3(Parse::Relational3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmetic1(Parse::Arithmetic1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmetic2(Parse::Arithmetic2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogical(Parse::LogicalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_op(Parse::Unary_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitwise(Parse::BitwiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStart(Parse::StartContext *ctx) override {
    return visitChildren(ctx);
  }


};

