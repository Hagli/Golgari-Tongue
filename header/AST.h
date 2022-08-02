#include <string>
#include <memory>
#include <vector>

class ExprAST {
    public:
        virtual ~ExprAST() {}
};

class NumberExprAST : public ExprAST {
    int num;

    public:
        NumberExprAST(int number) : num(number) {};
        int getNum() {return num;};
};

class TurnExprAST : public ExprAST {
    int num;

    public:
        TurnExprAST(int number) : num(number) {}
        int getTurn() {return num;};
};

class IdentifierExprAST : public ExprAST {
    std::string identifierName; 
    //for now it will just be a string later make every Identifier you can call
    //is an actual object in the 'library' of the language
    //reminder = Identifier/Object -> spells and lands

    public:
        IdentifierExprAST(std::string &name) : identifierName(name) {};
        std::string getIdent() {return identifierName;};
};

class ActionExprAST : public ExprAST {
    std::string actionName; 
    std::unique_ptr<NumberExprAST> num;
    std::unique_ptr<IdentifierExprAST> ident;

    public:
        ActionExprAST(std::string &name, std::unique_ptr<NumberExprAST> number, std::unique_ptr<IdentifierExprAST> identifier) : actionName(name), num(std::move(number)), ident(std::move(identifier))  {}
        std::string getActName() {return actionName;};
        std::unique_ptr<NumberExprAST> getNum() {return std::move(num);};
        std::unique_ptr<IdentifierExprAST> getIdent() {return std::move(ident);};
};

class PhaseExprAST : public ExprAST {
    std::string phaseName;
    std::unique_ptr<ActionExprAST> act;

    public:
        PhaseExprAST(std::string &name, std::unique_ptr<ActionExprAST> action) : phaseName(name), act(std::move(action)) {}
        std::unique_ptr<ActionExprAST> getAction() {return std::move(act);};
};

/////////////////////////////////
class BinaryExprAST : public ExprAST {
    char op;
    std::unique_ptr<ExprAST> lhs, rhs;

    public:
        BinaryExprAST(char operation, std::unique_ptr<ExprAST> left, std::unique_ptr<ExprAST> right) :
        op(operation), lhs(std::move(left)), rhs(std::move(right)) {}
};