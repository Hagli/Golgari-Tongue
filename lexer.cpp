//Taken from the tutorial at
//https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html
#include <string>

enum Token {
    tok_eof = -1,

    //control point or phase
    tok_turn = -2,
    tok_upkeep_p = -3,
    tok_main1_p = -4,
    tok_battle_p = -5,
    tok_main2_p= -6,
    tok_end_p = -7,

    //command
    tok_play = -8,
    tok_attack = -9,
    tok_pass = -10,
    tok_end = -11,

    //primary
    tok_object = -12, //objects ("spells/lands")
    tok_number = -13,
};

//reminder to change this from global variable
static std::string IdentifierStr; // Filled in if tok_identifier
static double NumVal;             // Filled in if tok_number

static int gettok() {
    static int LastChar = ' ';

    while (isspace(LastChar)){
        LastChar = getchar();
    }

    if(isalpha(LastChar)){ //identifier: [a-zA-Z][a-zA-Z0-9]*
        IdentifierStr = LastChar;
        while (isalnum((LastChar = getchar()))){
            IdentifierStr += LastChar;
        }
    }

    if (IdentifierStr == "turn"){
        return tok_turn;
    }
    else if (IdentifierStr == "u"){
        return tok_upkeep_p;
    }
    else if (IdentifierStr == "m1"){
        return tok_main1_p;
    }
    else if (IdentifierStr == "b"){
        return tok_battle_p;
    }
    else if (IdentifierStr == "m2"){
        return tok_main2_p;
    }
    else if (IdentifierStr == "e"){
        return tok_end_p;
    }
    else if (IdentifierStr == "play"){
        return tok_play;
    }
    else if (IdentifierStr == "attack"){
        return tok_attack;
    }
    else if (IdentifierStr == "pass"){
        return tok_pass;
    }
    else if (IdentifierStr == "end"){
        return tok_end;
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

    if (LastChar == EOF){
        return tok_eof;
    }

    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}