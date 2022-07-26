#include <cstdio>
#include <memory>
#include <vector>

/// CurTok/getNextToken - Provide a simple token buffer.  CurTok is the current
/// token the parser is looking at.  getNextToken reads another token from the
/// lexer and updates CurTok with its results.

#include "../header/lexer.h"
static int getNextToken() {
    return CurTok = gettok();
}

#include "../header/parser.h"
/// LogError* - These are little helper functions for error handling.
std::unique_ptr<ExprAST> LogError(const char *Str) {
    fprintf(stderr, "LogError: %s\n", Str);
    return nullptr;
}

/// numberexpr ::= number
static std::unique_ptr<ExprAST> ParseNumberExpr() {
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    getNextToken(); // consume the number
    return std::move(Result);
}

/// identifier ::= identifier;
static std::unique_ptr<ExprAST> ParseIdentifierExpr() {
    std::string idName = IdentifierStr;

    getNextToken();

    return std::make_unique<IdentifierExprAST>(idName);
}

/// actionexpr ::= action
/// actionexpr ::= action ((number)(identifier,))*(number)identifier(;)
static std::unique_ptr<ExprAST> ParseActionExpr() {
    std::string idName = IdentifierStr;

    getNextToken();
    
    std::vector<std::unique_ptr<ExprAST>> args;
    while(1) {
        if(CurTok==tok_number){
            auto arg = ParseNumberExpr();
            args.push_back(std::move(arg));
        }
        else if(auto arg = ParseIdentifierExpr()){
            args.push_back(std::move(arg));
        }
        else
            return nullptr;
        
        if((CurTok==tok_phase) || (CurTok==';'))
            break;
        
        if(CurTok!=',')
            return LogError("Expected a newline, ';', or ',' instead.");
        
        getNextToken();
    }

    return std::make_unique<ActionExprAST>(idName, std::move(args));
}

/// turnexpr ::= turn number
static std::unique_ptr<ExprAST> ParseTurnExpr() {
    getNextToken();
    if(CurTok!=':')
        return LogError("Exprected a ':' after a turn declaration.");
    
    getNextToken();
    if(CurTok!=tok_number)
        return LogError("Expected turn number.");
    
    auto Result = std::make_unique<TurnExprAST>(NumVal);
    getNextToken(); // consume the number
    return std::move(Result);
}

/// phaseexpr ::= phase (action;)*action
static std::unique_ptr<ExprAST> ParsePhaseExpr() {
    std::string idName = IdentifierStr;

    getNextToken();

    if (CurTok!=':')
        return LogError("Expected ':' after a phase expression.");
    
    getNextToken();

    std::vector<std::unique_ptr<ExprAST>> args;
    while(1) {
        if(auto arg = ParseActionExpr()){
            args.push_back(std::move(arg));
        }
        else
            return nullptr;
        
        if(CurTok==tok_phase) //newline
            break;
        
        if(CurTok!=';')
            return LogError("Expected a newline or ';' instead.");
        
        getNextToken();
    }

    return std::make_unique<PhaseExprAST>(idName, std::move(args));
}