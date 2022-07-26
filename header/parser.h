#include <memory>
#include "AST.h"

static int CurTok;
static int getNextToken();
static std::unique_ptr<ExprAST> ParseNumberExpr();
static std::unique_ptr<ExprAST> ParseIdentifierExpr();
static std::unique_ptr<ExprAST> ParseActionExpr();
static std::unique_ptr<ExprAST> ParseTurnExpr();
static std::unique_ptr<ExprAST> ParsePhaseExpr();
