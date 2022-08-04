#include <cstdio>
#include "AST.h"
#include "lexer.h"

const int getNextToken();
const int getCurTok();
std::unique_ptr<NumberExprAST> ParseNumberExpr();
std::unique_ptr<IdentifierExprAST> ParseIdentifierExpr();
std::unique_ptr<ActionExprAST> ParseActionExpr();
std::unique_ptr<TurnExprAST> ParseTurnExpr();
std::unique_ptr<PhaseExprAST> ParsePhaseExpr();