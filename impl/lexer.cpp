//Taken from the tutorial at
//https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html
#include "../header/lexer.h"
#include "../header/token.h"

//reminder to change this from global variable
//static std::string IdentifierStr; Filled in if tok_identifier
//static int NumVal;              Filled in if tok_number

const int gettok() {
    static int LastChar = ' ';

    while (isspace(LastChar)){
        LastChar = getchar();
    }

    if(isalpha(LastChar)){ //identifier: [a-zA-Z][a-zA-Z0-9]*
        IdentifierStr = LastChar;
        while (isalnum((LastChar = getchar()))){
            IdentifierStr += LastChar;
        }
        if (IdentifierStr == "turn")
            return tok_turn;
        else if ((IdentifierStr == "u") || (IdentifierStr == "m1") || (IdentifierStr == "b") || (IdentifierStr == "m2") || (IdentifierStr == "e")){
            return tok_phase;
        }
        else if ((IdentifierStr == "play") || (IdentifierStr == "attack") || (IdentifierStr == "pass")){
            return tok_action;
        }
        else if (IdentifierStr == "end"){
           return tok_eof; //basically end of file that needs to be read heheh
        }
        else {
            return tok_identifier;
        }
    }

    //for now, there should be only integers in the program text code
    if (isdigit(LastChar)){
        std::string NumStr;
        do {
            NumStr += LastChar;
            LastChar = getchar();
        } while (isdigit(LastChar));

        NumVal = std::stoi(NumStr.c_str(), 0);
        return tok_number;
    }

    if (LastChar == '"'){
        //comment for 1 line
        //for now
        do {
            LastChar = getchar();
        } while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if (LastChar != EOF){
            return gettok();
        }
    }

    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}