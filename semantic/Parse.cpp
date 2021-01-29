
// Generated from /home/navid/Compiler_project/Parse.g4 by ANTLR 4.8


#include "ParseListener.h"
#include "ParseVisitor.h"

#include "Parse.h"


using namespace antlrcpp;
using namespace antlr4;

Parse::Parse(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

Parse::~Parse() {
  delete _interpreter;
}

std::string Parse::getGrammarFileName() const {
  return "Parse.g4";
}

const std::vector<std::string>& Parse::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& Parse::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

Parse::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Parse::Start_funcContext* Parse::ProgramContext::start_func() {
  return getRuleContext<Parse::Start_funcContext>(0);
}

tree::TerminalNode* Parse::ProgramContext::EOF() {
  return getToken(Parse::EOF, 0);
}

std::vector<Parse::Ft_defContext *> Parse::ProgramContext::ft_def() {
  return getRuleContexts<Parse::Ft_defContext>();
}

Parse::Ft_defContext* Parse::ProgramContext::ft_def(size_t i) {
  return getRuleContext<Parse::Ft_defContext>(i);
}


size_t Parse::ProgramContext::getRuleIndex() const {
  return Parse::RuleProgram;
}

void Parse::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void Parse::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any Parse::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

Parse::ProgramContext* Parse::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, Parse::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(83);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(80);
        ft_def();
      }
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(86);
    start_func();
    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Parse::FUNCTION)
      | (1ULL << Parse::TYPE)
      | (1ULL << Parse::LPAR))) != 0)) {
      setState(87);
      ft_def();
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(93);
    match(Parse::EOF);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Start_funcContext ------------------------------------------------------------------

Parse::Start_funcContext::Start_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> Parse::Start_funcContext::LPAR() {
  return getTokens(Parse::LPAR);
}

tree::TerminalNode* Parse::Start_funcContext::LPAR(size_t i) {
  return getToken(Parse::LPAR, i);
}

tree::TerminalNode* Parse::Start_funcContext::INT() {
  return getToken(Parse::INT, 0);
}

tree::TerminalNode* Parse::Start_funcContext::ID() {
  return getToken(Parse::ID, 0);
}

std::vector<tree::TerminalNode *> Parse::Start_funcContext::RPAR() {
  return getTokens(Parse::RPAR);
}

tree::TerminalNode* Parse::Start_funcContext::RPAR(size_t i) {
  return getToken(Parse::RPAR, i);
}

tree::TerminalNode* Parse::Start_funcContext::ASM() {
  return getToken(Parse::ASM, 0);
}

tree::TerminalNode* Parse::Start_funcContext::FUNCTION() {
  return getToken(Parse::FUNCTION, 0);
}

Parse::StartContext* Parse::Start_funcContext::start() {
  return getRuleContext<Parse::StartContext>(0);
}

Parse::BlockContext* Parse::Start_funcContext::block() {
  return getRuleContext<Parse::BlockContext>(0);
}


size_t Parse::Start_funcContext::getRuleIndex() const {
  return Parse::RuleStart_func;
}

void Parse::Start_funcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart_func(this);
}

void Parse::Start_funcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart_func(this);
}


antlrcpp::Any Parse::Start_funcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitStart_func(this);
  else
    return visitor->visitChildren(this);
}

Parse::Start_funcContext* Parse::start_func() {
  Start_funcContext *_localctx = _tracker.createInstance<Start_funcContext>(_ctx, getState());
  enterRule(_localctx, 2, Parse::RuleStart_func);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(Parse::LPAR);
    setState(96);
    match(Parse::INT);
    setState(97);
    match(Parse::ID);
    setState(98);
    match(Parse::RPAR);
    setState(99);
    match(Parse::ASM);
    setState(100);
    match(Parse::FUNCTION);
    setState(101);
    start();
    setState(102);
    match(Parse::LPAR);
    setState(103);
    match(Parse::RPAR);
    setState(104);
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

Parse::Ft_defContext::Ft_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Parse::Type_defContext* Parse::Ft_defContext::type_def() {
  return getRuleContext<Parse::Type_defContext>(0);
}

Parse::Fun_defContext* Parse::Ft_defContext::fun_def() {
  return getRuleContext<Parse::Fun_defContext>(0);
}


size_t Parse::Ft_defContext::getRuleIndex() const {
  return Parse::RuleFt_def;
}

void Parse::Ft_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFt_def(this);
}

void Parse::Ft_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFt_def(this);
}


antlrcpp::Any Parse::Ft_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitFt_def(this);
  else
    return visitor->visitChildren(this);
}

Parse::Ft_defContext* Parse::ft_def() {
  Ft_defContext *_localctx = _tracker.createInstance<Ft_defContext>(_ctx, getState());
  enterRule(_localctx, 4, Parse::RuleFt_def);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Parse::TYPE: {
        setState(106);
        type_def();
        break;
      }

      case Parse::FUNCTION:
      case Parse::LPAR: {
        setState(107);
        fun_def();
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

//----------------- Type_defContext ------------------------------------------------------------------

Parse::Type_defContext::Type_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Type_defContext::TYPE() {
  return getToken(Parse::TYPE, 0);
}

std::vector<tree::TerminalNode *> Parse::Type_defContext::ID() {
  return getTokens(Parse::ID);
}

tree::TerminalNode* Parse::Type_defContext::ID(size_t i) {
  return getToken(Parse::ID, i);
}

tree::TerminalNode* Parse::Type_defContext::CLPAR() {
  return getToken(Parse::CLPAR, 0);
}

tree::TerminalNode* Parse::Type_defContext::CRPAR() {
  return getToken(Parse::CRPAR, 0);
}

tree::TerminalNode* Parse::Type_defContext::COLON() {
  return getToken(Parse::COLON, 0);
}

std::vector<Parse::ComponentContext *> Parse::Type_defContext::component() {
  return getRuleContexts<Parse::ComponentContext>();
}

Parse::ComponentContext* Parse::Type_defContext::component(size_t i) {
  return getRuleContext<Parse::ComponentContext>(i);
}


size_t Parse::Type_defContext::getRuleIndex() const {
  return Parse::RuleType_def;
}

void Parse::Type_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_def(this);
}

void Parse::Type_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_def(this);
}


antlrcpp::Any Parse::Type_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitType_def(this);
  else
    return visitor->visitChildren(this);
}

Parse::Type_defContext* Parse::type_def() {
  Type_defContext *_localctx = _tracker.createInstance<Type_defContext>(_ctx, getState());
  enterRule(_localctx, 6, Parse::RuleType_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    match(Parse::TYPE);
    setState(111);
    match(Parse::ID);
    setState(114);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Parse::COLON) {
      setState(112);
      match(Parse::COLON);
      setState(113);
      dynamic_cast<Type_defContext *>(_localctx)->superType = match(Parse::ID);
    }
    setState(116);
    match(Parse::CLPAR);
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(117);
      component();
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 23) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 23)) & ((1ULL << (Parse::FUNCTION - 23))
      | (1ULL << (Parse::BOOL - 23))
      | (1ULL << (Parse::INT - 23))
      | (1ULL << (Parse::FLOAT - 23))
      | (1ULL << (Parse::STRING - 23))
      | (1ULL << (Parse::CONST - 23))
      | (1ULL << (Parse::PUBLIC - 23))
      | (1ULL << (Parse::PRIVATE - 23))
      | (1ULL << (Parse::PROTECTED - 23))
      | (1ULL << (Parse::LPAR - 23))
      | (1ULL << (Parse::ID - 23)))) != 0));
    setState(122);
    match(Parse::CRPAR);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentContext ------------------------------------------------------------------

Parse::ComponentContext::ComponentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Parse::Field_defContext* Parse::ComponentContext::field_def() {
  return getRuleContext<Parse::Field_defContext>(0);
}

Parse::Method_defContext* Parse::ComponentContext::method_def() {
  return getRuleContext<Parse::Method_defContext>(0);
}


size_t Parse::ComponentContext::getRuleIndex() const {
  return Parse::RuleComponent;
}

void Parse::ComponentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent(this);
}

void Parse::ComponentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent(this);
}


antlrcpp::Any Parse::ComponentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitComponent(this);
  else
    return visitor->visitChildren(this);
}

Parse::ComponentContext* Parse::component() {
  ComponentContext *_localctx = _tracker.createInstance<ComponentContext>(_ctx, getState());
  enterRule(_localctx, 8, Parse::RuleComponent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(124);
      field_def();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(125);
      method_def();
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

//----------------- Field_defContext ------------------------------------------------------------------

Parse::Field_defContext::Field_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Parse::Var_defContext* Parse::Field_defContext::var_def() {
  return getRuleContext<Parse::Var_defContext>(0);
}

Parse::Access_modifierContext* Parse::Field_defContext::access_modifier() {
  return getRuleContext<Parse::Access_modifierContext>(0);
}


size_t Parse::Field_defContext::getRuleIndex() const {
  return Parse::RuleField_def;
}

void Parse::Field_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterField_def(this);
}

void Parse::Field_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitField_def(this);
}


antlrcpp::Any Parse::Field_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitField_def(this);
  else
    return visitor->visitChildren(this);
}

Parse::Field_defContext* Parse::field_def() {
  Field_defContext *_localctx = _tracker.createInstance<Field_defContext>(_ctx, getState());
  enterRule(_localctx, 10, Parse::RuleField_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Parse::PUBLIC)
      | (1ULL << Parse::PRIVATE)
      | (1ULL << Parse::PROTECTED))) != 0)) {
      setState(128);
      access_modifier();
    }
    setState(131);
    var_def();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_defContext ------------------------------------------------------------------

Parse::Method_defContext::Method_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Parse::Fun_defContext* Parse::Method_defContext::fun_def() {
  return getRuleContext<Parse::Fun_defContext>(0);
}

Parse::Access_modifierContext* Parse::Method_defContext::access_modifier() {
  return getRuleContext<Parse::Access_modifierContext>(0);
}


size_t Parse::Method_defContext::getRuleIndex() const {
  return Parse::RuleMethod_def;
}

void Parse::Method_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethod_def(this);
}

void Parse::Method_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethod_def(this);
}


antlrcpp::Any Parse::Method_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitMethod_def(this);
  else
    return visitor->visitChildren(this);
}

Parse::Method_defContext* Parse::method_def() {
  Method_defContext *_localctx = _tracker.createInstance<Method_defContext>(_ctx, getState());
  enterRule(_localctx, 12, Parse::RuleMethod_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Parse::PUBLIC)
      | (1ULL << Parse::PRIVATE)
      | (1ULL << Parse::PROTECTED))) != 0)) {
      setState(133);
      access_modifier();
    }
    setState(136);
    fun_def();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Access_modifierContext ------------------------------------------------------------------

Parse::Access_modifierContext::Access_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Access_modifierContext::PRIVATE() {
  return getToken(Parse::PRIVATE, 0);
}

tree::TerminalNode* Parse::Access_modifierContext::PUBLIC() {
  return getToken(Parse::PUBLIC, 0);
}

tree::TerminalNode* Parse::Access_modifierContext::PROTECTED() {
  return getToken(Parse::PROTECTED, 0);
}


size_t Parse::Access_modifierContext::getRuleIndex() const {
  return Parse::RuleAccess_modifier;
}

void Parse::Access_modifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccess_modifier(this);
}

void Parse::Access_modifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccess_modifier(this);
}


antlrcpp::Any Parse::Access_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitAccess_modifier(this);
  else
    return visitor->visitChildren(this);
}

Parse::Access_modifierContext* Parse::access_modifier() {
  Access_modifierContext *_localctx = _tracker.createInstance<Access_modifierContext>(_ctx, getState());
  enterRule(_localctx, 14, Parse::RuleAccess_modifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Parse::PUBLIC)
      | (1ULL << Parse::PRIVATE)
      | (1ULL << Parse::PROTECTED))) != 0))) {
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

//----------------- Var_defContext ------------------------------------------------------------------

Parse::Var_defContext::Var_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Parse::TypeContext* Parse::Var_defContext::type() {
  return getRuleContext<Parse::TypeContext>(0);
}

std::vector<Parse::Var_valContext *> Parse::Var_defContext::var_val() {
  return getRuleContexts<Parse::Var_valContext>();
}

Parse::Var_valContext* Parse::Var_defContext::var_val(size_t i) {
  return getRuleContext<Parse::Var_valContext>(i);
}

tree::TerminalNode* Parse::Var_defContext::SEMIC() {
  return getToken(Parse::SEMIC, 0);
}

tree::TerminalNode* Parse::Var_defContext::CONST() {
  return getToken(Parse::CONST, 0);
}

std::vector<tree::TerminalNode *> Parse::Var_defContext::COMMA() {
  return getTokens(Parse::COMMA);
}

tree::TerminalNode* Parse::Var_defContext::COMMA(size_t i) {
  return getToken(Parse::COMMA, i);
}


size_t Parse::Var_defContext::getRuleIndex() const {
  return Parse::RuleVar_def;
}

void Parse::Var_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_def(this);
}

void Parse::Var_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_def(this);
}


antlrcpp::Any Parse::Var_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitVar_def(this);
  else
    return visitor->visitChildren(this);
}

Parse::Var_defContext* Parse::var_def() {
  Var_defContext *_localctx = _tracker.createInstance<Var_defContext>(_ctx, getState());
  enterRule(_localctx, 16, Parse::RuleVar_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Parse::CONST) {
      setState(140);
      match(Parse::CONST);
    }
    setState(143);
    type();
    setState(144);
    var_val();
    setState(149);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Parse::COMMA) {
      setState(145);
      match(Parse::COMMA);
      setState(146);
      var_val();
      setState(151);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(152);
    match(Parse::SEMIC);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

Parse::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::TypeContext::INT() {
  return getToken(Parse::INT, 0);
}

tree::TerminalNode* Parse::TypeContext::BOOL() {
  return getToken(Parse::BOOL, 0);
}

tree::TerminalNode* Parse::TypeContext::FLOAT() {
  return getToken(Parse::FLOAT, 0);
}

tree::TerminalNode* Parse::TypeContext::STRING() {
  return getToken(Parse::STRING, 0);
}

tree::TerminalNode* Parse::TypeContext::ID() {
  return getToken(Parse::ID, 0);
}


size_t Parse::TypeContext::getRuleIndex() const {
  return Parse::RuleType;
}

void Parse::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void Parse::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any Parse::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

Parse::TypeContext* Parse::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 18, Parse::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    _la = _input->LA(1);
    if (!(((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & ((1ULL << (Parse::BOOL - 25))
      | (1ULL << (Parse::INT - 25))
      | (1ULL << (Parse::FLOAT - 25))
      | (1ULL << (Parse::STRING - 25))
      | (1ULL << (Parse::ID - 25)))) != 0))) {
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

Parse::Var_valContext::Var_valContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Parse::RefContext* Parse::Var_valContext::ref() {
  return getRuleContext<Parse::RefContext>(0);
}

tree::TerminalNode* Parse::Var_valContext::ASM() {
  return getToken(Parse::ASM, 0);
}

Parse::ExprContext* Parse::Var_valContext::expr() {
  return getRuleContext<Parse::ExprContext>(0);
}


size_t Parse::Var_valContext::getRuleIndex() const {
  return Parse::RuleVar_val;
}

void Parse::Var_valContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_val(this);
}

void Parse::Var_valContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_val(this);
}


antlrcpp::Any Parse::Var_valContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitVar_val(this);
  else
    return visitor->visitChildren(this);
}

Parse::Var_valContext* Parse::var_val() {
  Var_valContext *_localctx = _tracker.createInstance<Var_valContext>(_ctx, getState());
  enterRule(_localctx, 20, Parse::RuleVar_val);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    ref();
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Parse::ASM) {
      setState(157);
      match(Parse::ASM);
      setState(158);
      expr(0);
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

Parse::Fun_defContext::Fun_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Fun_defContext::FUNCTION() {
  return getToken(Parse::FUNCTION, 0);
}

tree::TerminalNode* Parse::Fun_defContext::ID() {
  return getToken(Parse::ID, 0);
}

std::vector<tree::TerminalNode *> Parse::Fun_defContext::LPAR() {
  return getTokens(Parse::LPAR);
}

tree::TerminalNode* Parse::Fun_defContext::LPAR(size_t i) {
  return getToken(Parse::LPAR, i);
}

Parse::Def_argsContext* Parse::Fun_defContext::def_args() {
  return getRuleContext<Parse::Def_argsContext>(0);
}

std::vector<tree::TerminalNode *> Parse::Fun_defContext::RPAR() {
  return getTokens(Parse::RPAR);
}

tree::TerminalNode* Parse::Fun_defContext::RPAR(size_t i) {
  return getToken(Parse::RPAR, i);
}

Parse::BlockContext* Parse::Fun_defContext::block() {
  return getRuleContext<Parse::BlockContext>(0);
}

tree::TerminalNode* Parse::Fun_defContext::ASM() {
  return getToken(Parse::ASM, 0);
}

Parse::Args_varContext* Parse::Fun_defContext::args_var() {
  return getRuleContext<Parse::Args_varContext>(0);
}


size_t Parse::Fun_defContext::getRuleIndex() const {
  return Parse::RuleFun_def;
}

void Parse::Fun_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFun_def(this);
}

void Parse::Fun_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFun_def(this);
}


antlrcpp::Any Parse::Fun_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitFun_def(this);
  else
    return visitor->visitChildren(this);
}

Parse::Fun_defContext* Parse::fun_def() {
  Fun_defContext *_localctx = _tracker.createInstance<Fun_defContext>(_ctx, getState());
  enterRule(_localctx, 22, Parse::RuleFun_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Parse::LPAR) {
      setState(161);
      match(Parse::LPAR);
      setState(162);
      dynamic_cast<Fun_defContext *>(_localctx)->def_ret = args_var();
      setState(163);
      match(Parse::RPAR);
      setState(164);
      match(Parse::ASM);
    }
    setState(168);
    match(Parse::FUNCTION);
    setState(169);
    match(Parse::ID);
    setState(170);
    match(Parse::LPAR);
    setState(171);
    def_args();
    setState(172);
    match(Parse::RPAR);
    setState(173);
    block();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Def_argsContext ------------------------------------------------------------------

Parse::Def_argsContext::Def_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Parse::Args_varContext* Parse::Def_argsContext::args_var() {
  return getRuleContext<Parse::Args_varContext>(0);
}


size_t Parse::Def_argsContext::getRuleIndex() const {
  return Parse::RuleDef_args;
}

void Parse::Def_argsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDef_args(this);
}

void Parse::Def_argsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDef_args(this);
}


antlrcpp::Any Parse::Def_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitDef_args(this);
  else
    return visitor->visitChildren(this);
}

Parse::Def_argsContext* Parse::def_args() {
  Def_argsContext *_localctx = _tracker.createInstance<Def_argsContext>(_ctx, getState());
  enterRule(_localctx, 24, Parse::RuleDef_args);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & ((1ULL << (Parse::BOOL - 25))
      | (1ULL << (Parse::INT - 25))
      | (1ULL << (Parse::FLOAT - 25))
      | (1ULL << (Parse::STRING - 25))
      | (1ULL << (Parse::ID - 25)))) != 0)) {
      setState(175);
      args_var();
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Args_varContext ------------------------------------------------------------------

Parse::Args_varContext::Args_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Parse::Array_typeContext *> Parse::Args_varContext::array_type() {
  return getRuleContexts<Parse::Array_typeContext>();
}

Parse::Array_typeContext* Parse::Args_varContext::array_type(size_t i) {
  return getRuleContext<Parse::Array_typeContext>(i);
}

std::vector<tree::TerminalNode *> Parse::Args_varContext::ID() {
  return getTokens(Parse::ID);
}

tree::TerminalNode* Parse::Args_varContext::ID(size_t i) {
  return getToken(Parse::ID, i);
}

std::vector<tree::TerminalNode *> Parse::Args_varContext::COMMA() {
  return getTokens(Parse::COMMA);
}

tree::TerminalNode* Parse::Args_varContext::COMMA(size_t i) {
  return getToken(Parse::COMMA, i);
}


size_t Parse::Args_varContext::getRuleIndex() const {
  return Parse::RuleArgs_var;
}

void Parse::Args_varContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgs_var(this);
}

void Parse::Args_varContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgs_var(this);
}


antlrcpp::Any Parse::Args_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitArgs_var(this);
  else
    return visitor->visitChildren(this);
}

Parse::Args_varContext* Parse::args_var() {
  Args_varContext *_localctx = _tracker.createInstance<Args_varContext>(_ctx, getState());
  enterRule(_localctx, 26, Parse::RuleArgs_var);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    array_type();
    setState(179);
    match(Parse::ID);
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Parse::COMMA) {
      setState(180);
      match(Parse::COMMA);
      setState(181);
      array_type();
      setState(182);
      match(Parse::ID);
      setState(188);
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

//----------------- BlockContext ------------------------------------------------------------------

Parse::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::BlockContext::CLPAR() {
  return getToken(Parse::CLPAR, 0);
}

tree::TerminalNode* Parse::BlockContext::CRPAR() {
  return getToken(Parse::CRPAR, 0);
}

std::vector<Parse::Var_defContext *> Parse::BlockContext::var_def() {
  return getRuleContexts<Parse::Var_defContext>();
}

Parse::Var_defContext* Parse::BlockContext::var_def(size_t i) {
  return getRuleContext<Parse::Var_defContext>(i);
}

std::vector<Parse::StmtContext *> Parse::BlockContext::stmt() {
  return getRuleContexts<Parse::StmtContext>();
}

Parse::StmtContext* Parse::BlockContext::stmt(size_t i) {
  return getRuleContext<Parse::StmtContext>(i);
}


size_t Parse::BlockContext::getRuleIndex() const {
  return Parse::RuleBlock;
}

void Parse::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void Parse::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any Parse::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

Parse::BlockContext* Parse::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 28, Parse::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(Parse::CLPAR);
    setState(194);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 13) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 13)) & ((1ULL << (Parse::FOR - 13))
      | (1ULL << (Parse::WHILE - 13))
      | (1ULL << (Parse::DESTRUCT - 13))
      | (1ULL << (Parse::IF - 13))
      | (1ULL << (Parse::BREAK - 13))
      | (1ULL << (Parse::CONTINUE - 13))
      | (1ULL << (Parse::BOOL - 13))
      | (1ULL << (Parse::INT - 13))
      | (1ULL << (Parse::FLOAT - 13))
      | (1ULL << (Parse::STRING - 13))
      | (1ULL << (Parse::CONST - 13))
      | (1ULL << (Parse::READ - 13))
      | (1ULL << (Parse::WRITE - 13))
      | (1ULL << (Parse::SUPER - 13))
      | (1ULL << (Parse::THIS - 13))
      | (1ULL << (Parse::SWITCH - 13))
      | (1ULL << (Parse::LPAR - 13))
      | (1ULL << (Parse::ID - 13)))) != 0)) {
      setState(192);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
      case 1: {
        setState(190);
        var_def();
        break;
      }

      case 2: {
        setState(191);
        stmt();
        break;
      }

      }
      setState(196);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(197);
    match(Parse::CRPAR);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

Parse::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Parse::StmtContext::getRuleIndex() const {
  return Parse::RuleStmt;
}

void Parse::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BreaksContext ------------------------------------------------------------------

tree::TerminalNode* Parse::BreaksContext::BREAK() {
  return getToken(Parse::BREAK, 0);
}

tree::TerminalNode* Parse::BreaksContext::SEMIC() {
  return getToken(Parse::SEMIC, 0);
}

Parse::BreaksContext::BreaksContext(StmtContext *ctx) { copyFrom(ctx); }

void Parse::BreaksContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreaks(this);
}
void Parse::BreaksContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreaks(this);
}

antlrcpp::Any Parse::BreaksContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitBreaks(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CondSContext ------------------------------------------------------------------

Parse::Cond_stmtContext* Parse::CondSContext::cond_stmt() {
  return getRuleContext<Parse::Cond_stmtContext>(0);
}

Parse::CondSContext::CondSContext(StmtContext *ctx) { copyFrom(ctx); }

void Parse::CondSContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondS(this);
}
void Parse::CondSContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondS(this);
}

antlrcpp::Any Parse::CondSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitCondS(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinuesContext ------------------------------------------------------------------

tree::TerminalNode* Parse::ContinuesContext::CONTINUE() {
  return getToken(Parse::CONTINUE, 0);
}

tree::TerminalNode* Parse::ContinuesContext::SEMIC() {
  return getToken(Parse::SEMIC, 0);
}

Parse::ContinuesContext::ContinuesContext(StmtContext *ctx) { copyFrom(ctx); }

void Parse::ContinuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinues(this);
}
void Parse::ContinuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinues(this);
}

antlrcpp::Any Parse::ContinuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitContinues(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncCallSContext ------------------------------------------------------------------

Parse::Func_callContext* Parse::FuncCallSContext::func_call() {
  return getRuleContext<Parse::Func_callContext>(0);
}

tree::TerminalNode* Parse::FuncCallSContext::SEMIC() {
  return getToken(Parse::SEMIC, 0);
}

Parse::FuncCallSContext::FuncCallSContext(StmtContext *ctx) { copyFrom(ctx); }

void Parse::FuncCallSContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCallS(this);
}
void Parse::FuncCallSContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCallS(this);
}

antlrcpp::Any Parse::FuncCallSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitFuncCallS(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignSContext ------------------------------------------------------------------

Parse::AssignContext* Parse::AssignSContext::assign() {
  return getRuleContext<Parse::AssignContext>(0);
}

tree::TerminalNode* Parse::AssignSContext::SEMIC() {
  return getToken(Parse::SEMIC, 0);
}

Parse::AssignSContext::AssignSContext(StmtContext *ctx) { copyFrom(ctx); }

void Parse::AssignSContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignS(this);
}
void Parse::AssignSContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignS(this);
}

antlrcpp::Any Parse::AssignSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitAssignS(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LoopSContext ------------------------------------------------------------------

Parse::Loop_stmtContext* Parse::LoopSContext::loop_stmt() {
  return getRuleContext<Parse::Loop_stmtContext>(0);
}

Parse::LoopSContext::LoopSContext(StmtContext *ctx) { copyFrom(ctx); }

void Parse::LoopSContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopS(this);
}
void Parse::LoopSContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopS(this);
}

antlrcpp::Any Parse::LoopSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitLoopS(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DestructsContext ------------------------------------------------------------------

tree::TerminalNode* Parse::DestructsContext::DESTRUCT() {
  return getToken(Parse::DESTRUCT, 0);
}

tree::TerminalNode* Parse::DestructsContext::ID() {
  return getToken(Parse::ID, 0);
}

tree::TerminalNode* Parse::DestructsContext::SEMIC() {
  return getToken(Parse::SEMIC, 0);
}

std::vector<tree::TerminalNode *> Parse::DestructsContext::BL() {
  return getTokens(Parse::BL);
}

tree::TerminalNode* Parse::DestructsContext::BL(size_t i) {
  return getToken(Parse::BL, i);
}

std::vector<tree::TerminalNode *> Parse::DestructsContext::BR() {
  return getTokens(Parse::BR);
}

tree::TerminalNode* Parse::DestructsContext::BR(size_t i) {
  return getToken(Parse::BR, i);
}

Parse::DestructsContext::DestructsContext(StmtContext *ctx) { copyFrom(ctx); }

void Parse::DestructsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDestructs(this);
}
void Parse::DestructsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDestructs(this);
}

antlrcpp::Any Parse::DestructsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitDestructs(this);
  else
    return visitor->visitChildren(this);
}
Parse::StmtContext* Parse::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 30, Parse::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(221);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<Parse::AssignSContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(199);
      assign();
      setState(200);
      match(Parse::SEMIC);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<Parse::FuncCallSContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(202);
      func_call();
      setState(203);
      match(Parse::SEMIC);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<Parse::CondSContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(205);
      cond_stmt();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<Parse::LoopSContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(206);
      loop_stmt();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<Parse::BreaksContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(207);
      match(Parse::BREAK);
      setState(208);
      match(Parse::SEMIC);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<Parse::ContinuesContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(209);
      match(Parse::CONTINUE);
      setState(210);
      match(Parse::SEMIC);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<Parse::DestructsContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(211);
      match(Parse::DESTRUCT);
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Parse::BL) {
        setState(212);
        match(Parse::BL);
        setState(213);
        match(Parse::BR);
        setState(218);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(219);
      match(Parse::ID);
      setState(220);
      match(Parse::SEMIC);
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

Parse::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::AssignContext::ASM() {
  return getToken(Parse::ASM, 0);
}

Parse::ExprContext* Parse::AssignContext::expr() {
  return getRuleContext<Parse::ExprContext>(0);
}

std::vector<Parse::VarContext *> Parse::AssignContext::var() {
  return getRuleContexts<Parse::VarContext>();
}

Parse::VarContext* Parse::AssignContext::var(size_t i) {
  return getRuleContext<Parse::VarContext>(i);
}

tree::TerminalNode* Parse::AssignContext::LPAR() {
  return getToken(Parse::LPAR, 0);
}

tree::TerminalNode* Parse::AssignContext::RPAR() {
  return getToken(Parse::RPAR, 0);
}

std::vector<tree::TerminalNode *> Parse::AssignContext::COMMA() {
  return getTokens(Parse::COMMA);
}

tree::TerminalNode* Parse::AssignContext::COMMA(size_t i) {
  return getToken(Parse::COMMA, i);
}


size_t Parse::AssignContext::getRuleIndex() const {
  return Parse::RuleAssign;
}

void Parse::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void Parse::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


antlrcpp::Any Parse::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

Parse::AssignContext* Parse::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 32, Parse::RuleAssign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Parse::SUPER:
      case Parse::THIS:
      case Parse::ID: {
        setState(223);
        var();
        break;
      }

      case Parse::LPAR: {
        setState(224);
        match(Parse::LPAR);
        setState(225);
        var();
        setState(230);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == Parse::COMMA) {
          setState(226);
          match(Parse::COMMA);
          setState(227);
          var();
          setState(232);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(233);
        match(Parse::RPAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(237);
    match(Parse::ASM);
    setState(238);
    expr(0);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

Parse::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Parse::RefContext *> Parse::VarContext::ref() {
  return getRuleContexts<Parse::RefContext>();
}

Parse::RefContext* Parse::VarContext::ref(size_t i) {
  return getRuleContext<Parse::RefContext>(i);
}

std::vector<tree::TerminalNode *> Parse::VarContext::DOT() {
  return getTokens(Parse::DOT);
}

tree::TerminalNode* Parse::VarContext::DOT(size_t i) {
  return getToken(Parse::DOT, i);
}

tree::TerminalNode* Parse::VarContext::THIS() {
  return getToken(Parse::THIS, 0);
}

tree::TerminalNode* Parse::VarContext::SUPER() {
  return getToken(Parse::SUPER, 0);
}


size_t Parse::VarContext::getRuleIndex() const {
  return Parse::RuleVar;
}

void Parse::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void Parse::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


antlrcpp::Any Parse::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

Parse::VarContext* Parse::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 34, Parse::RuleVar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(242);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Parse::SUPER

    || _la == Parse::THIS) {
      setState(240);
      _la = _input->LA(1);
      if (!(_la == Parse::SUPER

      || _la == Parse::THIS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(241);
      match(Parse::DOT);
    }
    setState(244);
    ref();
    setState(249);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(245);
        match(Parse::DOT);
        setState(246);
        ref();
      }
      setState(251);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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

Parse::RefContext::RefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::RefContext::ID() {
  return getToken(Parse::ID, 0);
}

std::vector<tree::TerminalNode *> Parse::RefContext::BL() {
  return getTokens(Parse::BL);
}

tree::TerminalNode* Parse::RefContext::BL(size_t i) {
  return getToken(Parse::BL, i);
}

std::vector<Parse::ExprContext *> Parse::RefContext::expr() {
  return getRuleContexts<Parse::ExprContext>();
}

Parse::ExprContext* Parse::RefContext::expr(size_t i) {
  return getRuleContext<Parse::ExprContext>(i);
}

std::vector<tree::TerminalNode *> Parse::RefContext::BR() {
  return getTokens(Parse::BR);
}

tree::TerminalNode* Parse::RefContext::BR(size_t i) {
  return getToken(Parse::BR, i);
}


size_t Parse::RefContext::getRuleIndex() const {
  return Parse::RuleRef;
}

void Parse::RefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRef(this);
}

void Parse::RefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRef(this);
}


antlrcpp::Any Parse::RefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitRef(this);
  else
    return visitor->visitChildren(this);
}

Parse::RefContext* Parse::ref() {
  RefContext *_localctx = _tracker.createInstance<RefContext>(_ctx, getState());
  enterRule(_localctx, 36, Parse::RuleRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(Parse::ID);
    setState(259);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(253);
        match(Parse::BL);
        setState(254);
        expr(0);
        setState(255);
        match(Parse::BR);
      }
      setState(261);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_typeContext ------------------------------------------------------------------

Parse::Array_typeContext::Array_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Parse::TypeContext* Parse::Array_typeContext::type() {
  return getRuleContext<Parse::TypeContext>(0);
}

std::vector<tree::TerminalNode *> Parse::Array_typeContext::BL() {
  return getTokens(Parse::BL);
}

tree::TerminalNode* Parse::Array_typeContext::BL(size_t i) {
  return getToken(Parse::BL, i);
}

std::vector<tree::TerminalNode *> Parse::Array_typeContext::BR() {
  return getTokens(Parse::BR);
}

tree::TerminalNode* Parse::Array_typeContext::BR(size_t i) {
  return getToken(Parse::BR, i);
}


size_t Parse::Array_typeContext::getRuleIndex() const {
  return Parse::RuleArray_type;
}

void Parse::Array_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_type(this);
}

void Parse::Array_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_type(this);
}


antlrcpp::Any Parse::Array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitArray_type(this);
  else
    return visitor->visitChildren(this);
}

Parse::Array_typeContext* Parse::array_type() {
  Array_typeContext *_localctx = _tracker.createInstance<Array_typeContext>(_ctx, getState());
  enterRule(_localctx, 38, Parse::RuleArray_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    type();
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Parse::BL) {
      setState(263);
      match(Parse::BL);
      setState(264);
      match(Parse::BR);
      setState(269);
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

Parse::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Parse::ExprContext::getRuleIndex() const {
  return Parse::RuleExpr;
}

void Parse::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Relational2OpContext ------------------------------------------------------------------

std::vector<Parse::ExprContext *> Parse::Relational2OpContext::expr() {
  return getRuleContexts<Parse::ExprContext>();
}

Parse::ExprContext* Parse::Relational2OpContext::expr(size_t i) {
  return getRuleContext<Parse::ExprContext>(i);
}

Parse::Relational2Context* Parse::Relational2OpContext::relational2() {
  return getRuleContext<Parse::Relational2Context>(0);
}

Parse::Relational2OpContext::Relational2OpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::Relational2OpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational2Op(this);
}
void Parse::Relational2OpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational2Op(this);
}

antlrcpp::Any Parse::Relational2OpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitRelational2Op(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullContext ------------------------------------------------------------------

tree::TerminalNode* Parse::NullContext::NIL() {
  return getToken(Parse::NIL, 0);
}

Parse::NullContext::NullContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::NullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNull(this);
}
void Parse::NullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNull(this);
}

antlrcpp::Any Parse::NullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitNull(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryOpContext ------------------------------------------------------------------

Parse::Unary_opContext* Parse::UnaryOpContext::unary_op() {
  return getRuleContext<Parse::Unary_opContext>(0);
}

Parse::ExprContext* Parse::UnaryOpContext::expr() {
  return getRuleContext<Parse::ExprContext>(0);
}

Parse::UnaryOpContext::UnaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}
void Parse::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}

antlrcpp::Any Parse::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FUncCallExprContext ------------------------------------------------------------------

Parse::Func_callContext* Parse::FUncCallExprContext::func_call() {
  return getRuleContext<Parse::Func_callContext>(0);
}

Parse::FUncCallExprContext::FUncCallExprContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::FUncCallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFUncCallExpr(this);
}
void Parse::FUncCallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFUncCallExpr(this);
}

antlrcpp::Any Parse::FUncCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitFUncCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Relational13OpContext ------------------------------------------------------------------

std::vector<Parse::ExprContext *> Parse::Relational13OpContext::expr() {
  return getRuleContexts<Parse::ExprContext>();
}

Parse::ExprContext* Parse::Relational13OpContext::expr(size_t i) {
  return getRuleContext<Parse::ExprContext>(i);
}

Parse::Relational1Context* Parse::Relational13OpContext::relational1() {
  return getRuleContext<Parse::Relational1Context>(0);
}

Parse::Relational3Context* Parse::Relational13OpContext::relational3() {
  return getRuleContext<Parse::Relational3Context>(0);
}

Parse::Relational13OpContext::Relational13OpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::Relational13OpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational13Op(this);
}
void Parse::Relational13OpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational13Op(this);
}

antlrcpp::Any Parse::Relational13OpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitRelational13Op(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalOpContext ------------------------------------------------------------------

std::vector<Parse::ExprContext *> Parse::LogicalOpContext::expr() {
  return getRuleContexts<Parse::ExprContext>();
}

Parse::ExprContext* Parse::LogicalOpContext::expr(size_t i) {
  return getRuleContext<Parse::ExprContext>(i);
}

Parse::LogicalContext* Parse::LogicalOpContext::logical() {
  return getRuleContext<Parse::LogicalContext>(0);
}

Parse::LogicalOpContext::LogicalOpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::LogicalOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOp(this);
}
void Parse::LogicalOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOp(this);
}

antlrcpp::Any Parse::LogicalOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitLogicalOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AllocateOpContext ------------------------------------------------------------------

tree::TerminalNode* Parse::AllocateOpContext::ALLOCATE() {
  return getToken(Parse::ALLOCATE, 0);
}

Parse::Handle_callContext* Parse::AllocateOpContext::handle_call() {
  return getRuleContext<Parse::Handle_callContext>(0);
}

Parse::AllocateOpContext::AllocateOpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::AllocateOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAllocateOp(this);
}
void Parse::AllocateOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAllocateOp(this);
}

antlrcpp::Any Parse::AllocateOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitAllocateOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstValOpContext ------------------------------------------------------------------

Parse::Const_valContext* Parse::ConstValOpContext::const_val() {
  return getRuleContext<Parse::Const_valContext>(0);
}

Parse::ConstValOpContext::ConstValOpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::ConstValOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstValOp(this);
}
void Parse::ConstValOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstValOp(this);
}

antlrcpp::Any Parse::ConstValOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitConstValOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseOpContext ------------------------------------------------------------------

std::vector<Parse::ExprContext *> Parse::BitwiseOpContext::expr() {
  return getRuleContexts<Parse::ExprContext>();
}

Parse::ExprContext* Parse::BitwiseOpContext::expr(size_t i) {
  return getRuleContext<Parse::ExprContext>(i);
}

Parse::BitwiseContext* Parse::BitwiseOpContext::bitwise() {
  return getRuleContext<Parse::BitwiseContext>(0);
}

Parse::BitwiseOpContext::BitwiseOpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::BitwiseOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwiseOp(this);
}
void Parse::BitwiseOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwiseOp(this);
}

antlrcpp::Any Parse::BitwiseOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitBitwiseOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Arithmetic2OpContext ------------------------------------------------------------------

std::vector<Parse::ExprContext *> Parse::Arithmetic2OpContext::expr() {
  return getRuleContexts<Parse::ExprContext>();
}

Parse::ExprContext* Parse::Arithmetic2OpContext::expr(size_t i) {
  return getRuleContext<Parse::ExprContext>(i);
}

Parse::Arithmetic2Context* Parse::Arithmetic2OpContext::arithmetic2() {
  return getRuleContext<Parse::Arithmetic2Context>(0);
}

Parse::Arithmetic2OpContext::Arithmetic2OpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::Arithmetic2OpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic2Op(this);
}
void Parse::Arithmetic2OpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic2Op(this);
}

antlrcpp::Any Parse::Arithmetic2OpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitArithmetic2Op(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Arithmetic1OpContext ------------------------------------------------------------------

std::vector<Parse::ExprContext *> Parse::Arithmetic1OpContext::expr() {
  return getRuleContexts<Parse::ExprContext>();
}

Parse::ExprContext* Parse::Arithmetic1OpContext::expr(size_t i) {
  return getRuleContext<Parse::ExprContext>(i);
}

Parse::Arithmetic1Context* Parse::Arithmetic1OpContext::arithmetic1() {
  return getRuleContext<Parse::Arithmetic1Context>(0);
}

Parse::Arithmetic1OpContext::Arithmetic1OpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::Arithmetic1OpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic1Op(this);
}
void Parse::Arithmetic1OpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic1Op(this);
}

antlrcpp::Any Parse::Arithmetic1OpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitArithmetic1Op(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarExprContext ------------------------------------------------------------------

Parse::VarContext* Parse::VarExprContext::var() {
  return getRuleContext<Parse::VarContext>(0);
}

Parse::VarExprContext::VarExprContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::VarExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarExpr(this);
}
void Parse::VarExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarExpr(this);
}

antlrcpp::Any Parse::VarExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitVarExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListExprContext ------------------------------------------------------------------

Parse::ListContext* Parse::ListExprContext::list() {
  return getRuleContext<Parse::ListContext>(0);
}

Parse::ListExprContext::ListExprContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::ListExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListExpr(this);
}
void Parse::ListExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListExpr(this);
}

antlrcpp::Any Parse::ListExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitListExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisOpContext ------------------------------------------------------------------

tree::TerminalNode* Parse::ParenthesisOpContext::LPAR() {
  return getToken(Parse::LPAR, 0);
}

Parse::ExprContext* Parse::ParenthesisOpContext::expr() {
  return getRuleContext<Parse::ExprContext>(0);
}

tree::TerminalNode* Parse::ParenthesisOpContext::RPAR() {
  return getToken(Parse::RPAR, 0);
}

Parse::ParenthesisOpContext::ParenthesisOpContext(ExprContext *ctx) { copyFrom(ctx); }

void Parse::ParenthesisOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesisOp(this);
}
void Parse::ParenthesisOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesisOp(this);
}

antlrcpp::Any Parse::ParenthesisOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitParenthesisOp(this);
  else
    return visitor->visitChildren(this);
}

Parse::ExprContext* Parse::expr() {
   return expr(0);
}

Parse::ExprContext* Parse::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Parse::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  Parse::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, Parse::RuleExpr, precedence);



  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(285);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(271);
      unary_op();
      setState(272);
      expr(14);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParenthesisOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(274);
      match(Parse::LPAR);
      setState(275);
      expr(0);
      setState(276);
      match(Parse::RPAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ConstValOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(278);
      const_val();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AllocateOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(279);
      match(Parse::ALLOCATE);
      setState(280);
      handle_call();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<FUncCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(281);
      func_call();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<VarExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(282);
      var();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ListExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(283);
      list();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<NullContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(284);
      match(Parse::NIL);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(316);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(314);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Arithmetic1OpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(287);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(288);
          arithmetic1();
          setState(289);
          expr(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Arithmetic2OpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(291);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(292);
          arithmetic2();
          setState(293);
          expr(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Relational13OpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(295);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(298);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case Parse::RELATIONAL1: {
              setState(296);
              relational1();
              break;
            }

            case Parse::RELATIONAL3: {
              setState(297);
              relational3();
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(300);
          expr(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Relational2OpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(302);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(303);
          relational2();
          setState(304);
          expr(11);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BitwiseOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(306);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(307);
          bitwise();
          setState(308);
          expr(10);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LogicalOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(310);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(311);
          logical();
          setState(312);
          expr(8);
          break;
        }

        }
      }
      setState(318);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
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

Parse::Func_callContext::Func_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Parse::Func_callContext::getRuleIndex() const {
  return Parse::RuleFunc_call;
}

void Parse::Func_callContext::copyFrom(Func_callContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReadFuncContext ------------------------------------------------------------------

tree::TerminalNode* Parse::ReadFuncContext::READ() {
  return getToken(Parse::READ, 0);
}

tree::TerminalNode* Parse::ReadFuncContext::LPAR() {
  return getToken(Parse::LPAR, 0);
}

tree::TerminalNode* Parse::ReadFuncContext::RPAR() {
  return getToken(Parse::RPAR, 0);
}

Parse::ReadFuncContext::ReadFuncContext(Func_callContext *ctx) { copyFrom(ctx); }

void Parse::ReadFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReadFunc(this);
}
void Parse::ReadFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReadFunc(this);
}

antlrcpp::Any Parse::ReadFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitReadFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DotClallContext ------------------------------------------------------------------

Parse::Handle_callContext* Parse::DotClallContext::handle_call() {
  return getRuleContext<Parse::Handle_callContext>(0);
}

Parse::VarContext* Parse::DotClallContext::var() {
  return getRuleContext<Parse::VarContext>(0);
}

tree::TerminalNode* Parse::DotClallContext::DOT() {
  return getToken(Parse::DOT, 0);
}

Parse::DotClallContext::DotClallContext(Func_callContext *ctx) { copyFrom(ctx); }

void Parse::DotClallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDotClall(this);
}
void Parse::DotClallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDotClall(this);
}

antlrcpp::Any Parse::DotClallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitDotClall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteFuncContext ------------------------------------------------------------------

tree::TerminalNode* Parse::WriteFuncContext::WRITE() {
  return getToken(Parse::WRITE, 0);
}

tree::TerminalNode* Parse::WriteFuncContext::LPAR() {
  return getToken(Parse::LPAR, 0);
}

Parse::ExprContext* Parse::WriteFuncContext::expr() {
  return getRuleContext<Parse::ExprContext>(0);
}

tree::TerminalNode* Parse::WriteFuncContext::RPAR() {
  return getToken(Parse::RPAR, 0);
}

Parse::WriteFuncContext::WriteFuncContext(Func_callContext *ctx) { copyFrom(ctx); }

void Parse::WriteFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteFunc(this);
}
void Parse::WriteFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteFunc(this);
}

antlrcpp::Any Parse::WriteFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitWriteFunc(this);
  else
    return visitor->visitChildren(this);
}
Parse::Func_callContext* Parse::func_call() {
  Func_callContext *_localctx = _tracker.createInstance<Func_callContext>(_ctx, getState());
  enterRule(_localctx, 42, Parse::RuleFunc_call);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(333);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Parse::SUPER:
      case Parse::THIS:
      case Parse::ID: {
        _localctx = dynamic_cast<Func_callContext *>(_tracker.createInstance<Parse::DotClallContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(322);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          setState(319);
          var();
          setState(320);
          match(Parse::DOT);
          break;
        }

        }
        setState(324);
        handle_call();
        break;
      }

      case Parse::READ: {
        _localctx = dynamic_cast<Func_callContext *>(_tracker.createInstance<Parse::ReadFuncContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(325);
        match(Parse::READ);
        setState(326);
        match(Parse::LPAR);
        setState(327);
        match(Parse::RPAR);
        break;
      }

      case Parse::WRITE: {
        _localctx = dynamic_cast<Func_callContext *>(_tracker.createInstance<Parse::WriteFuncContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(328);
        match(Parse::WRITE);
        setState(329);
        match(Parse::LPAR);
        setState(330);
        expr(0);
        setState(331);
        match(Parse::RPAR);
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

//----------------- ListContext ------------------------------------------------------------------

Parse::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::ListContext::BL() {
  return getToken(Parse::BL, 0);
}

tree::TerminalNode* Parse::ListContext::BR() {
  return getToken(Parse::BR, 0);
}

std::vector<Parse::ExprContext *> Parse::ListContext::expr() {
  return getRuleContexts<Parse::ExprContext>();
}

Parse::ExprContext* Parse::ListContext::expr(size_t i) {
  return getRuleContext<Parse::ExprContext>(i);
}

std::vector<Parse::ListContext *> Parse::ListContext::list() {
  return getRuleContexts<Parse::ListContext>();
}

Parse::ListContext* Parse::ListContext::list(size_t i) {
  return getRuleContext<Parse::ListContext>(i);
}

std::vector<tree::TerminalNode *> Parse::ListContext::COMMA() {
  return getTokens(Parse::COMMA);
}

tree::TerminalNode* Parse::ListContext::COMMA(size_t i) {
  return getToken(Parse::COMMA, i);
}


size_t Parse::ListContext::getRuleIndex() const {
  return Parse::RuleList;
}

void Parse::ListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterList(this);
}

void Parse::ListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitList(this);
}


antlrcpp::Any Parse::ListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitList(this);
  else
    return visitor->visitChildren(this);
}

Parse::ListContext* Parse::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 44, Parse::RuleList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    match(Parse::BL);
    setState(338);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(336);
      expr(0);
      break;
    }

    case 2: {
      setState(337);
      list();
      break;
    }

    }
    setState(347);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Parse::COMMA) {
      setState(340);
      match(Parse::COMMA);
      setState(343);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
      case 1: {
        setState(341);
        expr(0);
        break;
      }

      case 2: {
        setState(342);
        list();
        break;
      }

      }
      setState(349);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(350);
    match(Parse::BR);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Handle_callContext ------------------------------------------------------------------

Parse::Handle_callContext::Handle_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Handle_callContext::ID() {
  return getToken(Parse::ID, 0);
}

tree::TerminalNode* Parse::Handle_callContext::LPAR() {
  return getToken(Parse::LPAR, 0);
}

tree::TerminalNode* Parse::Handle_callContext::RPAR() {
  return getToken(Parse::RPAR, 0);
}

Parse::ParamsContext* Parse::Handle_callContext::params() {
  return getRuleContext<Parse::ParamsContext>(0);
}


size_t Parse::Handle_callContext::getRuleIndex() const {
  return Parse::RuleHandle_call;
}

void Parse::Handle_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHandle_call(this);
}

void Parse::Handle_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHandle_call(this);
}


antlrcpp::Any Parse::Handle_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitHandle_call(this);
  else
    return visitor->visitChildren(this);
}

Parse::Handle_callContext* Parse::handle_call() {
  Handle_callContext *_localctx = _tracker.createInstance<Handle_callContext>(_ctx, getState());
  enterRule(_localctx, 46, Parse::RuleHandle_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    match(Parse::ID);
    setState(353);
    match(Parse::LPAR);
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Parse::UNARY_OP)
      | (1ULL << Parse::INT_CONST)
      | (1ULL << Parse::BOOL_CONST)
      | (1ULL << Parse::REAL_CONST)
      | (1ULL << Parse::STRING_CONST)
      | (1ULL << Parse::ALLOCATE)
      | (1ULL << Parse::NIL)
      | (1ULL << Parse::READ)
      | (1ULL << Parse::WRITE)
      | (1ULL << Parse::SUPER)
      | (1ULL << Parse::THIS)
      | (1ULL << Parse::LPAR))) != 0) || _la == Parse::BL

    || _la == Parse::ID) {
      setState(354);
      params();
    }
    setState(357);
    match(Parse::RPAR);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_bodyContext ------------------------------------------------------------------

Parse::Switch_bodyContext::Switch_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> Parse::Switch_bodyContext::CASEOF() {
  return getTokens(Parse::CASEOF);
}

tree::TerminalNode* Parse::Switch_bodyContext::CASEOF(size_t i) {
  return getToken(Parse::CASEOF, i);
}

std::vector<tree::TerminalNode *> Parse::Switch_bodyContext::INT_CONST() {
  return getTokens(Parse::INT_CONST);
}

tree::TerminalNode* Parse::Switch_bodyContext::INT_CONST(size_t i) {
  return getToken(Parse::INT_CONST, i);
}

std::vector<tree::TerminalNode *> Parse::Switch_bodyContext::COLON() {
  return getTokens(Parse::COLON);
}

tree::TerminalNode* Parse::Switch_bodyContext::COLON(size_t i) {
  return getToken(Parse::COLON, i);
}

std::vector<Parse::BlockContext *> Parse::Switch_bodyContext::block() {
  return getRuleContexts<Parse::BlockContext>();
}

Parse::BlockContext* Parse::Switch_bodyContext::block(size_t i) {
  return getRuleContext<Parse::BlockContext>(i);
}

tree::TerminalNode* Parse::Switch_bodyContext::DEFAULT() {
  return getToken(Parse::DEFAULT, 0);
}


size_t Parse::Switch_bodyContext::getRuleIndex() const {
  return Parse::RuleSwitch_body;
}

void Parse::Switch_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch_body(this);
}

void Parse::Switch_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch_body(this);
}


antlrcpp::Any Parse::Switch_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitSwitch_body(this);
  else
    return visitor->visitChildren(this);
}

Parse::Switch_bodyContext* Parse::switch_body() {
  Switch_bodyContext *_localctx = _tracker.createInstance<Switch_bodyContext>(_ctx, getState());
  enterRule(_localctx, 48, Parse::RuleSwitch_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(359);
      match(Parse::CASEOF);
      setState(360);
      match(Parse::INT_CONST);
      setState(361);
      match(Parse::COLON);
      setState(362);
      block();
      setState(365);
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == Parse::CASEOF);
    setState(370);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Parse::DEFAULT) {
      setState(367);
      match(Parse::DEFAULT);
      setState(368);
      match(Parse::COLON);
      setState(369);
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

//----------------- ParamsContext ------------------------------------------------------------------

Parse::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Parse::ExprContext *> Parse::ParamsContext::expr() {
  return getRuleContexts<Parse::ExprContext>();
}

Parse::ExprContext* Parse::ParamsContext::expr(size_t i) {
  return getRuleContext<Parse::ExprContext>(i);
}

std::vector<tree::TerminalNode *> Parse::ParamsContext::COMMA() {
  return getTokens(Parse::COMMA);
}

tree::TerminalNode* Parse::ParamsContext::COMMA(size_t i) {
  return getToken(Parse::COMMA, i);
}


size_t Parse::ParamsContext::getRuleIndex() const {
  return Parse::RuleParams;
}

void Parse::ParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams(this);
}

void Parse::ParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams(this);
}


antlrcpp::Any Parse::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

Parse::ParamsContext* Parse::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 50, Parse::RuleParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    expr(0);
    setState(377);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Parse::COMMA) {
      setState(373);
      match(Parse::COMMA);
      setState(374);
      expr(0);
      setState(379);
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

//----------------- Cond_stmtContext ------------------------------------------------------------------

Parse::Cond_stmtContext::Cond_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Parse::Cond_stmtContext::getRuleIndex() const {
  return Parse::RuleCond_stmt;
}

void Parse::Cond_stmtContext::copyFrom(Cond_stmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SwitchCondContext ------------------------------------------------------------------

tree::TerminalNode* Parse::SwitchCondContext::SWITCH() {
  return getToken(Parse::SWITCH, 0);
}

Parse::VarContext* Parse::SwitchCondContext::var() {
  return getRuleContext<Parse::VarContext>(0);
}

tree::TerminalNode* Parse::SwitchCondContext::CLPAR() {
  return getToken(Parse::CLPAR, 0);
}

Parse::Switch_bodyContext* Parse::SwitchCondContext::switch_body() {
  return getRuleContext<Parse::Switch_bodyContext>(0);
}

tree::TerminalNode* Parse::SwitchCondContext::CRPAR() {
  return getToken(Parse::CRPAR, 0);
}

Parse::SwitchCondContext::SwitchCondContext(Cond_stmtContext *ctx) { copyFrom(ctx); }

void Parse::SwitchCondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchCond(this);
}
void Parse::SwitchCondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchCond(this);
}

antlrcpp::Any Parse::SwitchCondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitSwitchCond(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfElseCondContext ------------------------------------------------------------------

Parse::IfBlockContext* Parse::IfElseCondContext::ifBlock() {
  return getRuleContext<Parse::IfBlockContext>(0);
}

Parse::ElseBlockContext* Parse::IfElseCondContext::elseBlock() {
  return getRuleContext<Parse::ElseBlockContext>(0);
}

Parse::IfElseCondContext::IfElseCondContext(Cond_stmtContext *ctx) { copyFrom(ctx); }

void Parse::IfElseCondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfElseCond(this);
}
void Parse::IfElseCondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfElseCond(this);
}

antlrcpp::Any Parse::IfElseCondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitIfElseCond(this);
  else
    return visitor->visitChildren(this);
}
Parse::Cond_stmtContext* Parse::cond_stmt() {
  Cond_stmtContext *_localctx = _tracker.createInstance<Cond_stmtContext>(_ctx, getState());
  enterRule(_localctx, 52, Parse::RuleCond_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(390);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Parse::IF: {
        _localctx = dynamic_cast<Cond_stmtContext *>(_tracker.createInstance<Parse::IfElseCondContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(380);
        ifBlock();
        setState(382);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
        case 1: {
          setState(381);
          elseBlock();
          break;
        }

        }
        break;
      }

      case Parse::SWITCH: {
        _localctx = dynamic_cast<Cond_stmtContext *>(_tracker.createInstance<Parse::SwitchCondContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(384);
        match(Parse::SWITCH);
        setState(385);
        var();
        setState(386);
        match(Parse::CLPAR);
        setState(387);
        switch_body();
        setState(388);
        match(Parse::CRPAR);
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

//----------------- IfBlockContext ------------------------------------------------------------------

Parse::IfBlockContext::IfBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::IfBlockContext::IF() {
  return getToken(Parse::IF, 0);
}

Parse::ExprContext* Parse::IfBlockContext::expr() {
  return getRuleContext<Parse::ExprContext>(0);
}

Parse::BlockContext* Parse::IfBlockContext::block() {
  return getRuleContext<Parse::BlockContext>(0);
}

Parse::StmtContext* Parse::IfBlockContext::stmt() {
  return getRuleContext<Parse::StmtContext>(0);
}


size_t Parse::IfBlockContext::getRuleIndex() const {
  return Parse::RuleIfBlock;
}

void Parse::IfBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfBlock(this);
}

void Parse::IfBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfBlock(this);
}


antlrcpp::Any Parse::IfBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitIfBlock(this);
  else
    return visitor->visitChildren(this);
}

Parse::IfBlockContext* Parse::ifBlock() {
  IfBlockContext *_localctx = _tracker.createInstance<IfBlockContext>(_ctx, getState());
  enterRule(_localctx, 54, Parse::RuleIfBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(392);
    match(Parse::IF);
    setState(393);
    expr(0);
    setState(396);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Parse::CLPAR: {
        setState(394);
        block();
        break;
      }

      case Parse::FOR:
      case Parse::WHILE:
      case Parse::DESTRUCT:
      case Parse::IF:
      case Parse::BREAK:
      case Parse::CONTINUE:
      case Parse::READ:
      case Parse::WRITE:
      case Parse::SUPER:
      case Parse::THIS:
      case Parse::SWITCH:
      case Parse::LPAR:
      case Parse::ID: {
        setState(395);
        stmt();
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

//----------------- ElseBlockContext ------------------------------------------------------------------

Parse::ElseBlockContext::ElseBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::ElseBlockContext::ELSE() {
  return getToken(Parse::ELSE, 0);
}

Parse::BlockContext* Parse::ElseBlockContext::block() {
  return getRuleContext<Parse::BlockContext>(0);
}

Parse::StmtContext* Parse::ElseBlockContext::stmt() {
  return getRuleContext<Parse::StmtContext>(0);
}


size_t Parse::ElseBlockContext::getRuleIndex() const {
  return Parse::RuleElseBlock;
}

void Parse::ElseBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseBlock(this);
}

void Parse::ElseBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseBlock(this);
}


antlrcpp::Any Parse::ElseBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitElseBlock(this);
  else
    return visitor->visitChildren(this);
}

Parse::ElseBlockContext* Parse::elseBlock() {
  ElseBlockContext *_localctx = _tracker.createInstance<ElseBlockContext>(_ctx, getState());
  enterRule(_localctx, 56, Parse::RuleElseBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(398);
    match(Parse::ELSE);
    setState(401);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Parse::CLPAR: {
        setState(399);
        block();
        break;
      }

      case Parse::FOR:
      case Parse::WHILE:
      case Parse::DESTRUCT:
      case Parse::IF:
      case Parse::BREAK:
      case Parse::CONTINUE:
      case Parse::READ:
      case Parse::WRITE:
      case Parse::SUPER:
      case Parse::THIS:
      case Parse::SWITCH:
      case Parse::LPAR:
      case Parse::ID: {
        setState(400);
        stmt();
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

//----------------- Loop_stmtContext ------------------------------------------------------------------

Parse::Loop_stmtContext::Loop_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Parse::Loop_stmtContext::getRuleIndex() const {
  return Parse::RuleLoop_stmt;
}

void Parse::Loop_stmtContext::copyFrom(Loop_stmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ForLoopContext ------------------------------------------------------------------

tree::TerminalNode* Parse::ForLoopContext::FOR() {
  return getToken(Parse::FOR, 0);
}

std::vector<tree::TerminalNode *> Parse::ForLoopContext::SEMIC() {
  return getTokens(Parse::SEMIC);
}

tree::TerminalNode* Parse::ForLoopContext::SEMIC(size_t i) {
  return getToken(Parse::SEMIC, i);
}

Parse::ExprContext* Parse::ForLoopContext::expr() {
  return getRuleContext<Parse::ExprContext>(0);
}

Parse::BlockContext* Parse::ForLoopContext::block() {
  return getRuleContext<Parse::BlockContext>(0);
}

std::vector<Parse::AssignContext *> Parse::ForLoopContext::assign() {
  return getRuleContexts<Parse::AssignContext>();
}

Parse::AssignContext* Parse::ForLoopContext::assign(size_t i) {
  return getRuleContext<Parse::AssignContext>(i);
}

Parse::TypeContext* Parse::ForLoopContext::type() {
  return getRuleContext<Parse::TypeContext>(0);
}

Parse::ForLoopContext::ForLoopContext(Loop_stmtContext *ctx) { copyFrom(ctx); }

void Parse::ForLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForLoop(this);
}
void Parse::ForLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForLoop(this);
}

antlrcpp::Any Parse::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileLoopContext ------------------------------------------------------------------

tree::TerminalNode* Parse::WhileLoopContext::WHILE() {
  return getToken(Parse::WHILE, 0);
}

Parse::ExprContext* Parse::WhileLoopContext::expr() {
  return getRuleContext<Parse::ExprContext>(0);
}

Parse::BlockContext* Parse::WhileLoopContext::block() {
  return getRuleContext<Parse::BlockContext>(0);
}

Parse::StmtContext* Parse::WhileLoopContext::stmt() {
  return getRuleContext<Parse::StmtContext>(0);
}

Parse::WhileLoopContext::WhileLoopContext(Loop_stmtContext *ctx) { copyFrom(ctx); }

void Parse::WhileLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileLoop(this);
}
void Parse::WhileLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileLoop(this);
}

antlrcpp::Any Parse::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}
Parse::Loop_stmtContext* Parse::loop_stmt() {
  Loop_stmtContext *_localctx = _tracker.createInstance<Loop_stmtContext>(_ctx, getState());
  enterRule(_localctx, 58, Parse::RuleLoop_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(424);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Parse::FOR: {
        _localctx = dynamic_cast<Loop_stmtContext *>(_tracker.createInstance<Parse::ForLoopContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(403);
        match(Parse::FOR);
        setState(408);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 25) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 25)) & ((1ULL << (Parse::BOOL - 25))
          | (1ULL << (Parse::INT - 25))
          | (1ULL << (Parse::FLOAT - 25))
          | (1ULL << (Parse::STRING - 25))
          | (1ULL << (Parse::SUPER - 25))
          | (1ULL << (Parse::THIS - 25))
          | (1ULL << (Parse::LPAR - 25))
          | (1ULL << (Parse::ID - 25)))) != 0)) {
          setState(405);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
          case 1: {
            setState(404);
            type();
            break;
          }

          }
          setState(407);
          assign();
        }
        setState(410);
        match(Parse::SEMIC);
        setState(411);
        expr(0);
        setState(412);
        match(Parse::SEMIC);
        setState(414);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 36) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 36)) & ((1ULL << (Parse::SUPER - 36))
          | (1ULL << (Parse::THIS - 36))
          | (1ULL << (Parse::LPAR - 36))
          | (1ULL << (Parse::ID - 36)))) != 0)) {
          setState(413);
          assign();
        }
        setState(416);
        block();
        break;
      }

      case Parse::WHILE: {
        _localctx = dynamic_cast<Loop_stmtContext *>(_tracker.createInstance<Parse::WhileLoopContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(418);
        match(Parse::WHILE);
        setState(419);
        expr(0);
        setState(422);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case Parse::CLPAR: {
            setState(420);
            block();
            break;
          }

          case Parse::FOR:
          case Parse::WHILE:
          case Parse::DESTRUCT:
          case Parse::IF:
          case Parse::BREAK:
          case Parse::CONTINUE:
          case Parse::READ:
          case Parse::WRITE:
          case Parse::SUPER:
          case Parse::THIS:
          case Parse::SWITCH:
          case Parse::LPAR:
          case Parse::ID: {
            setState(421);
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

Parse::Const_valContext::Const_valContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Const_valContext::INT_CONST() {
  return getToken(Parse::INT_CONST, 0);
}

tree::TerminalNode* Parse::Const_valContext::REAL_CONST() {
  return getToken(Parse::REAL_CONST, 0);
}

tree::TerminalNode* Parse::Const_valContext::BOOL_CONST() {
  return getToken(Parse::BOOL_CONST, 0);
}

tree::TerminalNode* Parse::Const_valContext::STRING_CONST() {
  return getToken(Parse::STRING_CONST, 0);
}


size_t Parse::Const_valContext::getRuleIndex() const {
  return Parse::RuleConst_val;
}

void Parse::Const_valContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_val(this);
}

void Parse::Const_valContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_val(this);
}


antlrcpp::Any Parse::Const_valContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitConst_val(this);
  else
    return visitor->visitChildren(this);
}

Parse::Const_valContext* Parse::const_val() {
  Const_valContext *_localctx = _tracker.createInstance<Const_valContext>(_ctx, getState());
  enterRule(_localctx, 60, Parse::RuleConst_val);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Parse::INT_CONST)
      | (1ULL << Parse::BOOL_CONST)
      | (1ULL << Parse::REAL_CONST)
      | (1ULL << Parse::STRING_CONST))) != 0))) {
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

//----------------- Relational1Context ------------------------------------------------------------------

Parse::Relational1Context::Relational1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Relational1Context::RELATIONAL1() {
  return getToken(Parse::RELATIONAL1, 0);
}


size_t Parse::Relational1Context::getRuleIndex() const {
  return Parse::RuleRelational1;
}

void Parse::Relational1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational1(this);
}

void Parse::Relational1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational1(this);
}


antlrcpp::Any Parse::Relational1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitRelational1(this);
  else
    return visitor->visitChildren(this);
}

Parse::Relational1Context* Parse::relational1() {
  Relational1Context *_localctx = _tracker.createInstance<Relational1Context>(_ctx, getState());
  enterRule(_localctx, 62, Parse::RuleRelational1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(Parse::RELATIONAL1);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relational2Context ------------------------------------------------------------------

Parse::Relational2Context::Relational2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Relational2Context::RELATIONAL2() {
  return getToken(Parse::RELATIONAL2, 0);
}


size_t Parse::Relational2Context::getRuleIndex() const {
  return Parse::RuleRelational2;
}

void Parse::Relational2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational2(this);
}

void Parse::Relational2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational2(this);
}


antlrcpp::Any Parse::Relational2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitRelational2(this);
  else
    return visitor->visitChildren(this);
}

Parse::Relational2Context* Parse::relational2() {
  Relational2Context *_localctx = _tracker.createInstance<Relational2Context>(_ctx, getState());
  enterRule(_localctx, 64, Parse::RuleRelational2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    match(Parse::RELATIONAL2);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relational3Context ------------------------------------------------------------------

Parse::Relational3Context::Relational3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Relational3Context::RELATIONAL3() {
  return getToken(Parse::RELATIONAL3, 0);
}


size_t Parse::Relational3Context::getRuleIndex() const {
  return Parse::RuleRelational3;
}

void Parse::Relational3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational3(this);
}

void Parse::Relational3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational3(this);
}


antlrcpp::Any Parse::Relational3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitRelational3(this);
  else
    return visitor->visitChildren(this);
}

Parse::Relational3Context* Parse::relational3() {
  Relational3Context *_localctx = _tracker.createInstance<Relational3Context>(_ctx, getState());
  enterRule(_localctx, 66, Parse::RuleRelational3);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(Parse::RELATIONAL3);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arithmetic1Context ------------------------------------------------------------------

Parse::Arithmetic1Context::Arithmetic1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Arithmetic1Context::ARITHMETIC1() {
  return getToken(Parse::ARITHMETIC1, 0);
}


size_t Parse::Arithmetic1Context::getRuleIndex() const {
  return Parse::RuleArithmetic1;
}

void Parse::Arithmetic1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic1(this);
}

void Parse::Arithmetic1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic1(this);
}


antlrcpp::Any Parse::Arithmetic1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitArithmetic1(this);
  else
    return visitor->visitChildren(this);
}

Parse::Arithmetic1Context* Parse::arithmetic1() {
  Arithmetic1Context *_localctx = _tracker.createInstance<Arithmetic1Context>(_ctx, getState());
  enterRule(_localctx, 68, Parse::RuleArithmetic1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    match(Parse::ARITHMETIC1);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arithmetic2Context ------------------------------------------------------------------

Parse::Arithmetic2Context::Arithmetic2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Arithmetic2Context::ARITHMETIC2() {
  return getToken(Parse::ARITHMETIC2, 0);
}


size_t Parse::Arithmetic2Context::getRuleIndex() const {
  return Parse::RuleArithmetic2;
}

void Parse::Arithmetic2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic2(this);
}

void Parse::Arithmetic2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic2(this);
}


antlrcpp::Any Parse::Arithmetic2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitArithmetic2(this);
  else
    return visitor->visitChildren(this);
}

Parse::Arithmetic2Context* Parse::arithmetic2() {
  Arithmetic2Context *_localctx = _tracker.createInstance<Arithmetic2Context>(_ctx, getState());
  enterRule(_localctx, 70, Parse::RuleArithmetic2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(436);
    match(Parse::ARITHMETIC2);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalContext ------------------------------------------------------------------

Parse::LogicalContext::LogicalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::LogicalContext::LOGICAL() {
  return getToken(Parse::LOGICAL, 0);
}


size_t Parse::LogicalContext::getRuleIndex() const {
  return Parse::RuleLogical;
}

void Parse::LogicalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical(this);
}

void Parse::LogicalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical(this);
}


antlrcpp::Any Parse::LogicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitLogical(this);
  else
    return visitor->visitChildren(this);
}

Parse::LogicalContext* Parse::logical() {
  LogicalContext *_localctx = _tracker.createInstance<LogicalContext>(_ctx, getState());
  enterRule(_localctx, 72, Parse::RuleLogical);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    match(Parse::LOGICAL);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_opContext ------------------------------------------------------------------

Parse::Unary_opContext::Unary_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::Unary_opContext::UNARY_OP() {
  return getToken(Parse::UNARY_OP, 0);
}


size_t Parse::Unary_opContext::getRuleIndex() const {
  return Parse::RuleUnary_op;
}

void Parse::Unary_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_op(this);
}

void Parse::Unary_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_op(this);
}


antlrcpp::Any Parse::Unary_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitUnary_op(this);
  else
    return visitor->visitChildren(this);
}

Parse::Unary_opContext* Parse::unary_op() {
  Unary_opContext *_localctx = _tracker.createInstance<Unary_opContext>(_ctx, getState());
  enterRule(_localctx, 74, Parse::RuleUnary_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    match(Parse::UNARY_OP);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitwiseContext ------------------------------------------------------------------

Parse::BitwiseContext::BitwiseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::BitwiseContext::BITWISE() {
  return getToken(Parse::BITWISE, 0);
}


size_t Parse::BitwiseContext::getRuleIndex() const {
  return Parse::RuleBitwise;
}

void Parse::BitwiseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwise(this);
}

void Parse::BitwiseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwise(this);
}


antlrcpp::Any Parse::BitwiseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitBitwise(this);
  else
    return visitor->visitChildren(this);
}

Parse::BitwiseContext* Parse::bitwise() {
  BitwiseContext *_localctx = _tracker.createInstance<BitwiseContext>(_ctx, getState());
  enterRule(_localctx, 76, Parse::RuleBitwise);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(442);
    match(Parse::BITWISE);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartContext ------------------------------------------------------------------

Parse::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Parse::StartContext::START() {
  return getToken(Parse::START, 0);
}


size_t Parse::StartContext::getRuleIndex() const {
  return Parse::RuleStart;
}

void Parse::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void Parse::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any Parse::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ParseVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

Parse::StartContext* Parse::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 78, Parse::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    match(Parse::START);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool Parse::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 20: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool Parse::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);
    case 4: return precpred(_ctx, 9);
    case 5: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> Parse::_decisionToDFA;
atn::PredictionContextCache Parse::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN Parse::_atn;
std::vector<uint16_t> Parse::_serializedATN;

std::vector<std::string> Parse::_ruleNames = {
  "program", "start_func", "ft_def", "type_def", "component", "field_def",
  "method_def", "access_modifier", "var_def", "type", "var_val", "fun_def",
  "def_args", "args_var", "block", "stmt", "assign", "var", "ref", "array_type",
  "expr", "func_call", "list", "handle_call", "switch_body", "params", "cond_stmt",
  "ifBlock", "elseBlock", "loop_stmt", "const_val", "relational1", "relational2",
  "relational3", "arithmetic1", "arithmetic2", "logical", "unary_op", "bitwise",
  "start"
};

std::vector<std::string> Parse::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "'for'", "'while'",
  "'allocate'", "'destruct'", "'if'", "'else'", "'break'", "'caseof'", "'continue'",
  "'default'", "'function'", "'nil'", "'bool'", "'type'", "'int'", "'float'",
  "'string'", "'const'", "'read'", "'write'", "'public'", "'private'", "'protected'",
  "'super'", "'this'", "'switch'", "'true'", "'false'", "'start'", "'*'",
  "'!='", "'<='", "'>='", "'&&'", "'||'", "'<'", "'>'", "'!'", "'~'", "'&'",
  "'|'", "'%'", "';'", "':'", "','", "'=='", "'='", "'+'", "'-'", "'/'",
  "'('", "')'", "'{'", "'}'", "']'", "'['", "'.'"
};

std::vector<std::string> Parse::_symbolicNames = {
  "", "UNARY_OP", "BITWISE", "LOGICAL", "RELATIONAL1", "RELATIONAL2", "RELATIONAL3",
  "ARITHMETIC1", "ARITHMETIC2", "INT_CONST", "BOOL_CONST", "REAL_CONST",
  "STRING_CONST", "FOR", "WHILE", "ALLOCATE", "DESTRUCT", "IF", "ELSE",
  "BREAK", "CASEOF", "CONTINUE", "DEFAULT", "FUNCTION", "NIL", "BOOL", "TYPE",
  "INT", "FLOAT", "STRING", "CONST", "READ", "WRITE", "PUBLIC", "PRIVATE",
  "PROTECTED", "SUPER", "THIS", "SWITCH", "TRUE", "FALSE", "START", "STAR",
  "OP_NE", "OP_LE", "OP_GE", "OP_AND", "OP_OR", "LT", "GT", "BANG", "TILDE",
  "AMP", "BITWISE_OR", "PERCENT", "SEMIC", "COLON", "COMMA", "EQ", "ASM",
  "PLUS", "MINUS", "DIV", "LPAR", "RPAR", "CLPAR", "CRPAR", "BR", "BL",
  "DOT", "WhiteSpace", "Comment", "INTEGER", "ID"
};

dfa::Vocabulary Parse::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> Parse::_tokenNames;

Parse::Initializer::Initializer() {
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
    0x3, 0x4b, 0x1c1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4,
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7,
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb,
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe,
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4,
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15,
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9,
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b,
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4,
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22,
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9,
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28,
    0x4, 0x29, 0x9, 0x29, 0x3, 0x2, 0x7, 0x2, 0x54, 0xa, 0x2, 0xc, 0x2,
    0xe, 0x2, 0x57, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x5b, 0xa, 0x2,
    0xc, 0x2, 0xe, 0x2, 0x5e, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3,
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x6f, 0xa, 0x4,
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x75, 0xa, 0x5, 0x3,
    0x5, 0x3, 0x5, 0x6, 0x5, 0x79, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x7a, 0x3,
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x81, 0xa, 0x6, 0x3, 0x7,
    0x5, 0x7, 0x84, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x5, 0x8, 0x89,
    0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x5, 0xa,
    0x90, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x96,
    0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x99, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3,
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa2, 0xa, 0xc,
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xa9, 0xa,
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3,
    0xd, 0x3, 0xe, 0x5, 0xe, 0xb3, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf,
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xbb, 0xa, 0xf, 0xc, 0xf, 0xe,
    0xf, 0xbe, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xc3,
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xc6, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10,
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3,
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11,
    0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xd9, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11,
    0xdc, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xe0, 0xa, 0x11, 0x3,
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xe7, 0xa,
    0x12, 0xc, 0x12, 0xe, 0x12, 0xea, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5,
    0x12, 0xee, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3,
    0x13, 0x5, 0x13, 0xf5, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7,
    0x13, 0xfa, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xfd, 0xb, 0x13, 0x3, 0x14,
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x104, 0xa, 0x14,
    0xc, 0x14, 0xe, 0x14, 0x107, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15,
    0x7, 0x15, 0x10c, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x10f, 0xb, 0x15,
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3,
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16,
    0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x120, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16,
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3,
    0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x12d, 0xa, 0x16, 0x3, 0x16,
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3,
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16,
    0x7, 0x16, 0x13d, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x140, 0xb, 0x16,
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x145, 0xa, 0x17, 0x3, 0x17,
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3,
    0x17, 0x3, 0x17, 0x5, 0x17, 0x150, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18,
    0x3, 0x18, 0x5, 0x18, 0x155, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18,
    0x5, 0x18, 0x15a, 0xa, 0x18, 0x7, 0x18, 0x15c, 0xa, 0x18, 0xc, 0x18,
    0xe, 0x18, 0x15f, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19,
    0x3, 0x19, 0x5, 0x19, 0x166, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a,
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x6, 0x1a, 0x16e, 0xa, 0x1a, 0xd, 0x1a,
    0xe, 0x1a, 0x16f, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x175,
    0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x17a, 0xa, 0x1b,
    0xc, 0x1b, 0xe, 0x1b, 0x17d, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c,
    0x181, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c,
    0x3, 0x1c, 0x5, 0x1c, 0x189, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d,
    0x3, 0x1d, 0x5, 0x1d, 0x18f, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e,
    0x5, 0x1e, 0x194, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x198,
    0xa, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x19b, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f,
    0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1a1, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f,
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1a9, 0xa, 0x1f,
    0x5, 0x1f, 0x1ab, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21,
    0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3,
    0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28,
    0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x2, 0x3, 0x2a, 0x2a, 0x2,
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c,
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34,
    0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c,
    0x4e, 0x50, 0x2, 0x6, 0x3, 0x2, 0x23, 0x25, 0x5, 0x2, 0x1b, 0x1b, 0x1d,
    0x1f, 0x4b, 0x4b, 0x3, 0x2, 0x26, 0x27, 0x3, 0x2, 0xb, 0xe, 0x2, 0x1d6,
    0x2, 0x55, 0x3, 0x2, 0x2, 0x2, 0x4, 0x61, 0x3, 0x2, 0x2, 0x2, 0x6, 0x6e,
    0x3, 0x2, 0x2, 0x2, 0x8, 0x70, 0x3, 0x2, 0x2, 0x2, 0xa, 0x80, 0x3, 0x2,
    0x2, 0x2, 0xc, 0x83, 0x3, 0x2, 0x2, 0x2, 0xe, 0x88, 0x3, 0x2, 0x2, 0x2,
    0x10, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x14,
    0x9c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa8,
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xb4, 0x3,
    0x2, 0x2, 0x2, 0x1e, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x20, 0xdf, 0x3, 0x2,
    0x2, 0x2, 0x22, 0xed, 0x3, 0x2, 0x2, 0x2, 0x24, 0xf4, 0x3, 0x2, 0x2,
    0x2, 0x26, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x28, 0x108, 0x3, 0x2, 0x2, 0x2,
    0x2a, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x2e,
    0x151, 0x3, 0x2, 0x2, 0x2, 0x30, 0x162, 0x3, 0x2, 0x2, 0x2, 0x32, 0x16d,
    0x3, 0x2, 0x2, 0x2, 0x34, 0x176, 0x3, 0x2, 0x2, 0x2, 0x36, 0x188, 0x3,
    0x2, 0x2, 0x2, 0x38, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x190, 0x3, 0x2,
    0x2, 0x2, 0x3c, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1ac, 0x3, 0x2, 0x2,
    0x2, 0x40, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1b0, 0x3, 0x2, 0x2, 0x2,
    0x44, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x48,
    0x1b6, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1ba,
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1be, 0x3,
    0x2, 0x2, 0x2, 0x52, 0x54, 0x5, 0x6, 0x4, 0x2, 0x53, 0x52, 0x3, 0x2,
    0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2,
    0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 0x2,
    0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5c, 0x5, 0x4, 0x3, 0x2, 0x59,
    0x5b, 0x5, 0x6, 0x4, 0x2, 0x5a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5e,
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3,
    0x2, 0x2, 0x2, 0x5d, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2,
    0x2, 0x2, 0x5f, 0x60, 0x7, 0x2, 0x2, 0x3, 0x60, 0x3, 0x3, 0x2, 0x2,
    0x2, 0x61, 0x62, 0x7, 0x41, 0x2, 0x2, 0x62, 0x63, 0x7, 0x1d, 0x2, 0x2,
    0x63, 0x64, 0x7, 0x4b, 0x2, 0x2, 0x64, 0x65, 0x7, 0x42, 0x2, 0x2, 0x65,
    0x66, 0x7, 0x3d, 0x2, 0x2, 0x66, 0x67, 0x7, 0x19, 0x2, 0x2, 0x67, 0x68,
    0x5, 0x50, 0x29, 0x2, 0x68, 0x69, 0x7, 0x41, 0x2, 0x2, 0x69, 0x6a, 0x7,
    0x42, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0x1e, 0x10, 0x2, 0x6b, 0x5, 0x3, 0x2,
    0x2, 0x2, 0x6c, 0x6f, 0x5, 0x8, 0x5, 0x2, 0x6d, 0x6f, 0x5, 0x18, 0xd,
    0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6d, 0x3, 0x2, 0x2, 0x2,
    0x6f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x1c, 0x2, 0x2, 0x71,
    0x74, 0x7, 0x4b, 0x2, 0x2, 0x72, 0x73, 0x7, 0x3a, 0x2, 0x2, 0x73, 0x75,
    0x7, 0x4b, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3,
    0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 0x7, 0x43,
    0x2, 0x2, 0x77, 0x79, 0x5, 0xa, 0x6, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2,
    0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2,
    0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7c,
    0x7d, 0x7, 0x44, 0x2, 0x2, 0x7d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81,
    0x5, 0xc, 0x7, 0x2, 0x7f, 0x81, 0x5, 0xe, 0x8, 0x2, 0x80, 0x7e, 0x3,
    0x2, 0x2, 0x2, 0x80, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0xb, 0x3, 0x2,
    0x2, 0x2, 0x82, 0x84, 0x5, 0x10, 0x9, 0x2, 0x83, 0x82, 0x3, 0x2, 0x2,
    0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2,
    0x85, 0x86, 0x5, 0x12, 0xa, 0x2, 0x86, 0xd, 0x3, 0x2, 0x2, 0x2, 0x87,
    0x89, 0x5, 0x10, 0x9, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89,
    0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x5,
    0x18, 0xd, 0x2, 0x8b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x9, 0x2,
    0x2, 0x2, 0x8d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x90, 0x7, 0x20, 0x2,
    0x2, 0x8f, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2,
    0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x5, 0x14, 0xb, 0x2, 0x92,
    0x97, 0x5, 0x16, 0xc, 0x2, 0x93, 0x94, 0x7, 0x3b, 0x2, 0x2, 0x94, 0x96,
    0x5, 0x16, 0xc, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x96, 0x99, 0x3,
    0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x3, 0x2,
    0x2, 0x2, 0x98, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2,
    0x2, 0x9a, 0x9b, 0x7, 0x39, 0x2, 0x2, 0x9b, 0x13, 0x3, 0x2, 0x2, 0x2,
    0x9c, 0x9d, 0x9, 0x3, 0x2, 0x2, 0x9d, 0x15, 0x3, 0x2, 0x2, 0x2, 0x9e,
    0xa1, 0x5, 0x26, 0x14, 0x2, 0x9f, 0xa0, 0x7, 0x3d, 0x2, 0x2, 0xa0, 0xa2,
    0x5, 0x2a, 0x16, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3,
    0x2, 0x2, 0x2, 0xa2, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x41,
    0x2, 0x2, 0xa4, 0xa5, 0x5, 0x1c, 0xf, 0x2, 0xa5, 0xa6, 0x7, 0x42, 0x2,
    0x2, 0xa6, 0xa7, 0x7, 0x3d, 0x2, 0x2, 0xa7, 0xa9, 0x3, 0x2, 0x2, 0x2,
    0xa8, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9,
    0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x19, 0x2, 0x2, 0xab, 0xac,
    0x7, 0x4b, 0x2, 0x2, 0xac, 0xad, 0x7, 0x41, 0x2, 0x2, 0xad, 0xae, 0x5,
    0x1a, 0xe, 0x2, 0xae, 0xaf, 0x7, 0x42, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x1e,
    0x10, 0x2, 0xb0, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb3, 0x5, 0x1c, 0xf,
    0x2, 0xb2, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2,
    0xb3, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x28, 0x15, 0x2, 0xb5,
    0xbc, 0x7, 0x4b, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x3b, 0x2, 0x2, 0xb7, 0xb8,
    0x5, 0x28, 0x15, 0x2, 0xb8, 0xb9, 0x7, 0x4b, 0x2, 0x2, 0xb9, 0xbb, 0x3,
    0x2, 0x2, 0x2, 0xba, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 0x3, 0x2,
    0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2,
    0x2, 0xbd, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2,
    0xbf, 0xc4, 0x7, 0x43, 0x2, 0x2, 0xc0, 0xc3, 0x5, 0x12, 0xa, 0x2, 0xc1,
    0xc3, 0x5, 0x20, 0x11, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc1,
    0x3, 0x2, 0x2, 0x2, 0xc3, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3,
    0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc7, 0x3, 0x2,
    0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x44, 0x2,
    0x2, 0xc8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x5, 0x22, 0x12, 0x2,
    0xca, 0xcb, 0x7, 0x39, 0x2, 0x2, 0xcb, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xcc,
    0xcd, 0x5, 0x2c, 0x17, 0x2, 0xcd, 0xce, 0x7, 0x39, 0x2, 0x2, 0xce, 0xe0,
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xe0, 0x5, 0x36, 0x1c, 0x2, 0xd0, 0xe0, 0x5,
    0x3c, 0x1f, 0x2, 0xd1, 0xd2, 0x7, 0x15, 0x2, 0x2, 0xd2, 0xe0, 0x7, 0x39,
    0x2, 0x2, 0xd3, 0xd4, 0x7, 0x17, 0x2, 0x2, 0xd4, 0xe0, 0x7, 0x39, 0x2,
    0x2, 0xd5, 0xda, 0x7, 0x12, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x46, 0x2, 0x2,
    0xd7, 0xd9, 0x7, 0x45, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9,
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb,
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3,
    0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x4b, 0x2, 0x2, 0xde, 0xe0, 0x7, 0x39,
    0x2, 0x2, 0xdf, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xcc, 0x3, 0x2, 0x2,
    0x2, 0xdf, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xd0, 0x3, 0x2, 0x2, 0x2,
    0xdf, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xdf,
    0xd5, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x21, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xee,
    0x5, 0x24, 0x13, 0x2, 0xe2, 0xe3, 0x7, 0x41, 0x2, 0x2, 0xe3, 0xe8, 0x5,
    0x24, 0x13, 0x2, 0xe4, 0xe5, 0x7, 0x3b, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x24,
    0x13, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2,
    0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2,
    0xe9, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb,
    0xec, 0x7, 0x42, 0x2, 0x2, 0xec, 0xee, 0x3, 0x2, 0x2, 0x2, 0xed, 0xe1,
    0x3, 0x2, 0x2, 0x2, 0xed, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x3,
    0x2, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x3d, 0x2, 0x2, 0xf0, 0xf1, 0x5, 0x2a,
    0x16, 0x2, 0xf1, 0x23, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x9, 0x4, 0x2,
    0x2, 0xf3, 0xf5, 0x7, 0x47, 0x2, 0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2,
    0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6,
    0xfb, 0x5, 0x26, 0x14, 0x2, 0xf7, 0xf8, 0x7, 0x47, 0x2, 0x2, 0xf8, 0xfa,
    0x5, 0x26, 0x14, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfd, 0x3,
    0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2,
    0x2, 0x2, 0xfc, 0x25, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2,
    0x2, 0xfe, 0x105, 0x7, 0x4b, 0x2, 0x2, 0xff, 0x100, 0x7, 0x46, 0x2,
    0x2, 0x100, 0x101, 0x5, 0x2a, 0x16, 0x2, 0x101, 0x102, 0x7, 0x45, 0x2,
    0x2, 0x102, 0x104, 0x3, 0x2, 0x2, 0x2, 0x103, 0xff, 0x3, 0x2, 0x2, 0x2,
    0x104, 0x107, 0x3, 0x2, 0x2, 0x2, 0x105, 0x103, 0x3, 0x2, 0x2, 0x2,
    0x105, 0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x27, 0x3, 0x2, 0x2, 0x2, 0x107,
    0x105, 0x3, 0x2, 0x2, 0x2, 0x108, 0x10d, 0x5, 0x14, 0xb, 0x2, 0x109,
    0x10a, 0x7, 0x46, 0x2, 0x2, 0x10a, 0x10c, 0x7, 0x45, 0x2, 0x2, 0x10b,
    0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10d,
    0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e,
    0x29, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111,
    0x8, 0x16, 0x1, 0x2, 0x111, 0x112, 0x5, 0x4c, 0x27, 0x2, 0x112, 0x113,
    0x5, 0x2a, 0x16, 0x10, 0x113, 0x120, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115,
    0x7, 0x41, 0x2, 0x2, 0x115, 0x116, 0x5, 0x2a, 0x16, 0x2, 0x116, 0x117,
    0x7, 0x42, 0x2, 0x2, 0x117, 0x120, 0x3, 0x2, 0x2, 0x2, 0x118, 0x120,
    0x5, 0x3e, 0x20, 0x2, 0x119, 0x11a, 0x7, 0x11, 0x2, 0x2, 0x11a, 0x120,
    0x5, 0x30, 0x19, 0x2, 0x11b, 0x120, 0x5, 0x2c, 0x17, 0x2, 0x11c, 0x120,
    0x5, 0x24, 0x13, 0x2, 0x11d, 0x120, 0x5, 0x2e, 0x18, 0x2, 0x11e, 0x120,
    0x7, 0x1a, 0x2, 0x2, 0x11f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x114,
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x119,
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11c,
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11e,
    0x3, 0x2, 0x2, 0x2, 0x120, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122,
    0xc, 0xf, 0x2, 0x2, 0x122, 0x123, 0x5, 0x46, 0x24, 0x2, 0x123, 0x124,
    0x5, 0x2a, 0x16, 0x10, 0x124, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126,
    0xc, 0xe, 0x2, 0x2, 0x126, 0x127, 0x5, 0x48, 0x25, 0x2, 0x127, 0x128,
    0x5, 0x2a, 0x16, 0xf, 0x128, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12c,
    0xc, 0xd, 0x2, 0x2, 0x12a, 0x12d, 0x5, 0x40, 0x21, 0x2, 0x12b, 0x12d,
    0x5, 0x44, 0x23, 0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12b,
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f,
    0x5, 0x2a, 0x16, 0xe, 0x12f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131,
    0xc, 0xc, 0x2, 0x2, 0x131, 0x132, 0x5, 0x42, 0x22, 0x2, 0x132, 0x133,
    0x5, 0x2a, 0x16, 0xd, 0x133, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135,
    0xc, 0xb, 0x2, 0x2, 0x135, 0x136, 0x5, 0x4e, 0x28, 0x2, 0x136, 0x137,
    0x5, 0x2a, 0x16, 0xc, 0x137, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139,
    0xc, 0x9, 0x2, 0x2, 0x139, 0x13a, 0x5, 0x4a, 0x26, 0x2, 0x13a, 0x13b,
    0x5, 0x2a, 0x16, 0xa, 0x13b, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x121,
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x125, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x129,
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x130, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x134,
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x140,
    0x3, 0x2, 0x2, 0x2, 0x13e, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f,
    0x3, 0x2, 0x2, 0x2, 0x13f, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13e, 0x3,
    0x2, 0x2, 0x2, 0x141, 0x142, 0x5, 0x24, 0x13, 0x2, 0x142, 0x143, 0x7,
    0x47, 0x2, 0x2, 0x143, 0x145, 0x3, 0x2, 0x2, 0x2, 0x144, 0x141, 0x3,
    0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3,
    0x2, 0x2, 0x2, 0x146, 0x150, 0x5, 0x30, 0x19, 0x2, 0x147, 0x148, 0x7,
    0x21, 0x2, 0x2, 0x148, 0x149, 0x7, 0x41, 0x2, 0x2, 0x149, 0x150, 0x7,
    0x42, 0x2, 0x2, 0x14a, 0x14b, 0x7, 0x22, 0x2, 0x2, 0x14b, 0x14c, 0x7,
    0x41, 0x2, 0x2, 0x14c, 0x14d, 0x5, 0x2a, 0x16, 0x2, 0x14d, 0x14e, 0x7,
    0x42, 0x2, 0x2, 0x14e, 0x150, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x144, 0x3,
    0x2, 0x2, 0x2, 0x14f, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14a, 0x3,
    0x2, 0x2, 0x2, 0x150, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x151, 0x154, 0x7, 0x46,
    0x2, 0x2, 0x152, 0x155, 0x5, 0x2a, 0x16, 0x2, 0x153, 0x155, 0x5, 0x2e,
    0x18, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x153, 0x3, 0x2,
    0x2, 0x2, 0x155, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x156, 0x159, 0x7, 0x3b,
    0x2, 0x2, 0x157, 0x15a, 0x5, 0x2a, 0x16, 0x2, 0x158, 0x15a, 0x5, 0x2e,
    0x18, 0x2, 0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x158, 0x3, 0x2,
    0x2, 0x2, 0x15a, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x156, 0x3, 0x2,
    0x2, 0x2, 0x15c, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15b, 0x3, 0x2,
    0x2, 0x2, 0x15d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x160, 0x3, 0x2,
    0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x7, 0x45,
    0x2, 0x2, 0x161, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x7, 0x4b,
    0x2, 0x2, 0x163, 0x165, 0x7, 0x41, 0x2, 0x2, 0x164, 0x166, 0x5, 0x34,
    0x1b, 0x2, 0x165, 0x164, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2,
    0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x7, 0x42,
    0x2, 0x2, 0x168, 0x31, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x7, 0x16,
    0x2, 0x2, 0x16a, 0x16b, 0x7, 0xb, 0x2, 0x2, 0x16b, 0x16c, 0x7, 0x3a,
    0x2, 0x2, 0x16c, 0x16e, 0x5, 0x1e, 0x10, 0x2, 0x16d, 0x169, 0x3, 0x2,
    0x2, 0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2,
    0x2, 0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x174, 0x3, 0x2,
    0x2, 0x2, 0x171, 0x172, 0x7, 0x18, 0x2, 0x2, 0x172, 0x173, 0x7, 0x3a,
    0x2, 0x2, 0x173, 0x175, 0x5, 0x1e, 0x10, 0x2, 0x174, 0x171, 0x3, 0x2,
    0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x33, 0x3, 0x2, 0x2,
    0x2, 0x176, 0x17b, 0x5, 0x2a, 0x16, 0x2, 0x177, 0x178, 0x7, 0x3b, 0x2,
    0x2, 0x178, 0x17a, 0x5, 0x2a, 0x16, 0x2, 0x179, 0x177, 0x3, 0x2, 0x2,
    0x2, 0x17a, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x179, 0x3, 0x2, 0x2,
    0x2, 0x17b, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x35, 0x3, 0x2, 0x2, 0x2,
    0x17d, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x180, 0x5, 0x38, 0x1d, 0x2,
    0x17f, 0x181, 0x5, 0x3a, 0x1e, 0x2, 0x180, 0x17f, 0x3, 0x2, 0x2, 0x2,
    0x180, 0x181, 0x3, 0x2, 0x2, 0x2, 0x181, 0x189, 0x3, 0x2, 0x2, 0x2,
    0x182, 0x183, 0x7, 0x28, 0x2, 0x2, 0x183, 0x184, 0x5, 0x24, 0x13, 0x2,
    0x184, 0x185, 0x7, 0x43, 0x2, 0x2, 0x185, 0x186, 0x5, 0x32, 0x1a, 0x2,
    0x186, 0x187, 0x7, 0x44, 0x2, 0x2, 0x187, 0x189, 0x3, 0x2, 0x2, 0x2,
    0x188, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x188, 0x182, 0x3, 0x2, 0x2, 0x2,
    0x189, 0x37, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x13, 0x2, 0x2,
    0x18b, 0x18e, 0x5, 0x2a, 0x16, 0x2, 0x18c, 0x18f, 0x5, 0x1e, 0x10, 0x2,
    0x18d, 0x18f, 0x5, 0x20, 0x11, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2,
    0x18e, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x39, 0x3, 0x2, 0x2, 0x2, 0x190,
    0x193, 0x7, 0x14, 0x2, 0x2, 0x191, 0x194, 0x5, 0x1e, 0x10, 0x2, 0x192,
    0x194, 0x5, 0x20, 0x11, 0x2, 0x193, 0x191, 0x3, 0x2, 0x2, 0x2, 0x193,
    0x192, 0x3, 0x2, 0x2, 0x2, 0x194, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x195, 0x19a,
    0x7, 0xf, 0x2, 0x2, 0x196, 0x198, 0x5, 0x14, 0xb, 0x2, 0x197, 0x196,
    0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199,
    0x3, 0x2, 0x2, 0x2, 0x199, 0x19b, 0x5, 0x22, 0x12, 0x2, 0x19a, 0x197,
    0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c,
    0x3, 0x2, 0x2, 0x2, 0x19c, 0x19d, 0x7, 0x39, 0x2, 0x2, 0x19d, 0x19e,
    0x5, 0x2a, 0x16, 0x2, 0x19e, 0x1a0, 0x7, 0x39, 0x2, 0x2, 0x19f, 0x1a1,
    0x5, 0x22, 0x12, 0x2, 0x1a0, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1,
    0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3,
    0x5, 0x1e, 0x10, 0x2, 0x1a3, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5,
    0x7, 0x10, 0x2, 0x2, 0x1a5, 0x1a8, 0x5, 0x2a, 0x16, 0x2, 0x1a6, 0x1a9,
    0x5, 0x1e, 0x10, 0x2, 0x1a7, 0x1a9, 0x5, 0x20, 0x11, 0x2, 0x1a8, 0x1a6,
    0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1ab,
    0x3, 0x2, 0x2, 0x2, 0x1aa, 0x195, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a4,
    0x3, 0x2, 0x2, 0x2, 0x1ab, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x9,
    0x5, 0x2, 0x2, 0x1ad, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x7, 0x6,
    0x2, 0x2, 0x1af, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x7, 0x7, 0x2,
    0x2, 0x1b1, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0x8, 0x2, 0x2,
    0x1b3, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x7, 0x9, 0x2, 0x2, 0x1b5,
    0x47, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x7, 0xa, 0x2, 0x2, 0x1b7, 0x49,
    0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x5, 0x2, 0x2, 0x1b9, 0x4b, 0x3,
    0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x7, 0x3, 0x2, 0x2, 0x1bb, 0x4d, 0x3, 0x2,
    0x2, 0x2, 0x1bc, 0x1bd, 0x7, 0x4, 0x2, 0x2, 0x1bd, 0x4f, 0x3, 0x2, 0x2,
    0x2, 0x1be, 0x1bf, 0x7, 0x2b, 0x2, 0x2, 0x1bf, 0x51, 0x3, 0x2, 0x2,
    0x2, 0x30, 0x55, 0x5c, 0x6e, 0x74, 0x7a, 0x80, 0x83, 0x88, 0x8f, 0x97,
    0xa1, 0xa8, 0xb2, 0xbc, 0xc2, 0xc4, 0xda, 0xdf, 0xe8, 0xed, 0xf4, 0xfb,
    0x105, 0x10d, 0x11f, 0x12c, 0x13c, 0x13e, 0x144, 0x14f, 0x154, 0x159,
    0x15d, 0x165, 0x16f, 0x174, 0x17b, 0x180, 0x188, 0x18e, 0x193, 0x197,
    0x19a, 0x1a0, 0x1a8, 0x1aa,
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) {
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

Parse::Initializer Parse::_init;
