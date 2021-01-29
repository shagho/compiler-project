#include <actions.hpp>
#include <iostream>
#include <antlr4-runtime.h>
#include "ExprLexer.h"

int main(int argc, char *argv[])
{
    std::ifstream stream;
    stream.open("input.txt");
    antlr4::ANTLRInputStream input(stream);
    ExprLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    ExprParser parser(&tokens);
    antlr4::tree::ParseTree *tree = parser.program();
    actions code;
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&code, tree);
}
