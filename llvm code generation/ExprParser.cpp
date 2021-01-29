
// Generated from /home/navid/Compiler_project/Expr.g4 by ANTLR 4.8


#include "ExprListener.h"
#include "ExprVisitor.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

ExprParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Start_funcContext* ExprParser::ProgramContext::start_func() {
  return getRuleContext<ExprParser::Start_funcContext>(0);
}

std::vector<ExprParser::Ft_defContext *> ExprParser::ProgramContext::ft_def() {
  return getRuleContexts<ExprParser::Ft_defContext>();
}

ExprParser::Ft_defContext* ExprParser::ProgramContext::ft_def(size_t i) {
  return getRuleContext<ExprParser::Ft_defContext>(i);
}


size_t ExprParser::ProgramContext::getRuleIndex() const {
  return ExprParser::RuleProgram;
}

void ExprParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void ExprParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any ExprParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProgramContext* ExprParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(52);
        ft_def();
      }
      setState(57);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(58);
    start_func();
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__0

    || _la == ExprParser::Function) {
      setState(59);
      ft_def();
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Start_funcContext ------------------------------------------------------------------

ExprParser::Start_funcContext::Start_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Start_funcContext::Int() {
  return getToken(ExprParser::Int, 0);
}

tree::TerminalNode* ExprParser::Start_funcContext::ID() {
  return getToken(ExprParser::ID, 0);
}

tree::TerminalNode* ExprParser::Start_funcContext::Function() {
  return getToken(ExprParser::Function, 0);
}

ExprParser::StartContext* ExprParser::Start_funcContext::start() {
  return getRuleContext<ExprParser::StartContext>(0);
}

ExprParser::BlockContext* ExprParser::Start_funcContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}


size_t ExprParser::Start_funcContext::getRuleIndex() const {
  return ExprParser::RuleStart_func;
}

void ExprParser::Start_funcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart_func(this);
}

void ExprParser::Start_funcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart_func(this);
}


antlrcpp::Any ExprParser::Start_funcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStart_func(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Start_funcContext* ExprParser::start_func() {
  Start_funcContext *_localctx = _tracker.createInstance<Start_funcContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleStart_func);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(ExprParser::T__0);
    setState(66);
    match(ExprParser::Int);
    setState(67);
    match(ExprParser::ID);
    setState(68);
    match(ExprParser::T__1);
    setState(69);
    match(ExprParser::T__2);
    setState(70);
    match(ExprParser::Function);
    setState(71);
    start();
    setState(72);
    match(ExprParser::T__0);
    setState(73);
    match(ExprParser::T__1);
    setState(74);
    block();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ft_defContext ------------------------------------------------------------------

ExprParser::Ft_defContext::Ft_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Fun_defContext* ExprParser::Ft_defContext::fun_def() {
  return getRuleContext<ExprParser::Fun_defContext>(0);
}


size_t ExprParser::Ft_defContext::getRuleIndex() const {
  return ExprParser::RuleFt_def;
}

void ExprParser::Ft_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFt_def(this);
}

void ExprParser::Ft_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFt_def(this);
}


antlrcpp::Any ExprParser::Ft_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFt_def(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Ft_defContext* ExprParser::ft_def() {
  Ft_defContext *_localctx = _tracker.createInstance<Ft_defContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleFt_def);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    fun_def();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_defContext ------------------------------------------------------------------

ExprParser::Var_defContext::Var_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::TypeContext* ExprParser::Var_defContext::type() {
  return getRuleContext<ExprParser::TypeContext>(0);
}

std::vector<ExprParser::Var_valContext *> ExprParser::Var_defContext::var_val() {
  return getRuleContexts<ExprParser::Var_valContext>();
}

ExprParser::Var_valContext* ExprParser::Var_defContext::var_val(size_t i) {
  return getRuleContext<ExprParser::Var_valContext>(i);
}

tree::TerminalNode* ExprParser::Var_defContext::Const() {
  return getToken(ExprParser::Const, 0);
}


size_t ExprParser::Var_defContext::getRuleIndex() const {
  return ExprParser::RuleVar_def;
}

void ExprParser::Var_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_def(this);
}

void ExprParser::Var_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_def(this);
}


antlrcpp::Any ExprParser::Var_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVar_def(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Var_defContext* ExprParser::var_def() {
  Var_defContext *_localctx = _tracker.createInstance<Var_defContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleVar_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::Const) {
      setState(78);
      match(ExprParser::Const);
    }
    setState(81);
    type();
    setState(82);
    var_val();
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__3) {
      setState(83);
      match(ExprParser::T__3);
      setState(84);
      var_val();
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    match(ExprParser::T__4);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

ExprParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::TypeContext::Int() {
  return getToken(ExprParser::Int, 0);
}

tree::TerminalNode* ExprParser::TypeContext::Bool() {
  return getToken(ExprParser::Bool, 0);
}

tree::TerminalNode* ExprParser::TypeContext::Float() {
  return getToken(ExprParser::Float, 0);
}

tree::TerminalNode* ExprParser::TypeContext::String() {
  return getToken(ExprParser::String, 0);
}

tree::TerminalNode* ExprParser::TypeContext::ID() {
  return getToken(ExprParser::ID, 0);
}


size_t ExprParser::TypeContext::getRuleIndex() const {
  return ExprParser::RuleType;
}

void ExprParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void ExprParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any ExprParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TypeContext* ExprParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 8, ExprParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::Bool)
      | (1ULL << ExprParser::Float)
      | (1ULL << ExprParser::Int)
      | (1ULL << ExprParser::String)
      | (1ULL << ExprParser::ID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_valContext ------------------------------------------------------------------

ExprParser::Var_valContext::Var_valContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::RefContext* ExprParser::Var_valContext::ref() {
  return getRuleContext<ExprParser::RefContext>(0);
}

ExprParser::Const_valContext* ExprParser::Var_valContext::const_val() {
  return getRuleContext<ExprParser::Const_valContext>(0);
}

ExprParser::ExprContext* ExprParser::Var_valContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}


size_t ExprParser::Var_valContext::getRuleIndex() const {
  return ExprParser::RuleVar_val;
}

void ExprParser::Var_valContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_val(this);
}

void ExprParser::Var_valContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_val(this);
}


antlrcpp::Any ExprParser::Var_valContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVar_val(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Var_valContext* ExprParser::var_val() {
  Var_valContext *_localctx = _tracker.createInstance<Var_valContext>(_ctx, getState());
  enterRule(_localctx, 10, ExprParser::RuleVar_val);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    ref();
    setState(100);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::T__2) {
      setState(95);
      match(ExprParser::T__2);
      setState(98);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(96);
        const_val();
        break;
      }

      case 2: {
        setState(97);
        expr();
        break;
      }

      }
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_defContext ------------------------------------------------------------------

ExprParser::Fun_defContext::Fun_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Fun_defContext::Function() {
  return getToken(ExprParser::Function, 0);
}

tree::TerminalNode* ExprParser::Fun_defContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::BlockContext* ExprParser::Fun_defContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

std::vector<ExprParser::Args_varContext *> ExprParser::Fun_defContext::args_var() {
  return getRuleContexts<ExprParser::Args_varContext>();
}

ExprParser::Args_varContext* ExprParser::Fun_defContext::args_var(size_t i) {
  return getRuleContext<ExprParser::Args_varContext>(i);
}


size_t ExprParser::Fun_defContext::getRuleIndex() const {
  return ExprParser::RuleFun_def;
}

void ExprParser::Fun_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFun_def(this);
}

void ExprParser::Fun_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFun_def(this);
}


antlrcpp::Any ExprParser::Fun_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFun_def(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Fun_defContext* ExprParser::fun_def() {
  Fun_defContext *_localctx = _tracker.createInstance<Fun_defContext>(_ctx, getState());
  enterRule(_localctx, 12, ExprParser::RuleFun_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::T__0) {
      setState(102);
      match(ExprParser::T__0);
      setState(103);
      args_var(0);
      setState(104);
      match(ExprParser::T__1);
      setState(105);
      match(ExprParser::T__2);
    }
    setState(109);
    match(ExprParser::Function);
    setState(110);
    match(ExprParser::ID);
    setState(111);
    match(ExprParser::T__0);
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::Bool)
      | (1ULL << ExprParser::Float)
      | (1ULL << ExprParser::Int)
      | (1ULL << ExprParser::String)
      | (1ULL << ExprParser::ID))) != 0)) {
      setState(112);
      args_var(0);
    }
    setState(115);
    match(ExprParser::T__1);
    setState(116);
    block();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Args_varContext ------------------------------------------------------------------

ExprParser::Args_varContext::Args_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::TypeContext* ExprParser::Args_varContext::type() {
  return getRuleContext<ExprParser::TypeContext>(0);
}

tree::TerminalNode* ExprParser::Args_varContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::Args_varContext* ExprParser::Args_varContext::args_var() {
  return getRuleContext<ExprParser::Args_varContext>(0);
}


size_t ExprParser::Args_varContext::getRuleIndex() const {
  return ExprParser::RuleArgs_var;
}

void ExprParser::Args_varContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgs_var(this);
}

void ExprParser::Args_varContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgs_var(this);
}


antlrcpp::Any ExprParser::Args_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArgs_var(this);
  else
    return visitor->visitChildren(this);
}


ExprParser::Args_varContext* ExprParser::args_var() {
   return args_var(0);
}

ExprParser::Args_varContext* ExprParser::args_var(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::Args_varContext *_localctx = _tracker.createInstance<Args_varContext>(_ctx, parentState);
  ExprParser::Args_varContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, ExprParser::RuleArgs_var, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(119);
    type();
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__5) {
      setState(120);
      match(ExprParser::T__5);
      setState(121);
      match(ExprParser::T__6);
      setState(126);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(127);
    match(ExprParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(143);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Args_varContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgs_var);
        setState(129);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(130);
        match(ExprParser::T__3);
        setState(131);
        type();
        setState(136);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ExprParser::T__5) {
          setState(132);
          match(ExprParser::T__5);
          setState(133);
          match(ExprParser::T__6);
          setState(138);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(139);
        match(ExprParser::ID);
      }
      setState(145);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ExprParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Var_defContext *> ExprParser::BlockContext::var_def() {
  return getRuleContexts<ExprParser::Var_defContext>();
}

ExprParser::Var_defContext* ExprParser::BlockContext::var_def(size_t i) {
  return getRuleContext<ExprParser::Var_defContext>(i);
}

std::vector<ExprParser::StmtContext *> ExprParser::BlockContext::stmt() {
  return getRuleContexts<ExprParser::StmtContext>();
}

ExprParser::StmtContext* ExprParser::BlockContext::stmt(size_t i) {
  return getRuleContext<ExprParser::StmtContext>(i);
}


size_t ExprParser::BlockContext::getRuleIndex() const {
  return ExprParser::RuleBlock;
}

void ExprParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void ExprParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any ExprParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::BlockContext* ExprParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 16, ExprParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(ExprParser::T__7);
    setState(151);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__0)
      | (1ULL << ExprParser::Bool)
      | (1ULL << ExprParser::Break)
      | (1ULL << ExprParser::Const)
      | (1ULL << ExprParser::Continue)
      | (1ULL << ExprParser::Float)
      | (1ULL << ExprParser::For)
      | (1ULL << ExprParser::If)
      | (1ULL << ExprParser::Int)
      | (1ULL << ExprParser::Read)
      | (1ULL << ExprParser::String)
      | (1ULL << ExprParser::Switch)
      | (1ULL << ExprParser::While)
      | (1ULL << ExprParser::Write)
      | (1ULL << ExprParser::ID))) != 0)) {
      setState(149);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
      case 1: {
        setState(147);
        var_def();
        break;
      }

      case 2: {
        setState(148);
        stmt();
        break;
      }

      }
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(154);
    match(ExprParser::T__8);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

ExprParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::AssignContext* ExprParser::StmtContext::assign() {
  return getRuleContext<ExprParser::AssignContext>(0);
}

ExprParser::Func_callContext* ExprParser::StmtContext::func_call() {
  return getRuleContext<ExprParser::Func_callContext>(0);
}

ExprParser::Cond_stmtContext* ExprParser::StmtContext::cond_stmt() {
  return getRuleContext<ExprParser::Cond_stmtContext>(0);
}

ExprParser::Loop_stmtContext* ExprParser::StmtContext::loop_stmt() {
  return getRuleContext<ExprParser::Loop_stmtContext>(0);
}

tree::TerminalNode* ExprParser::StmtContext::Break() {
  return getToken(ExprParser::Break, 0);
}

tree::TerminalNode* ExprParser::StmtContext::Continue() {
  return getToken(ExprParser::Continue, 0);
}


size_t ExprParser::StmtContext::getRuleIndex() const {
  return ExprParser::RuleStmt;
}

void ExprParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void ExprParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any ExprParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::StmtContext* ExprParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 18, ExprParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(156);
      assign();
      setState(157);
      match(ExprParser::T__4);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(159);
      func_call();
      setState(160);
      match(ExprParser::T__4);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(162);
      cond_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(163);
      loop_stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(164);
      match(ExprParser::Break);
      setState(165);
      match(ExprParser::T__4);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(166);
      match(ExprParser::Continue);
      setState(167);
      match(ExprParser::T__4);
      break;
    }

    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

ExprParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::VarContext *> ExprParser::AssignContext::var() {
  return getRuleContexts<ExprParser::VarContext>();
}

ExprParser::VarContext* ExprParser::AssignContext::var(size_t i) {
  return getRuleContext<ExprParser::VarContext>(i);
}

ExprParser::Const_valContext* ExprParser::AssignContext::const_val() {
  return getRuleContext<ExprParser::Const_valContext>(0);
}

ExprParser::ExprContext* ExprParser::AssignContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}


size_t ExprParser::AssignContext::getRuleIndex() const {
  return ExprParser::RuleAssign;
}

void ExprParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void ExprParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


antlrcpp::Any ExprParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::AssignContext* ExprParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 20, ExprParser::RuleAssign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::ID: {
        setState(170);
        var();
        break;
      }

      case ExprParser::T__0: {
        setState(171);
        match(ExprParser::T__0);
        setState(172);
        var();
        setState(177);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ExprParser::T__3) {
          setState(173);
          match(ExprParser::T__3);
          setState(174);
          var();
          setState(179);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(180);
        match(ExprParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(184);
    match(ExprParser::T__2);
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(185);
      const_val();
      break;
    }

    case 2: {
      setState(186);
      expr();
      break;
    }

    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

ExprParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::RefContext *> ExprParser::VarContext::ref() {
  return getRuleContexts<ExprParser::RefContext>();
}

ExprParser::RefContext* ExprParser::VarContext::ref(size_t i) {
  return getRuleContext<ExprParser::RefContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::VarContext::Dot() {
  return getTokens(ExprParser::Dot);
}

tree::TerminalNode* ExprParser::VarContext::Dot(size_t i) {
  return getToken(ExprParser::Dot, i);
}


size_t ExprParser::VarContext::getRuleIndex() const {
  return ExprParser::RuleVar;
}

void ExprParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void ExprParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


antlrcpp::Any ExprParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::VarContext* ExprParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 22, ExprParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(189);
    ref();
    setState(194);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(190);
        match(ExprParser::Dot);
        setState(191);
        ref();
      }
      setState(196);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RefContext ------------------------------------------------------------------

ExprParser::RefContext::RefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::RefContext::ID() {
  return getToken(ExprParser::ID, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::RefContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::RefContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}


size_t ExprParser::RefContext::getRuleIndex() const {
  return ExprParser::RuleRef;
}

void ExprParser::RefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRef(this);
}

void ExprParser::RefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRef(this);
}


antlrcpp::Any ExprParser::RefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRef(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::RefContext* ExprParser::ref() {
  RefContext *_localctx = _tracker.createInstance<RefContext>(_ctx, getState());
  enterRule(_localctx, 24, ExprParser::RuleRef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    match(ExprParser::ID);
    setState(204);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__5) {
      setState(198);
      match(ExprParser::T__5);
      setState(199);
      expr();
      setState(200);
      match(ExprParser::T__6);
      setState(206);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::TermContext *> ExprParser::ExprContext::term() {
  return getRuleContexts<ExprParser::TermContext>();
}

ExprParser::TermContext* ExprParser::ExprContext::term(size_t i) {
  return getRuleContext<ExprParser::TermContext>(i);
}

std::vector<ExprParser::Arithmetic2Context *> ExprParser::ExprContext::arithmetic2() {
  return getRuleContexts<ExprParser::Arithmetic2Context>();
}

ExprParser::Arithmetic2Context* ExprParser::ExprContext::arithmetic2(size_t i) {
  return getRuleContext<ExprParser::Arithmetic2Context>(i);
}

ExprParser::Func_callContext* ExprParser::ExprContext::func_call() {
  return getRuleContext<ExprParser::Func_callContext>(0);
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ExprParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any ExprParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExprContext* ExprParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 26, ExprParser::RuleExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(217);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(207);
      term();
      setState(213);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::T__13

      || _la == ExprParser::T__14) {
        setState(208);
        arithmetic2();
        setState(209);
        term();
        setState(215);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(216);
      func_call();
      break;
    }

    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

ExprParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::FactorContext *> ExprParser::TermContext::factor() {
  return getRuleContexts<ExprParser::FactorContext>();
}

ExprParser::FactorContext* ExprParser::TermContext::factor(size_t i) {
  return getRuleContext<ExprParser::FactorContext>(i);
}

std::vector<ExprParser::Arithmetic1Context *> ExprParser::TermContext::arithmetic1() {
  return getRuleContexts<ExprParser::Arithmetic1Context>();
}

ExprParser::Arithmetic1Context* ExprParser::TermContext::arithmetic1(size_t i) {
  return getRuleContext<ExprParser::Arithmetic1Context>(i);
}


size_t ExprParser::TermContext::getRuleIndex() const {
  return ExprParser::RuleTerm;
}

void ExprParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void ExprParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


antlrcpp::Any ExprParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TermContext* ExprParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 28, ExprParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    factor();
    setState(225);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__10)
      | (1ULL << ExprParser::T__11)
      | (1ULL << ExprParser::T__12))) != 0)) {
      setState(220);
      arithmetic1();
      setState(221);
      factor();
      setState(227);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

ExprParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::FactorContext::getRuleIndex() const {
  return ExprParser::RuleFactor;
}

void ExprParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::ExContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ExContext::ExContext(FactorContext *ctx) { copyFrom(ctx); }

void ExprParser::ExContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEx(this);
}
void ExprParser::ExContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEx(this);
}

antlrcpp::Any ExprParser::ExContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitEx(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::IdentifierContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::IdentifierContext::IdentifierContext(FactorContext *ctx) { copyFrom(ctx); }

void ExprParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}
void ExprParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}

antlrcpp::Any ExprParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- I_constContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::I_constContext::Int_const() {
  return getToken(ExprParser::Int_const, 0);
}

ExprParser::I_constContext::I_constContext(FactorContext *ctx) { copyFrom(ctx); }

void ExprParser::I_constContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterI_const(this);
}
void ExprParser::I_constContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitI_const(this);
}

antlrcpp::Any ExprParser::I_constContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitI_const(this);
  else
    return visitor->visitChildren(this);
}
//----------------- F_constContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::F_constContext::Float_const() {
  return getToken(ExprParser::Float_const, 0);
}

ExprParser::F_constContext::F_constContext(FactorContext *ctx) { copyFrom(ctx); }

void ExprParser::F_constContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterF_const(this);
}
void ExprParser::F_constContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitF_const(this);
}

antlrcpp::Any ExprParser::F_constContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitF_const(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::FactorContext* ExprParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 30, ExprParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(235);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::T__0: {
        _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ExprParser::ExContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(228);
        match(ExprParser::T__0);
        setState(229);
        expr();
        setState(230);
        match(ExprParser::T__1);
        break;
      }

      case ExprParser::Int_const: {
        _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ExprParser::I_constContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(232);
        match(ExprParser::Int_const);
        break;
      }

      case ExprParser::Float_const: {
        _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ExprParser::F_constContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(233);
        match(ExprParser::Float_const);
        break;
      }

      case ExprParser::ID: {
        _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<ExprParser::IdentifierContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(234);
        match(ExprParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_callContext ------------------------------------------------------------------

ExprParser::Func_callContext::Func_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::Func_callContext::getRuleIndex() const {
  return ExprParser::RuleFunc_call;
}

void ExprParser::Func_callContext::copyFrom(Func_callContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext ------------------------------------------------------------------

ExprParser::Handle_callContext* ExprParser::CallContext::handle_call() {
  return getRuleContext<ExprParser::Handle_callContext>(0);
}

ExprParser::VarContext* ExprParser::CallContext::var() {
  return getRuleContext<ExprParser::VarContext>(0);
}

tree::TerminalNode* ExprParser::CallContext::Dot() {
  return getToken(ExprParser::Dot, 0);
}

ExprParser::CallContext::CallContext(Func_callContext *ctx) { copyFrom(ctx); }

void ExprParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void ExprParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

antlrcpp::Any ExprParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Write_atrContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::Write_atrContext::Write() {
  return getToken(ExprParser::Write, 0);
}

ExprParser::Const_valContext* ExprParser::Write_atrContext::const_val() {
  return getRuleContext<ExprParser::Const_valContext>(0);
}

ExprParser::Write_atrContext::Write_atrContext(Func_callContext *ctx) { copyFrom(ctx); }

void ExprParser::Write_atrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWrite_atr(this);
}
void ExprParser::Write_atrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWrite_atr(this);
}

antlrcpp::Any ExprParser::Write_atrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitWrite_atr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Read_atrContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::Read_atrContext::Read() {
  return getToken(ExprParser::Read, 0);
}

ExprParser::Read_atrContext::Read_atrContext(Func_callContext *ctx) { copyFrom(ctx); }

void ExprParser::Read_atrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRead_atr(this);
}
void ExprParser::Read_atrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRead_atr(this);
}

antlrcpp::Any ExprParser::Read_atrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRead_atr(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::Func_callContext* ExprParser::func_call() {
  Func_callContext *_localctx = _tracker.createInstance<Func_callContext>(_ctx, getState());
  enterRule(_localctx, 32, ExprParser::RuleFunc_call);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(251);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::ID: {
        _localctx = dynamic_cast<Func_callContext *>(_tracker.createInstance<ExprParser::CallContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(240);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          setState(237);
          var();
          setState(238);
          match(ExprParser::Dot);
          break;
        }

        }
        setState(242);
        handle_call();
        break;
      }

      case ExprParser::Read: {
        _localctx = dynamic_cast<Func_callContext *>(_tracker.createInstance<ExprParser::Read_atrContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(243);
        match(ExprParser::Read);
        setState(244);
        match(ExprParser::T__0);
        setState(245);
        match(ExprParser::T__1);
        break;
      }

      case ExprParser::Write: {
        _localctx = dynamic_cast<Func_callContext *>(_tracker.createInstance<ExprParser::Write_atrContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(246);
        match(ExprParser::Write);
        setState(247);
        match(ExprParser::T__0);
        setState(248);
        const_val();
        setState(249);
        match(ExprParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Handle_callContext ------------------------------------------------------------------

ExprParser::Handle_callContext::Handle_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Handle_callContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::ParamsContext* ExprParser::Handle_callContext::params() {
  return getRuleContext<ExprParser::ParamsContext>(0);
}


size_t ExprParser::Handle_callContext::getRuleIndex() const {
  return ExprParser::RuleHandle_call;
}

void ExprParser::Handle_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHandle_call(this);
}

void ExprParser::Handle_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHandle_call(this);
}


antlrcpp::Any ExprParser::Handle_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitHandle_call(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Handle_callContext* ExprParser::handle_call() {
  Handle_callContext *_localctx = _tracker.createInstance<Handle_callContext>(_ctx, getState());
  enterRule(_localctx, 34, ExprParser::RuleHandle_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(ExprParser::ID);
    setState(254);
    match(ExprParser::T__0);
    setState(256);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__0)
      | (1ULL << ExprParser::Read)
      | (1ULL << ExprParser::Write)
      | (1ULL << ExprParser::Int_const)
      | (1ULL << ExprParser::Float_const)
      | (1ULL << ExprParser::ID))) != 0)) {
      setState(255);
      params();
    }
    setState(258);
    match(ExprParser::T__1);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

ExprParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ExprContext* ExprParser::ParamsContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ParamsContext* ExprParser::ParamsContext::params() {
  return getRuleContext<ExprParser::ParamsContext>(0);
}


size_t ExprParser::ParamsContext::getRuleIndex() const {
  return ExprParser::RuleParams;
}

void ExprParser::ParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams(this);
}

void ExprParser::ParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams(this);
}


antlrcpp::Any ExprParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ParamsContext* ExprParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 36, ExprParser::RuleParams);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(265);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(260);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(261);
      expr();
      setState(262);
      match(ExprParser::T__3);
      setState(263);
      params();
      break;
    }

    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_stmtContext ------------------------------------------------------------------

ExprParser::Cond_stmtContext::Cond_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Cond_stmtContext::If() {
  return getToken(ExprParser::If, 0);
}

ExprParser::ExprContext* ExprParser::Cond_stmtContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

std::vector<ExprParser::BlockContext *> ExprParser::Cond_stmtContext::block() {
  return getRuleContexts<ExprParser::BlockContext>();
}

ExprParser::BlockContext* ExprParser::Cond_stmtContext::block(size_t i) {
  return getRuleContext<ExprParser::BlockContext>(i);
}

std::vector<ExprParser::StmtContext *> ExprParser::Cond_stmtContext::stmt() {
  return getRuleContexts<ExprParser::StmtContext>();
}

ExprParser::StmtContext* ExprParser::Cond_stmtContext::stmt(size_t i) {
  return getRuleContext<ExprParser::StmtContext>(i);
}

tree::TerminalNode* ExprParser::Cond_stmtContext::Else() {
  return getToken(ExprParser::Else, 0);
}

tree::TerminalNode* ExprParser::Cond_stmtContext::Switch() {
  return getToken(ExprParser::Switch, 0);
}

ExprParser::VarContext* ExprParser::Cond_stmtContext::var() {
  return getRuleContext<ExprParser::VarContext>(0);
}

ExprParser::Switch_bodyContext* ExprParser::Cond_stmtContext::switch_body() {
  return getRuleContext<ExprParser::Switch_bodyContext>(0);
}


size_t ExprParser::Cond_stmtContext::getRuleIndex() const {
  return ExprParser::RuleCond_stmt;
}

void ExprParser::Cond_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond_stmt(this);
}

void ExprParser::Cond_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond_stmt(this);
}


antlrcpp::Any ExprParser::Cond_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCond_stmt(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Cond_stmtContext* ExprParser::cond_stmt() {
  Cond_stmtContext *_localctx = _tracker.createInstance<Cond_stmtContext>(_ctx, getState());
  enterRule(_localctx, 38, ExprParser::RuleCond_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(267);
        match(ExprParser::If);
        setState(268);
        expr();
        setState(271);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case ExprParser::T__7: {
            setState(269);
            block();
            break;
          }

          case ExprParser::T__0:
          case ExprParser::Break:
          case ExprParser::Continue:
          case ExprParser::For:
          case ExprParser::If:
          case ExprParser::Read:
          case ExprParser::Switch:
          case ExprParser::While:
          case ExprParser::Write:
          case ExprParser::ID: {
            setState(270);
            stmt();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(278);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
        case 1: {
          setState(273);
          match(ExprParser::Else);
          setState(276);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case ExprParser::T__7: {
              setState(274);
              block();
              break;
            }

            case ExprParser::T__0:
            case ExprParser::Break:
            case ExprParser::Continue:
            case ExprParser::For:
            case ExprParser::If:
            case ExprParser::Read:
            case ExprParser::Switch:
            case ExprParser::While:
            case ExprParser::Write:
            case ExprParser::ID: {
              setState(275);
              stmt();
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          break;
        }

        }
        break;
      }

      case ExprParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(280);
        match(ExprParser::Switch);
        setState(281);
        var();
        setState(282);
        match(ExprParser::T__7);
        setState(283);
        switch_body();
        setState(284);
        match(ExprParser::T__8);
        break;
      }

    default:
      throw NoViableAltException(this);
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_bodyContext ------------------------------------------------------------------

ExprParser::Switch_bodyContext::Switch_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ExprParser::Switch_bodyContext::Caseof() {
  return getTokens(ExprParser::Caseof);
}

tree::TerminalNode* ExprParser::Switch_bodyContext::Caseof(size_t i) {
  return getToken(ExprParser::Caseof, i);
}

std::vector<tree::TerminalNode *> ExprParser::Switch_bodyContext::Int_const() {
  return getTokens(ExprParser::Int_const);
}

tree::TerminalNode* ExprParser::Switch_bodyContext::Int_const(size_t i) {
  return getToken(ExprParser::Int_const, i);
}

std::vector<ExprParser::BlockContext *> ExprParser::Switch_bodyContext::block() {
  return getRuleContexts<ExprParser::BlockContext>();
}

ExprParser::BlockContext* ExprParser::Switch_bodyContext::block(size_t i) {
  return getRuleContext<ExprParser::BlockContext>(i);
}

tree::TerminalNode* ExprParser::Switch_bodyContext::Default() {
  return getToken(ExprParser::Default, 0);
}


size_t ExprParser::Switch_bodyContext::getRuleIndex() const {
  return ExprParser::RuleSwitch_body;
}

void ExprParser::Switch_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch_body(this);
}

void ExprParser::Switch_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch_body(this);
}


antlrcpp::Any ExprParser::Switch_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSwitch_body(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Switch_bodyContext* ExprParser::switch_body() {
  Switch_bodyContext *_localctx = _tracker.createInstance<Switch_bodyContext>(_ctx, getState());
  enterRule(_localctx, 40, ExprParser::RuleSwitch_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(288);
      match(ExprParser::Caseof);
      setState(289);
      match(ExprParser::Int_const);
      setState(290);
      match(ExprParser::T__9);
      setState(291);
      block();
      setState(294);
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ExprParser::Caseof);
    setState(299);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::Default) {
      setState(296);
      match(ExprParser::Default);
      setState(297);
      match(ExprParser::T__9);
      setState(298);
      block();
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Loop_stmtContext ------------------------------------------------------------------

ExprParser::Loop_stmtContext::Loop_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Loop_stmtContext::For() {
  return getToken(ExprParser::For, 0);
}

ExprParser::ExprContext* ExprParser::Loop_stmtContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::BlockContext* ExprParser::Loop_stmtContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

std::vector<ExprParser::AssignContext *> ExprParser::Loop_stmtContext::assign() {
  return getRuleContexts<ExprParser::AssignContext>();
}

ExprParser::AssignContext* ExprParser::Loop_stmtContext::assign(size_t i) {
  return getRuleContext<ExprParser::AssignContext>(i);
}

ExprParser::TypeContext* ExprParser::Loop_stmtContext::type() {
  return getRuleContext<ExprParser::TypeContext>(0);
}

tree::TerminalNode* ExprParser::Loop_stmtContext::While() {
  return getToken(ExprParser::While, 0);
}

ExprParser::StmtContext* ExprParser::Loop_stmtContext::stmt() {
  return getRuleContext<ExprParser::StmtContext>(0);
}


size_t ExprParser::Loop_stmtContext::getRuleIndex() const {
  return ExprParser::RuleLoop_stmt;
}

void ExprParser::Loop_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoop_stmt(this);
}

void ExprParser::Loop_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoop_stmt(this);
}


antlrcpp::Any ExprParser::Loop_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLoop_stmt(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Loop_stmtContext* ExprParser::loop_stmt() {
  Loop_stmtContext *_localctx = _tracker.createInstance<Loop_stmtContext>(_ctx, getState());
  enterRule(_localctx, 42, ExprParser::RuleLoop_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::For: {
        enterOuterAlt(_localctx, 1);
        setState(301);
        match(ExprParser::For);
        setState(306);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << ExprParser::T__0)
          | (1ULL << ExprParser::Bool)
          | (1ULL << ExprParser::Float)
          | (1ULL << ExprParser::Int)
          | (1ULL << ExprParser::String)
          | (1ULL << ExprParser::ID))) != 0)) {
          setState(303);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
          case 1: {
            setState(302);
            type();
            break;
          }

          }
          setState(305);
          assign();
        }
        setState(308);
        match(ExprParser::T__4);
        setState(309);
        expr();
        setState(310);
        match(ExprParser::T__4);
        setState(312);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ExprParser::T__0

        || _la == ExprParser::ID) {
          setState(311);
          assign();
        }
        setState(314);
        block();
        break;
      }

      case ExprParser::While: {
        enterOuterAlt(_localctx, 2);
        setState(316);
        match(ExprParser::While);
        setState(317);
        expr();
        setState(320);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case ExprParser::T__7: {
            setState(318);
            block();
            break;
          }

          case ExprParser::T__0:
          case ExprParser::Break:
          case ExprParser::Continue:
          case ExprParser::For:
          case ExprParser::If:
          case ExprParser::Read:
          case ExprParser::Switch:
          case ExprParser::While:
          case ExprParser::Write:
          case ExprParser::ID: {
            setState(319);
            stmt();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_valContext ------------------------------------------------------------------

ExprParser::Const_valContext::Const_valContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Const_valContext::ID() {
  return getToken(ExprParser::ID, 0);
}

tree::TerminalNode* ExprParser::Const_valContext::Int_const() {
  return getToken(ExprParser::Int_const, 0);
}

tree::TerminalNode* ExprParser::Const_valContext::Float_const() {
  return getToken(ExprParser::Float_const, 0);
}

tree::TerminalNode* ExprParser::Const_valContext::String_const() {
  return getToken(ExprParser::String_const, 0);
}

tree::TerminalNode* ExprParser::Const_valContext::Bool_const() {
  return getToken(ExprParser::Bool_const, 0);
}


size_t ExprParser::Const_valContext::getRuleIndex() const {
  return ExprParser::RuleConst_val;
}

void ExprParser::Const_valContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_val(this);
}

void ExprParser::Const_valContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_val(this);
}


antlrcpp::Any ExprParser::Const_valContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConst_val(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Const_valContext* ExprParser::const_val() {
  Const_valContext *_localctx = _tracker.createInstance<Const_valContext>(_ctx, getState());
  enterRule(_localctx, 44, ExprParser::RuleConst_val);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::Int_const)
      | (1ULL << ExprParser::Float_const)
      | (1ULL << ExprParser::String_const)
      | (1ULL << ExprParser::Bool_const)
      | (1ULL << ExprParser::ID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arithmetic1Context ------------------------------------------------------------------

ExprParser::Arithmetic1Context::Arithmetic1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::Arithmetic1Context::getRuleIndex() const {
  return ExprParser::RuleArithmetic1;
}

void ExprParser::Arithmetic1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic1(this);
}

void ExprParser::Arithmetic1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic1(this);
}


antlrcpp::Any ExprParser::Arithmetic1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArithmetic1(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Arithmetic1Context* ExprParser::arithmetic1() {
  Arithmetic1Context *_localctx = _tracker.createInstance<Arithmetic1Context>(_ctx, getState());
  enterRule(_localctx, 46, ExprParser::RuleArithmetic1);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(326);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__10)
      | (1ULL << ExprParser::T__11)
      | (1ULL << ExprParser::T__12))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arithmetic2Context ------------------------------------------------------------------

ExprParser::Arithmetic2Context::Arithmetic2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::Arithmetic2Context::getRuleIndex() const {
  return ExprParser::RuleArithmetic2;
}

void ExprParser::Arithmetic2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic2(this);
}

void ExprParser::Arithmetic2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic2(this);
}


antlrcpp::Any ExprParser::Arithmetic2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArithmetic2(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Arithmetic2Context* ExprParser::arithmetic2() {
  Arithmetic2Context *_localctx = _tracker.createInstance<Arithmetic2Context>(_ctx, getState());
  enterRule(_localctx, 48, ExprParser::RuleArithmetic2);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    _la = _input->LA(1);
    if (!(_la == ExprParser::T__13

    || _la == ExprParser::T__14)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartContext ------------------------------------------------------------------

ExprParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::StartContext::START() {
  return getToken(ExprParser::START, 0);
}


size_t ExprParser::StartContext::getRuleIndex() const {
  return ExprParser::RuleStart;
}

void ExprParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void ExprParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any ExprParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::StartContext* ExprParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 50, ExprParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(ExprParser::START);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 7: return args_varSempred(dynamic_cast<Args_varContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::args_varSempred(Args_varContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "program", "start_func", "ft_def", "var_def", "type", "var_val", "fun_def",
  "args_var", "block", "stmt", "assign", "var", "ref", "expr", "term", "factor",
  "func_call", "handle_call", "params", "cond_stmt", "switch_body", "loop_stmt",
  "const_val", "arithmetic1", "arithmetic2", "start"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'('", "')'", "'='", "','", "';'", "'['", "']'", "'{'", "'}'", "':'",
  "'*'", "'/'", "'%'", "'+'", "'-'", "'allocate'", "'bool'", "'break'",
  "'caseof'", "'const'", "'continue'", "'default'", "'destruct'", "'else'",
  "'false'", "'function'", "'float'", "'for'", "'if'", "'int'", "'nil'",
  "'private'", "'protected'", "'public'", "'read'", "'string'", "'super'",
  "'switch'", "'this'", "'true'", "'type'", "'while'", "'write'", "'.'",
  "'start'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "Allocate",
  "Bool", "Break", "Caseof", "Const", "Continue", "Default", "Destruct",
  "Else", "False", "Function", "Float", "For", "If", "Int", "Nil", "Private",
  "Protected", "Public", "Read", "String", "Super", "Switch", "This", "True",
  "Type", "While", "Write", "Dot", "START", "Int_const", "Float_const",
  "String_const", "Bool_const", "ID", "WHITESPACE", "Comment"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
    for (size_t i = 0; i < _symbolicNames.size(); ++i) {
        std::string name = _vocabulary.getLiteralName(i);
        if (name.empty()) {
            name = _vocabulary.getSymbolicName(i);
        }

        if (name.empty()) {
            _tokenNames.push_back("<INVALID>");
        } else {
      _tokenNames.push_back(name);
    }
    }

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964,
    0x3, 0x36, 0x14f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4,
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7,
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb,
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe,
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4,
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15,
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9,
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b,
    0x3, 0x2, 0x7, 0x2, 0x38, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x3b, 0xb, 0x2,
    0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x3f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x42,
    0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4,
    0x3, 0x5, 0x5, 0x5, 0x52, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3,
    0x5, 0x7, 0x5, 0x58, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5b, 0xb, 0x5, 0x3,
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3,
    0x7, 0x5, 0x7, 0x65, 0xa, 0x7, 0x5, 0x7, 0x67, 0xa, 0x7, 0x3, 0x8, 0x3,
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6e, 0xa, 0x8, 0x3, 0x8,
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x74, 0xa, 0x8, 0x3, 0x8, 0x3,
    0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x7d,
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x80, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3,
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x89, 0xa, 0x9,
    0xc, 0x9, 0xe, 0x9, 0x8c, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x90,
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x93, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3,
    0xa, 0x7, 0xa, 0x98, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x9b, 0xb, 0xa, 0x3,
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3,
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5,
    0xb, 0xab, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc,
    0x7, 0xc, 0xb2, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xb5, 0xb, 0xc, 0x3, 0xc,
    0x3, 0xc, 0x5, 0xc, 0xb9, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5,
    0xc, 0xbe, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xc3, 0xa,
    0xd, 0xc, 0xd, 0xe, 0xd, 0xc6, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe,
    0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xcd, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xd0,
    0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xd6, 0xa,
    0xf, 0xc, 0xf, 0xe, 0xf, 0xd9, 0xb, 0xf, 0x3, 0xf, 0x5, 0xf, 0xdc, 0xa,
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xe2, 0xa,
    0x10, 0xc, 0x10, 0xe, 0x10, 0xe5, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3,
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xee, 0xa,
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xf3, 0xa, 0x12, 0x3,
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12,
    0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xfe, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13,
    0x3, 0x13, 0x5, 0x13, 0x103, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14,
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x10c, 0xa, 0x14,
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x112, 0xa, 0x15,
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x117, 0xa, 0x15, 0x5, 0x15,
    0x119, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15,
    0x3, 0x15, 0x5, 0x15, 0x121, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16,
    0x3, 0x16, 0x6, 0x16, 0x127, 0xa, 0x16, 0xd, 0x16, 0xe, 0x16, 0x128,
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x12e, 0xa, 0x16, 0x3, 0x17,
    0x3, 0x17, 0x5, 0x17, 0x132, 0xa, 0x17, 0x3, 0x17, 0x5, 0x17, 0x135,
    0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x13b,
    0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3,
    0x17, 0x5, 0x17, 0x143, 0xa, 0x17, 0x5, 0x17, 0x145, 0xa, 0x17, 0x3,
    0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b,
    0x3, 0x1b, 0x3, 0x1b, 0x2, 0x3, 0x10, 0x1c, 0x2, 0x4, 0x6, 0x8, 0xa,
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22,
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x2, 0x6, 0x7,
    0x2, 0x13, 0x13, 0x1d, 0x1d, 0x20, 0x20, 0x26, 0x26, 0x34, 0x34, 0x3,
    0x2, 0x30, 0x34, 0x3, 0x2, 0xd, 0xf, 0x3, 0x2, 0x10, 0x11, 0x2, 0x161,
    0x2, 0x39, 0x3, 0x2, 0x2, 0x2, 0x4, 0x43, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4e,
    0x3, 0x2, 0x2, 0x2, 0x8, 0x51, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5e, 0x3, 0x2,
    0x2, 0x2, 0xc, 0x60, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6d, 0x3, 0x2, 0x2, 0x2,
    0x10, 0x78, 0x3, 0x2, 0x2, 0x2, 0x12, 0x94, 0x3, 0x2, 0x2, 0x2, 0x14,
    0xaa, 0x3, 0x2, 0x2, 0x2, 0x16, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x18, 0xbf,
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xdb, 0x3,
    0x2, 0x2, 0x2, 0x1e, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x20, 0xed, 0x3, 0x2,
    0x2, 0x2, 0x22, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x24, 0xff, 0x3, 0x2, 0x2,
    0x2, 0x26, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x28, 0x120, 0x3, 0x2, 0x2, 0x2,
    0x2a, 0x126, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x144, 0x3, 0x2, 0x2, 0x2, 0x2e,
    0x146, 0x3, 0x2, 0x2, 0x2, 0x30, 0x148, 0x3, 0x2, 0x2, 0x2, 0x32, 0x14a,
    0x3, 0x2, 0x2, 0x2, 0x34, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x5,
    0x6, 0x4, 0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2,
    0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2,
    0x2, 0x3a, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2,
    0x3c, 0x40, 0x5, 0x4, 0x3, 0x2, 0x3d, 0x3f, 0x5, 0x6, 0x4, 0x2, 0x3e,
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e,
    0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3, 0x3,
    0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 0x3,
    0x2, 0x2, 0x44, 0x45, 0x7, 0x20, 0x2, 0x2, 0x45, 0x46, 0x7, 0x34, 0x2,
    0x2, 0x46, 0x47, 0x7, 0x4, 0x2, 0x2, 0x47, 0x48, 0x7, 0x5, 0x2, 0x2,
    0x48, 0x49, 0x7, 0x1c, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x34, 0x1b, 0x2, 0x4a,
    0x4b, 0x7, 0x3, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x4, 0x2, 0x2, 0x4c, 0x4d,
    0x5, 0x12, 0xa, 0x2, 0x4d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x5,
    0xe, 0x8, 0x2, 0x4f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x7, 0x16,
    0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 0x2,
    0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x5, 0xa, 0x6, 0x2,
    0x54, 0x59, 0x5, 0xc, 0x7, 0x2, 0x55, 0x56, 0x7, 0x6, 0x2, 0x2, 0x56,
    0x58, 0x5, 0xc, 0x7, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b,
    0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3,
    0x2, 0x2, 0x2, 0x5a, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2,
    0x2, 0x2, 0x5c, 0x5d, 0x7, 0x7, 0x2, 0x2, 0x5d, 0x9, 0x3, 0x2, 0x2,
    0x2, 0x5e, 0x5f, 0x9, 0x2, 0x2, 0x2, 0x5f, 0xb, 0x3, 0x2, 0x2, 0x2,
    0x60, 0x66, 0x5, 0x1a, 0xe, 0x2, 0x61, 0x64, 0x7, 0x5, 0x2, 0x2, 0x62,
    0x65, 0x5, 0x2e, 0x18, 0x2, 0x63, 0x65, 0x5, 0x1c, 0xf, 0x2, 0x64, 0x62,
    0x3, 0x2, 0x2, 0x2, 0x64, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x67, 0x3,
    0x2, 0x2, 0x2, 0x66, 0x61, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2,
    0x2, 0x2, 0x67, 0xd, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x3, 0x2,
    0x2, 0x69, 0x6a, 0x5, 0x10, 0x9, 0x2, 0x6a, 0x6b, 0x7, 0x4, 0x2, 0x2,
    0x6b, 0x6c, 0x7, 0x5, 0x2, 0x2, 0x6c, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6d,
    0x68, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f,
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x1c, 0x2, 0x2, 0x70, 0x71, 0x7,
    0x34, 0x2, 0x2, 0x71, 0x73, 0x7, 0x3, 0x2, 0x2, 0x72, 0x74, 0x5, 0x10,
    0x9, 0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2,
    0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0x4, 0x2, 0x2,
    0x76, 0x77, 0x5, 0x12, 0xa, 0x2, 0x77, 0xf, 0x3, 0x2, 0x2, 0x2, 0x78,
    0x79, 0x8, 0x9, 0x1, 0x2, 0x79, 0x7e, 0x5, 0xa, 0x6, 0x2, 0x7a, 0x7b,
    0x7, 0x8, 0x2, 0x2, 0x7b, 0x7d, 0x7, 0x9, 0x2, 0x2, 0x7c, 0x7a, 0x3,
    0x2, 0x2, 0x2, 0x7d, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7c, 0x3, 0x2,
    0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x81, 0x3, 0x2, 0x2,
    0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 0x34, 0x2, 0x2,
    0x82, 0x91, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0xc, 0x3, 0x2, 0x2, 0x84,
    0x85, 0x7, 0x6, 0x2, 0x2, 0x85, 0x8a, 0x5, 0xa, 0x6, 0x2, 0x86, 0x87,
    0x7, 0x8, 0x2, 0x2, 0x87, 0x89, 0x7, 0x9, 0x2, 0x2, 0x88, 0x86, 0x3,
    0x2, 0x2, 0x2, 0x89, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2,
    0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8d, 0x3, 0x2, 0x2,
    0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x34, 0x2, 0x2,
    0x8e, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x83, 0x3, 0x2, 0x2, 0x2, 0x90,
    0x93, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92,
    0x3, 0x2, 0x2, 0x2, 0x92, 0x11, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3,
    0x2, 0x2, 0x2, 0x94, 0x99, 0x7, 0xa, 0x2, 0x2, 0x95, 0x98, 0x5, 0x8,
    0x5, 0x2, 0x96, 0x98, 0x5, 0x14, 0xb, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2,
    0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x9b, 0x3, 0x2, 0x2, 0x2,
    0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a,
    0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d,
    0x7, 0xb, 0x2, 0x2, 0x9d, 0x13, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x5,
    0x16, 0xc, 0x2, 0x9f, 0xa0, 0x7, 0x7, 0x2, 0x2, 0xa0, 0xab, 0x3, 0x2,
    0x2, 0x2, 0xa1, 0xa2, 0x5, 0x22, 0x12, 0x2, 0xa2, 0xa3, 0x7, 0x7, 0x2,
    0x2, 0xa3, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xab, 0x5, 0x28, 0x15, 0x2,
    0xa5, 0xab, 0x5, 0x2c, 0x17, 0x2, 0xa6, 0xa7, 0x7, 0x14, 0x2, 0x2, 0xa7,
    0xab, 0x7, 0x7, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x17, 0x2, 0x2, 0xa9, 0xab,
    0x7, 0x7, 0x2, 0x2, 0xaa, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa1, 0x3,
    0x2, 0x2, 0x2, 0xaa, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa5, 0x3, 0x2,
    0x2, 0x2, 0xaa, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2,
    0x2, 0xab, 0x15, 0x3, 0x2, 0x2, 0x2, 0xac, 0xb9, 0x5, 0x18, 0xd, 0x2,
    0xad, 0xae, 0x7, 0x3, 0x2, 0x2, 0xae, 0xb3, 0x5, 0x18, 0xd, 0x2, 0xaf,
    0xb0, 0x7, 0x6, 0x2, 0x2, 0xb0, 0xb2, 0x5, 0x18, 0xd, 0x2, 0xb1, 0xaf,
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3,
    0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb6, 0x3, 0x2,
    0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x4, 0x2,
    0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xac, 0x3, 0x2, 0x2, 0x2,
    0xb8, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba,
    0xbd, 0x7, 0x5, 0x2, 0x2, 0xbb, 0xbe, 0x5, 0x2e, 0x18, 0x2, 0xbc, 0xbe,
    0x5, 0x1c, 0xf, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbc, 0x3,
    0x2, 0x2, 0x2, 0xbe, 0x17, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc4, 0x5, 0x1a,
    0xe, 0x2, 0xc0, 0xc1, 0x7, 0x2e, 0x2, 0x2, 0xc1, 0xc3, 0x5, 0x1a, 0xe,
    0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc6, 0x3, 0x2, 0x2, 0x2,
    0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5,
    0x19, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xce,
    0x7, 0x34, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x8, 0x2, 0x2, 0xc9, 0xca, 0x5,
    0x1c, 0xf, 0x2, 0xca, 0xcb, 0x7, 0x9, 0x2, 0x2, 0xcb, 0xcd, 0x3, 0x2,
    0x2, 0x2, 0xcc, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xd0, 0x3, 0x2, 0x2,
    0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2,
    0xcf, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd1,
    0xd7, 0x5, 0x1e, 0x10, 0x2, 0xd2, 0xd3, 0x5, 0x32, 0x1a, 0x2, 0xd3,
    0xd4, 0x5, 0x1e, 0x10, 0x2, 0xd4, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd2,
    0x3, 0x2, 0x2, 0x2, 0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3,
    0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xdc, 0x3, 0x2,
    0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdc, 0x5, 0x22, 0x12,
    0x2, 0xdb, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xda, 0x3, 0x2, 0x2, 0x2,
    0xdc, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe3, 0x5, 0x20, 0x11, 0x2, 0xde,
    0xdf, 0x5, 0x30, 0x19, 0x2, 0xdf, 0xe0, 0x5, 0x20, 0x11, 0x2, 0xe0,
    0xe2, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe5,
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3,
    0x2, 0x2, 0x2, 0xe4, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 0x3, 0x2,
    0x2, 0x2, 0xe6, 0xe7, 0x7, 0x3, 0x2, 0x2, 0xe7, 0xe8, 0x5, 0x1c, 0xf,
    0x2, 0xe8, 0xe9, 0x7, 0x4, 0x2, 0x2, 0xe9, 0xee, 0x3, 0x2, 0x2, 0x2,
    0xea, 0xee, 0x7, 0x30, 0x2, 0x2, 0xeb, 0xee, 0x7, 0x31, 0x2, 0x2, 0xec,
    0xee, 0x7, 0x34, 0x2, 0x2, 0xed, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xed, 0xea,
    0x3, 0x2, 0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xed, 0xec, 0x3,
    0x2, 0x2, 0x2, 0xee, 0x21, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x5, 0x18,
    0xd, 0x2, 0xf0, 0xf1, 0x7, 0x2e, 0x2, 0x2, 0xf1, 0xf3, 0x3, 0x2, 0x2,
    0x2, 0xf2, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2,
    0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xfe, 0x5, 0x24, 0x13, 0x2, 0xf5,
    0xf6, 0x7, 0x25, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x3, 0x2, 0x2, 0xf7, 0xfe,
    0x7, 0x4, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x2d, 0x2, 0x2, 0xf9, 0xfa, 0x7,
    0x3, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x2e, 0x18, 0x2, 0xfb, 0xfc, 0x7, 0x4,
    0x2, 0x2, 0xfc, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xf2, 0x3, 0x2, 0x2,
    0x2, 0xfd, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xf8, 0x3, 0x2, 0x2, 0x2,
    0xfe, 0x23, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x34, 0x2, 0x2, 0x100,
    0x102, 0x7, 0x3, 0x2, 0x2, 0x101, 0x103, 0x5, 0x26, 0x14, 0x2, 0x102,
    0x101, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2, 0x2, 0x103,
    0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x7, 0x4, 0x2, 0x2, 0x105,
    0x25, 0x3, 0x2, 0x2, 0x2, 0x106, 0x10c, 0x5, 0x1c, 0xf, 0x2, 0x107,
    0x108, 0x5, 0x1c, 0xf, 0x2, 0x108, 0x109, 0x7, 0x6, 0x2, 0x2, 0x109,
    0x10a, 0x5, 0x26, 0x14, 0x2, 0x10a, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10b,
    0x106, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10c,
    0x27, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x1f, 0x2, 0x2, 0x10e,
    0x111, 0x5, 0x1c, 0xf, 0x2, 0x10f, 0x112, 0x5, 0x12, 0xa, 0x2, 0x110,
    0x112, 0x5, 0x14, 0xb, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111,
    0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x118, 0x3, 0x2, 0x2, 0x2, 0x113,
    0x116, 0x7, 0x1a, 0x2, 0x2, 0x114, 0x117, 0x5, 0x12, 0xa, 0x2, 0x115,
    0x117, 0x5, 0x14, 0xb, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116,
    0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x119, 0x3, 0x2, 0x2, 0x2, 0x118,
    0x113, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 0x2, 0x119,
    0x121, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x28, 0x2, 0x2, 0x11b,
    0x11c, 0x5, 0x18, 0xd, 0x2, 0x11c, 0x11d, 0x7, 0xa, 0x2, 0x2, 0x11d,
    0x11e, 0x5, 0x2a, 0x16, 0x2, 0x11e, 0x11f, 0x7, 0xb, 0x2, 0x2, 0x11f,
    0x121, 0x3, 0x2, 0x2, 0x2, 0x120, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x120,
    0x11a, 0x3, 0x2, 0x2, 0x2, 0x121, 0x29, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123,
    0x7, 0x15, 0x2, 0x2, 0x123, 0x124, 0x7, 0x30, 0x2, 0x2, 0x124, 0x125,
    0x7, 0xc, 0x2, 0x2, 0x125, 0x127, 0x5, 0x12, 0xa, 0x2, 0x126, 0x122,
    0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x126,
    0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12d,
    0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x18, 0x2, 0x2, 0x12b, 0x12c,
    0x7, 0xc, 0x2, 0x2, 0x12c, 0x12e, 0x5, 0x12, 0xa, 0x2, 0x12d, 0x12a,
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x2b, 0x3,
    0x2, 0x2, 0x2, 0x12f, 0x134, 0x7, 0x1e, 0x2, 0x2, 0x130, 0x132, 0x5,
    0xa, 0x6, 0x2, 0x131, 0x130, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3,
    0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 0x5,
    0x16, 0xc, 0x2, 0x134, 0x131, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3,
    0x2, 0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x7,
    0x7, 0x2, 0x2, 0x137, 0x138, 0x5, 0x1c, 0xf, 0x2, 0x138, 0x13a, 0x7,
    0x7, 0x2, 0x2, 0x139, 0x13b, 0x5, 0x16, 0xc, 0x2, 0x13a, 0x139, 0x3,
    0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3,
    0x2, 0x2, 0x2, 0x13c, 0x13d, 0x5, 0x12, 0xa, 0x2, 0x13d, 0x145, 0x3,
    0x2, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x2c, 0x2, 0x2, 0x13f, 0x142, 0x5,
    0x1c, 0xf, 0x2, 0x140, 0x143, 0x5, 0x12, 0xa, 0x2, 0x141, 0x143, 0x5,
    0x14, 0xb, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x141, 0x3,
    0x2, 0x2, 0x2, 0x143, 0x145, 0x3, 0x2, 0x2, 0x2, 0x144, 0x12f, 0x3,
    0x2, 0x2, 0x2, 0x144, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x145, 0x2d, 0x3, 0x2,
    0x2, 0x2, 0x146, 0x147, 0x9, 0x3, 0x2, 0x2, 0x147, 0x2f, 0x3, 0x2, 0x2,
    0x2, 0x148, 0x149, 0x9, 0x4, 0x2, 0x2, 0x149, 0x31, 0x3, 0x2, 0x2, 0x2,
    0x14a, 0x14b, 0x9, 0x5, 0x2, 0x2, 0x14b, 0x33, 0x3, 0x2, 0x2, 0x2, 0x14c,
    0x14d, 0x7, 0x2f, 0x2, 0x2, 0x14d, 0x35, 0x3, 0x2, 0x2, 0x2, 0x28, 0x39,
    0x40, 0x51, 0x59, 0x64, 0x66, 0x6d, 0x73, 0x7e, 0x8a, 0x91, 0x97, 0x99,
    0xaa, 0xb3, 0xb8, 0xbd, 0xc4, 0xce, 0xd7, 0xdb, 0xe3, 0xed, 0xf2, 0xfd,
    0x102, 0x10b, 0x111, 0x116, 0x118, 0x120, 0x128, 0x12d, 0x131, 0x134,
    0x13a, 0x142, 0x144,
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) {
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
