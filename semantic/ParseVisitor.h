
// Generated from /home/navid/Compiler_project/Parse.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "Parse.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by Parse.
 */
class  ParseVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by Parse.
   */
    virtual antlrcpp::Any visitProgram(Parse::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitStart_func(Parse::Start_funcContext *context) = 0;

    virtual antlrcpp::Any visitFt_def(Parse::Ft_defContext *context) = 0;

    virtual antlrcpp::Any visitType_def(Parse::Type_defContext *context) = 0;

    virtual antlrcpp::Any visitComponent(Parse::ComponentContext *context) = 0;

    virtual antlrcpp::Any visitField_def(Parse::Field_defContext *context) = 0;

    virtual antlrcpp::Any visitMethod_def(Parse::Method_defContext *context) = 0;

    virtual antlrcpp::Any visitAccess_modifier(Parse::Access_modifierContext *context) = 0;

    virtual antlrcpp::Any visitVar_def(Parse::Var_defContext *context) = 0;

    virtual antlrcpp::Any visitType(Parse::TypeContext *context) = 0;

    virtual antlrcpp::Any visitVar_val(Parse::Var_valContext *context) = 0;

    virtual antlrcpp::Any visitFun_def(Parse::Fun_defContext *context) = 0;

    virtual antlrcpp::Any visitDef_args(Parse::Def_argsContext *context) = 0;

    virtual antlrcpp::Any visitArgs_var(Parse::Args_varContext *context) = 0;

    virtual antlrcpp::Any visitBlock(Parse::BlockContext *context) = 0;

    virtual antlrcpp::Any visitAssignS(Parse::AssignSContext *context) = 0;

    virtual antlrcpp::Any visitFuncCallS(Parse::FuncCallSContext *context) = 0;

    virtual antlrcpp::Any visitCondS(Parse::CondSContext *context) = 0;

    virtual antlrcpp::Any visitLoopS(Parse::LoopSContext *context) = 0;

    virtual antlrcpp::Any visitBreaks(Parse::BreaksContext *context) = 0;

    virtual antlrcpp::Any visitContinues(Parse::ContinuesContext *context) = 0;

    virtual antlrcpp::Any visitDestructs(Parse::DestructsContext *context) = 0;

    virtual antlrcpp::Any visitAssign(Parse::AssignContext *context) = 0;

    virtual antlrcpp::Any visitVar(Parse::VarContext *context) = 0;

    virtual antlrcpp::Any visitRef(Parse::RefContext *context) = 0;

    virtual antlrcpp::Any visitArray_type(Parse::Array_typeContext *context) = 0;

    virtual antlrcpp::Any visitRelational2Op(Parse::Relational2OpContext *context) = 0;

    virtual antlrcpp::Any visitNull(Parse::NullContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOp(Parse::UnaryOpContext *context) = 0;

    virtual antlrcpp::Any visitFUncCallExpr(Parse::FUncCallExprContext *context) = 0;

    virtual antlrcpp::Any visitRelational13Op(Parse::Relational13OpContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOp(Parse::LogicalOpContext *context) = 0;

    virtual antlrcpp::Any visitAllocateOp(Parse::AllocateOpContext *context) = 0;

    virtual antlrcpp::Any visitConstValOp(Parse::ConstValOpContext *context) = 0;

    virtual antlrcpp::Any visitBitwiseOp(Parse::BitwiseOpContext *context) = 0;

    virtual antlrcpp::Any visitArithmetic2Op(Parse::Arithmetic2OpContext *context) = 0;

    virtual antlrcpp::Any visitArithmetic1Op(Parse::Arithmetic1OpContext *context) = 0;

    virtual antlrcpp::Any visitVarExpr(Parse::VarExprContext *context) = 0;

    virtual antlrcpp::Any visitListExpr(Parse::ListExprContext *context) = 0;

    virtual antlrcpp::Any visitParenthesisOp(Parse::ParenthesisOpContext *context) = 0;

    virtual antlrcpp::Any visitDotClall(Parse::DotClallContext *context) = 0;

    virtual antlrcpp::Any visitReadFunc(Parse::ReadFuncContext *context) = 0;

    virtual antlrcpp::Any visitWriteFunc(Parse::WriteFuncContext *context) = 0;

    virtual antlrcpp::Any visitList(Parse::ListContext *context) = 0;

    virtual antlrcpp::Any visitHandle_call(Parse::Handle_callContext *context) = 0;

    virtual antlrcpp::Any visitSwitch_body(Parse::Switch_bodyContext *context) = 0;

    virtual antlrcpp::Any visitParams(Parse::ParamsContext *context) = 0;

    virtual antlrcpp::Any visitIfElseCond(Parse::IfElseCondContext *context) = 0;

    virtual antlrcpp::Any visitSwitchCond(Parse::SwitchCondContext *context) = 0;

    virtual antlrcpp::Any visitIfBlock(Parse::IfBlockContext *context) = 0;

    virtual antlrcpp::Any visitElseBlock(Parse::ElseBlockContext *context) = 0;

    virtual antlrcpp::Any visitForLoop(Parse::ForLoopContext *context) = 0;

    virtual antlrcpp::Any visitWhileLoop(Parse::WhileLoopContext *context) = 0;

    virtual antlrcpp::Any visitConst_val(Parse::Const_valContext *context) = 0;

    virtual antlrcpp::Any visitRelational1(Parse::Relational1Context *context) = 0;

    virtual antlrcpp::Any visitRelational2(Parse::Relational2Context *context) = 0;

    virtual antlrcpp::Any visitRelational3(Parse::Relational3Context *context) = 0;

    virtual antlrcpp::Any visitArithmetic1(Parse::Arithmetic1Context *context) = 0;

    virtual antlrcpp::Any visitArithmetic2(Parse::Arithmetic2Context *context) = 0;

    virtual antlrcpp::Any visitLogical(Parse::LogicalContext *context) = 0;

    virtual antlrcpp::Any visitUnary_op(Parse::Unary_opContext *context) = 0;

    virtual antlrcpp::Any visitBitwise(Parse::BitwiseContext *context) = 0;

    virtual antlrcpp::Any visitStart(Parse::StartContext *context) = 0;


};

