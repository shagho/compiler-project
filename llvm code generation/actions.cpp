#include "actions.hpp"
#include <iostream>

actions::actions()
{

}

void actions::exitProgram(ExprParser::ProgramContext *)
{
    std::cout << code.generate() << std::endl;

}

void actions::exitVar_def(ExprParser::Var_defContext *ctx)
{
    std::string type = ctx->type()->getText();
    std::string id = ctx->var_val()[0]->ref()->getText();
    if(ctx->var_val(0)->const_val() != nullptr)
    {
        Value value = getValue(ctx->var_val(0)->const_val());
        declareVariable(id, value);
        assignVariable(id, value, ctx->getStart()->getLine(), false);
    }

    else if(ctx->var_val(0)->expr() != nullptr)
    {
        if(ctx->var_val(0)->expr()->func_call() != nullptr)
        {
            if(ctx->var_val(0)->expr()->func_call()->getText() == "read()")
            {
                if(type == "int")
                {
                    if(variables.find(id) == variables.end())
                    {
                        if(global)
                            globalNames.insert(id);
                        code.declare_i32(id, global);
                        code.scanf_i32(id, globalNames);
                        variables.insert(std::pair<std::string, Value>(id, Value(id, VarType::INT)));
                        localNames.insert(id);
//                        variables[id] = Value(id, VarType::INT);
                    }

                    else
                        code.scanf_i32(id, globalNames);
                }

                else if(type == "float")
                {
                    if(variables.find(id) == variables.end())
                    {
                        if(global)
                            globalNames.insert(id);
                        code.declare_double(id, global);
                        code.scnaf_double(id, globalNames);
                        variables.insert(std::pair<std::string, Value>(id, Value(id, VarType::FLOAT)));
                        localNames.insert(id);
//                        variables[id] = Value(id, VarType::FLOAT);
                    }

                    else
                        code.scnaf_double(id, globalNames);
                }
            }
        }
        else
        {
            Value value = mathUtils::eval(type, infixExpr, globalNames, variables, code);
            if(type == "int")
                value.type = VarType::INT;
            if(type == "float")
                value.type = VarType::FLOAT;
            declareVariable(id, value);
            assignVariable(id, value, ctx->getStart()->getLine(), true);
            while(not infixExpr.empty())
                infixExpr.pop();
        }
    }

    else
    {
        if(type == "int")
        {
            variables.insert(std::pair<std::string, Value>(id, Value(id, VarType::INT)));
            code.declare_i32(id, global);
        }
        else if(type == "float")
        {
            variables.insert(std::pair<std::string, Value>(id, Value(id, VarType::FLOAT)));
            code.declare_double(id, global);
        }
    }

}

void actions::enterFun_def(ExprParser::Fun_defContext *ctx)
{
    global = false;
    function = ctx->ID()->getText();
    code.function_start(function);
}

void actions::exitFun_def(ExprParser::Fun_defContext *)
{
    global = true;
    code.function_end();
    removeLocalVariables();
    localNames.clear();
}

void actions::exitAssign(ExprParser::AssignContext *ctx)
{
    if(ctx->const_val() != nullptr)
    {
        std::string id = ctx->var(0)->getText();
        Value value = getValue(ctx->const_val());
        assignVariable(id, value,ctx->getStart()->getLine(), false);
    }

    if(ctx->expr() != nullptr)
    {
        if(ctx->expr()->func_call()!= nullptr)
        {
            if(ctx->expr()->func_call()->getText() == "read")
            {
                VarType type = variables.at(ctx->var(0)->getText()).type;
                if(type == VarType::INT)
                    code.scanf_i32(ctx->var(0)->getText(), globalNames);

                else if(type == VarType::FLOAT)
                    code.scnaf_double(ctx->var(0)->getText(), globalNames);
            }
        }
        else
        {
            std::string id = ctx->var(0)->getText();
            VarType type = variables.at(ctx->var(0)->getText()).type;
            std::string types = type == VarType::INT ? "int":"float";
            Value value = mathUtils::eval(types, infixExpr, globalNames, variables, code);
            assignVariable(id, value, ctx->getStart()->getLine(), true);
            while(not infixExpr.empty())
                infixExpr.pop();
        }
    }
}

void actions::enterEx(ExprParser::ExContext *)
{
    infixExpr.push("(");
}

void actions::exitEx(ExprParser::ExContext *)
{
    infixExpr.push(")");
}

void actions::exitIdentifier(ExprParser::IdentifierContext *ctx)
{
    infixExpr.push(ctx->getText());
}

void actions::exitCall(ExprParser::CallContext * ctx)
{
    code.call(ctx->handle_call()->ID()->getText());
}

void actions::exitWrite_atr(ExprParser::Write_atrContext *ctx)
{
    std::string id = ctx->const_val()->getText();
    if(variables.find(id) != variables.end())
        printVariable(id);
    else
        printConstant(ctx->const_val());
}

void actions::exitI_const(ExprParser::I_constContext *ctx)
{
    infixExpr.push(ctx->getText());
}

void actions::exitF_const(ExprParser::F_constContext *ctx)
{
    infixExpr.push(ctx->getText());
}

void actions::exitArithmetic1(ExprParser::Arithmetic1Context *ctx)
{
    infixExpr.push(ctx->getText());
}

void actions::exitArithmetic2(ExprParser::Arithmetic2Context *ctx)
{
    infixExpr.push(ctx->getText());
}

void actions::enterStart_func(ExprParser::Start_funcContext *)
{
    global = false;
    code.main_reg = code.reg;
    code.reg = 1;
    code.buffer = "";
}

void actions::exitStart_func(ExprParser::Start_funcContext *)
{
    global = true;
    code.formatBuffer();
    code.main_text += code.buffer;
    code.buffer = "";
    code.reg = code.main_reg;
    removeLocalVariables();
    localNames.clear();
}

Value  actions::getValue(ExprParser::Const_valContext *ctx)
{
    if(ctx->Int_const() != nullptr)
        return Value(ctx->Int_const()->getText(), VarType::INT);
    else if (ctx->Float_const() != nullptr)
        return Value(ctx->Float_const()->getText(), VarType::FLOAT);
    else if(ctx->String_const() != nullptr)
        return Value(getTextWithoutQuotes(ctx), VarType::STRING);
    else
    {
        if(variables.find(ctx->ID()->getText()) != variables.end())
        {
            Value declare = variables.at(ctx->ID()->getText());
            return declare;
        }
    }
    error(ctx->getStart()->getLine(), "Invalid value");
}

void actions::declareVariable(std::string ID, Value value)
{
    if(variables.find(ID) == variables.end())
    {
        if(value.type != VarType::STRING)
            variables.insert(std::pair<std::string, Value>(ID, value));
        if(value.type == VarType::INT)
            code.declare_i32(ID, global);
        else if (value.type == VarType::FLOAT)
            code.declare_double(ID, global);
    }
}

void actions::assignVariable(std::string ID, Value value, int line, bool isMathExpr)
{
    if(global)
        globalNames.insert(ID);
    else if(globalNames.find(ID) == globalNames.end())
        localNames.insert(ID);

    if(value.type == VarType::INT)
        code.assign_i32(ID, getValue(value, isMathExpr),&globalNames);
    else if(value.type == VarType::FLOAT)
        code.assign_double(ID, getValue(value, isMathExpr), &globalNames);
    else if(value.type == VarType::STRING)
        assignString(ID, value, line);
    else
        error(line, "Assign error " + ID);
}

std::string actions::getValue(Value value, bool isMathExpr)
{
    if(isMathExpr)
        return value.content;
    if(mathUtils::isNumeric(value.content))
        return value.content;
    else
    {
        if(value.type == VarType::FLOAT)
            code.load_double(value.content, globalNames);
        else
            code.load_i32(value.content, globalNames);
        return "%" + std::to_string(code.reg - 1);
    }
}

void actions::assignString(std::string id, Value value, int line)
{
    if(variables.find(id) == variables.end())
    {
        code.assign_string(id, value.content, global, function);
        variables.insert(std::pair<std::string, Value>(id, value));
    }
    else
        error(line, id + "is constant value.");
}

void actions::printConstant(ExprParser::Const_valContext *ctx)
{
    if(ctx->String_const() != nullptr)
        code.print(getTextWithoutQuotes(ctx));
    else
        code.print(ctx->getText());
}

void actions::printVariable(std::string ID)
{
    if(variables.at(ID).type == VarType::INT)
        code.printf_i32(ID, globalNames);
    else if(variables.at(ID).type == VarType::FLOAT)
        code.printf_double(ID, globalNames);
    else if(variables.at(ID).type == VarType::STRING)
        code.printf_string(ID, variables.at(ID).content.size(), globalNames, function);
}

std::string actions::getTextWithoutQuotes(ExprParser::Const_valContext *ctx)
{
    std::string text = ctx->String_const()->getText();
    return text.substr(1, text.size() - 1);
}

void actions::removeLocalVariables()
{
    for(std::string id : localNames)
    {
        variables.erase(id);
    }
}

void actions::error(int line, std::string msg)
{
    std::cout << "Error, line " + std::to_string(line) + ", " + msg << std::endl;
    exit(1);
}


