#ifndef DEFSYMBOLANDSCOPES_HPP
#define DEFSYMBOLANDSCOPES_HPP

#include "basescope.hpp"
#include "classsymbol.hpp"
#include "field_symbol.hpp"
#include "method_symbol.hpp"
#include "Parse.h"
#include "Lexe.h"
#include "ParseBaseListener.h"
#include "ParseBaseVisitor.h"
#include "error.hpp"
#include <tree/ParseTreeProperty.h>


class defSymbolandScopes: public ParseBaseListener, public ParseBaseVisitor
{
public:
    defSymbolandScopes();
    void enterProgram(Parse::ProgramContext * /*ctx*/) override;
    void exitProgram(Parse::ProgramContext * /*ctx*/) override;

    void enterType_def(Parse::Type_defContext * /*ctx*/) override;
    void exitType_def(Parse::Type_defContext * /*ctx*/) override;

//    void enterComponent(Parse::ComponentContext * /*ctx*/) override;
//    void exitComponent(Parse::ComponentContext * /*ctx*/) override;

//    void enterVar_def(Parse::Var_defContext * /*ctx*/) override;
//    void exitVar_def(Parse::Var_defContext * /*ctx*/) override;

    void enterField_def(Parse::Field_defContext * /*ctx*/) override;
//    virtual void exitField_def(Parse::Field_defContext * /*ctx*/) override;

//    virtual void enterMethod_def(Parse::Method_defContext * /*ctx*/) override;
//    virtual void exitMethod_def(Parse::Method_defContext * /*ctx*/) override;


//    void enterAccess_modifier(Parse::Access_modifierContext * /*ctx*/) override;
//    virtual void exitAccess_modifier(Parse::Access_modifierContext * /*ctx*/) override;

//    virtual void enterType(Parse::TypeContext * /*ctx*/) override { }
//    virtual void exitType(Parse::TypeContext * /*ctx*/) override { }

//    virtual void enterVar_val(Parse::Var_valContext * /*ctx*/) override { }
//    virtual void exitVar_val(Parse::Var_valContext * /*ctx*/) override { }

//    virtual void enterFun_def(Parse::Fun_defContext * /*ctx*/) override { }
//    virtual void exitFun_def(Parse::Fun_defContext * /*ctx*/) override { }

//    virtual void enterDef_args(Parse::Def_argsContext * /*ctx*/) override { }
//    virtual void exitDef_args(Parse::Def_argsContext * /*ctx*/) override { }

//    virtual void enterArgs_var(Parse::Args_varContext * /*ctx*/) override { }
//    virtual void exitArgs_var(Parse::Args_varContext * /*ctx*/) override { }

//    virtual void enterBlock(Parse::BlockContext * /*ctx*/) override { }
//    virtual void exitBlock(Parse::BlockContext * /*ctx*/) override { }

//    virtual void enterAssignS(Parse::AssignSContext * /*ctx*/) override { }
//    virtual void exitAssignS(Parse::AssignSContext * /*ctx*/) override { }

//    virtual void enterFuncCallS(Parse::FuncCallSContext * /*ctx*/) override { }
//    virtual void exitFuncCallS(Parse::FuncCallSContext * /*ctx*/) override { }

//    virtual void enterCondS(Parse::CondSContext * /*ctx*/) override { }
//    virtual void exitCondS(Parse::CondSContext * /*ctx*/) override { }

//    virtual void enterLoopS(Parse::LoopSContext * /*ctx*/) override { }
//    virtual void exitLoopS(Parse::LoopSContext * /*ctx*/) override { }

//    virtual void enterBreaks(Parse::BreaksContext * /*ctx*/) override { }
//    virtual void exitBreaks(Parse::BreaksContext * /*ctx*/) override { }

//    virtual void enterContinues(Parse::ContinuesContext * /*ctx*/) override { }
//    virtual void exitContinues(Parse::ContinuesContext * /*ctx*/) override { }

//    virtual void enterDestructs(Parse::DestructsContext * /*ctx*/) override { }
//    virtual void exitDestructs(Parse::DestructsContext * /*ctx*/) override { }

//    virtual void enterAssign(Parse::AssignContext * /*ctx*/) override { }
//    virtual void exitAssign(Parse::AssignContext * /*ctx*/) override { }

//    virtual void enterVar(Parse::VarContext * /*ctx*/) override { }
//    virtual void exitVar(Parse::VarContext * /*ctx*/) override { }

//    virtual void enterRef(Parse::RefContext * /*ctx*/) override { }
//    virtual void exitRef(Parse::RefContext * /*ctx*/) override { }

//    virtual void enterArray_type(Parse::Array_typeContext * /*ctx*/) override { }
//    virtual void exitArray_type(Parse::Array_typeContext * /*ctx*/) override { }

//    virtual void enterRelational2Op(Parse::Relational2OpContext * /*ctx*/) override { }
//    virtual void exitRelational2Op(Parse::Relational2OpContext * /*ctx*/) override { }

//    virtual void enterNull(Parse::NullContext * /*ctx*/) override { }
//    virtual void exitNull(Parse::NullContext * /*ctx*/) override { }

//    virtual void enterUnaryOp(Parse::UnaryOpContext * /*ctx*/) override { }
//    virtual void exitUnaryOp(Parse::UnaryOpContext * /*ctx*/) override { }

//    virtual void enterFUncCallExpr(Parse::FUncCallExprContext * /*ctx*/) override { }
//    virtual void exitFUncCallExpr(Parse::FUncCallExprContext * /*ctx*/) override { }

//    virtual void enterRelational13Op(Parse::Relational13OpContext * /*ctx*/) override { }
//    virtual void exitRelational13Op(Parse::Relational13OpContext * /*ctx*/) override { }

//    virtual void enterLogicalOp(Parse::LogicalOpContext * /*ctx*/) override { }
//    virtual void exitLogicalOp(Parse::LogicalOpContext * /*ctx*/) override { }

//    virtual void enterAllocateOp(Parse::AllocateOpContext * /*ctx*/) override { }
//    virtual void exitAllocateOp(Parse::AllocateOpContext * /*ctx*/) override { }

//    virtual void enterConstValOp(Parse::ConstValOpContext * /*ctx*/) override { }
//    virtual void exitConstValOp(Parse::ConstValOpContext * /*ctx*/) override { }

//    virtual void enterBitwiseOp(Parse::BitwiseOpContext * /*ctx*/) override { }
//    virtual void exitBitwiseOp(Parse::BitwiseOpContext * /*ctx*/) override { }

//    virtual void enterArithmetic2Op(Parse::Arithmetic2OpContext * /*ctx*/) override { }
//    virtual void exitArithmetic2Op(Parse::Arithmetic2OpContext * /*ctx*/) override { }

//    virtual void enterArithmetic1Op(Parse::Arithmetic1OpContext * /*ctx*/) override { }
//    virtual void exitArithmetic1Op(Parse::Arithmetic1OpContext * /*ctx*/) override { }

//    virtual void enterVarExpr(Parse::VarExprContext * /*ctx*/) override { }
//    virtual void exitVarExpr(Parse::VarExprContext * /*ctx*/) override { }

//    virtual void enterListExpr(Parse::ListExprContext * /*ctx*/) override { }
//    virtual void exitListExpr(Parse::ListExprContext * /*ctx*/) override { }

//    virtual void enterDotClall(Parse::DotClallContext * /*ctx*/) override { }
//    virtual void exitDotClall(Parse::DotClallContext * /*ctx*/) override { }

//    virtual void enterReadFunc(Parse::ReadFuncContext * /*ctx*/) override { }
//    virtual void exitReadFunc(Parse::ReadFuncContext * /*ctx*/) override { }

//    virtual void enterWriteFunc(Parse::WriteFuncContext * /*ctx*/) override { }
//    virtual void exitWriteFunc(Parse::WriteFuncContext * /*ctx*/) override { }

//    virtual void enterList(Parse::ListContext * /*ctx*/) override { }
//    virtual void exitList(Parse::ListContext * /*ctx*/) override { }

//    virtual void enterHandle_call(Parse::Handle_callContext * /*ctx*/) override { }
//    virtual void exitHandle_call(Parse::Handle_callContext * /*ctx*/) override { }

//    virtual void enterSwitch_body(Parse::Switch_bodyContext * /*ctx*/) override { }
//    virtual void exitSwitch_body(Parse::Switch_bodyContext * /*ctx*/) override { }

//    virtual void enterParams(Parse::ParamsContext * /*ctx*/) override { }
//    virtual void exitParams(Parse::ParamsContext * /*ctx*/) override { }


//    virtual void enterSwitchCond(Parse::SwitchCondContext * /*ctx*/) override { }
//    virtual void exitSwitchCond(Parse::SwitchCondContext * /*ctx*/) override { }

//    virtual void enterForLoop(Parse::ForLoopContext * /*ctx*/) override { }
//    virtual void exitForLoop(Parse::ForLoopContext * /*ctx*/) override { }

//    virtual void enterWhileLoop(Parse::WhileLoopContext * /*ctx*/) override { }
//    virtual void exitWhileLoop(Parse::WhileLoopContext * /*ctx*/) override { }

//    virtual void enterConst_val(Parse::Const_valContext * /*ctx*/) override { }
//    virtual void exitConst_val(Parse::Const_valContext * /*ctx*/) override { }

//    virtual void enterRelational1(Parse::Relational1Context * /*ctx*/) override { }
//    virtual void exitRelational1(Parse::Relational1Context * /*ctx*/) override { }

//    virtual void enterRelational2(Parse::Relational2Context * /*ctx*/) override { }
//    virtual void exitRelational2(Parse::Relational2Context * /*ctx*/) override { }

//    virtual void enterRelational3(Parse::Relational3Context * /*ctx*/) override { }
//    virtual void exitRelational3(Parse::Relational3Context * /*ctx*/) override { }

//    virtual void enterArithmetic1(Parse::Arithmetic1Context * /*ctx*/) override { }
//    virtual void exitArithmetic1(Parse::Arithmetic1Context * /*ctx*/) override { }

//    virtual void enterArithmetic2(Parse::Arithmetic2Context * /*ctx*/) override { }
//    virtual void exitArithmetic2(Parse::Arithmetic2Context * /*ctx*/) override { }

//    virtual void enterLogical(Parse::LogicalContext * /*ctx*/) override { }
//    virtual void exitLogical(Parse::LogicalContext * /*ctx*/) override { }

//    virtual void enterUnary_op(Parse::Unary_opContext * /*ctx*/) override { }
//    virtual void exitUnary_op(Parse::Unary_opContext * /*ctx*/) override { }

//    virtual void enterBitwise(Parse::BitwiseContext * /*ctx*/) override { }
//    virtual void exitBitwise(Parse::BitwiseContext * /*ctx*/) override { }

    //visitor implementation
//    antlrcpp::Any visitAccess_modifier(Parse::Access_modifierContext *ctx) override;
//    antlrcpp::Any visitParams(Parse::ParamsContext *ctx) override;
    antlrcpp::Any visitRef(Parse::RefContext *ctx) override;
    antlrcpp::Any visitRelational2Op(Parse::Relational2OpContext *ctx) override ;
    antlrcpp::Any visitNull(Parse::NullContext *ctx) override ;
    antlrcpp::Any visitUnaryOp(Parse::UnaryOpContext *ctx) override ;
//    antlrcpp::Any visitFUncCallExpr(Parse::FUncCallExprContext *ctx) override ;
    antlrcpp::Any visitRelational13Op(Parse::Relational13OpContext *ctx) override ;
    antlrcpp::Any visitLogicalOp(Parse::LogicalOpContext *ctx) override ;
//    antlrcpp::Any visitAllocateOp(Parse::AllocateOpContext *ctx) override;
    antlrcpp::Any visitConstValOp(Parse::ConstValOpContext *ctx) override;
    antlrcpp::Any visitParenthesisOp(Parse::ParenthesisOpContext *ctx) override;
    antlrcpp::Any visitBitwiseOp(Parse::BitwiseOpContext *ctx) override;

    antlrcpp::Any visitArithmetic2Op(Parse::Arithmetic2OpContext *ctx) override;

    antlrcpp::Any visitArithmetic1Op(Parse::Arithmetic1OpContext *ctx) override;

//    antlrcpp::Any visitVarExpr(Parse::VarExprContext *ctx) override;

//    antlrcpp::Any visitListExpr(Parse::ListExprContext *ctx) override;

    antlrcpp::Any visitReadFunc(Parse::ReadFuncContext *ctx) override;

    /*////////////////////////////////////////////////////////////////////*/
    void save(antlr4::ParserRuleContext *ctx, symtab::scope *scope);

    std::vector<Error> getErrors() const;

private:
    symtab::scope * currentScope;
    symtab::baseScope global;
    antlr4::tree::ParseTreeProperty<symtab::scope*> scopes;
    std::string accessModifer = "";
    std::vector<Error> errors;
};

#endif // DEFSYMBOLANDSCOPES_HPP
