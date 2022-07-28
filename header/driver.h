#include "AST.h"

//extern int NumVal;
//extern std::string IdentifierStr;

extern int getNextToken();
extern std::unique_ptr<ExprAST> ParseTurnExpr();
extern std::unique_ptr<ExprAST> ParsePhaseExpr();
extern std::unique_ptr<ExprAST> ParseActionExpr();
extern std::unique_ptr<ExprAST> ParseIdentifierExpr();
extern std::unique_ptr<ExprAST> ParseNumberExpr();

extern int CurTok;