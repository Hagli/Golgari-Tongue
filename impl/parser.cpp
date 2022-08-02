/// CurTok/getNextToken - Provide a simple token buffer.  CurTok is the current
/// token the parser is looking at.  getNextToken reads another token from the
/// lexer and updates CurTok with its results.

#include "../header/parser.h"
const int getNextToken() {
    return CurTok = gettok();
}

/// numberexpr ::= number
std::unique_ptr<NumberExprAST> ParseNumberExpr() {
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    getNextToken(); // consume the number, usage kinda weird, do not foghetti zis part
    return std::move(Result);
}

/// identifier ::= identifier;
std::unique_ptr<IdentifierExprAST> ParseIdentifierExpr() {
    std::string idName = IdentifierStr;
    getNextToken();
    return std::make_unique<IdentifierExprAST>(idName);
}

//#include "../header/token.h"
/// actionexpr ::= action (number)identifier(;)
std::unique_ptr<ActionExprAST> ParseActionExpr() {
    std::string idName = IdentifierStr;
    getNextToken();

    std::unique_ptr<NumberExprAST> num = std::move(ParseNumberExpr());
    std::unique_ptr<IdentifierExprAST> ident = std::move(ParseIdentifierExpr());

    return std::make_unique<ActionExprAST>(idName, std::move(num), std::move(ident));
}

/// turnexpr ::= turn : number
std::unique_ptr<TurnExprAST> ParseTurnExpr() {
    getNextToken();
    /*if(CurTok!=':')
        return LogError("Exprected a ':' after a turn declaration.");
    */
    
    getNextToken();
    /*if(CurTok!=tok_number)
        return LogError("Expected turn number.");
    */
    
    auto Result = std::make_unique<TurnExprAST>(NumVal);
    //getNextToken(); // consume the number
    return std::move(Result);
}

/// phaseexpr ::= phase : action
std::unique_ptr<PhaseExprAST> ParsePhaseExpr() {
    std::string idName = IdentifierStr;

    getNextToken();
    /*
    if(CurTok!=':')
        return LogError("Expected ':' after a phase expression.");
    */
    
    getNextToken();

    std::unique_ptr<ActionExprAST> act = ParseActionExpr();

    return std::make_unique<PhaseExprAST>(idName, std::move(act));
}