/// CurTok/getNextToken - Provide a simple token buffer.  CurTok is the current
/// token the parser is looking at.  getNextToken reads another token from the
/// lexer and updates CurTok with its results.
#include "../header/parser.h"

int CurTok;

const int getNextToken() {
    return CurTok = gettok();
}

const int getCurTok() {
    return CurTok;
}

/// numberexpr ::= number
std::unique_ptr<NumberExprAST> ParseNumberExpr() {
    auto Result = std::make_unique<NumberExprAST>(getNumVal());
    //getNextToken(); // consume the number, usage kinda weird, do not foghetti zis part
    return std::move(Result);
}

/// identifier ::= identifier;
std::unique_ptr<PermanentExprAST> ParsePermanentExpr() {
    std::string idName = getIdentifierStr();
    getNextToken();
    return std::make_unique<PermanentExprAST>(idName);
}

//#include "../header/token.h"
/// actionexpr ::= action (number)identifier(;)
std::unique_ptr<ActionExprAST> ParseActionExpr() {
    std::string idName = getIdentifierStr();
    getNextToken();

    std::unique_ptr<NumberExprAST> num = std::move(ParseNumberExpr());
    getNextToken();

    std::unique_ptr<PermanentExprAST> ident = std::move(ParsePermanentExpr());

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
    
    auto Result = std::make_unique<TurnExprAST>(getNumVal());
    //getNextToken(); // consume the number
    return std::move(Result);
}

/// phaseexpr ::= phase : action
std::unique_ptr<PhaseExprAST> ParsePhaseExpr() {
    std::string idName = getIdentifierStr();

    getNextToken();
    fprintf(stdout, "%s\n", getIdentifierStr().c_str());
    /*
    if(CurTok!=':')
        return LogError("Expected ':' after a phase expression.");
    */
    
    getNextToken();
    fprintf(stdout, "%s\n", getIdentifierStr().c_str());

    std::unique_ptr<ActionExprAST> act = ParseActionExpr();

    return std::make_unique<PhaseExprAST>(idName, std::move(act));
}