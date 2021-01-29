
// Generated from /home/navid/Compiler_project/Lexe.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  Lexe : public antlr4::Lexer {
public:
  enum {
    UNARY_OP = 1, BITWISE = 2, LOGICAL = 3, RELATIONAL1 = 4, RELATIONAL2 = 5, 
    RELATIONAL3 = 6, ARITHMETIC1 = 7, ARITHMETIC2 = 8, INT_CONST = 9, BOOL_CONST = 10, 
    REAL_CONST = 11, STRING_CONST = 12, FOR = 13, WHILE = 14, ALLOCATE = 15, 
    DESTRUCT = 16, IF = 17, ELSE = 18, BREAK = 19, CASEOF = 20, CONTINUE = 21, 
    DEFAULT = 22, FUNCTION = 23, NIL = 24, BOOL = 25, TYPE = 26, INT = 27, 
    FLOAT = 28, STRING = 29, CONST = 30, READ = 31, WRITE = 32, PUBLIC = 33, 
    PRIVATE = 34, PROTECTED = 35, SUPER = 36, THIS = 37, SWITCH = 38, TRUE = 39, 
    FALSE = 40, START = 41, STAR = 42, OP_NE = 43, OP_LE = 44, OP_GE = 45, 
    OP_AND = 46, OP_OR = 47, LT = 48, GT = 49, BANG = 50, TILDE = 51, AMP = 52, 
    BITWISE_OR = 53, PERCENT = 54, SEMIC = 55, COLON = 56, COMMA = 57, EQ = 58, 
    ASM = 59, PLUS = 60, MINUS = 61, DIV = 62, LPAR = 63, RPAR = 64, CLPAR = 65, 
    CRPAR = 66, BR = 67, BL = 68, DOT = 69, WhiteSpace = 70, Comment = 71, 
    INTEGER = 72, ID = 73
  };

  Lexe(antlr4::CharStream *input);
  ~Lexe();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

