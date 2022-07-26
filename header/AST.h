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
        NumberExprAST(int number) : num(number) {}
};

class PhaseExprAST : public ExprAST {
    std::string phaseName;
    std::vector<std::unique_ptr<ExprAST>> args;

    public:
        PhaseExprAST(std::string &name, std::vector<std::unique_ptr<ExprAST>> arguments) : phaseName(name), args(std::move(arguments)) {}
};

class TurnExprAST : public ExprAST {
    int num;

    public:
        TurnExprAST(int number) : num(number) {}
};

class ActionExprAST : public ExprAST {
    std::string actionName;
    std::vector<std::unique_ptr<ExprAST>> args;

    public:
        ActionExprAST(std::string &name, std::vector<std::unique_ptr<ExprAST>> arguments) : actionName(name), args(std::move(arguments)) {}
};

class IdentifierExprAST : public ExprAST {
    std::string identifierName; 
    //for now it will just be a string later make every Identifier you can call
    //is an actual object in the 'library' of the language
    //reminder = Identifier/Object -> spells and lands

    public:
        IdentifierExprAST(std::string &name) : identifierName(name) {}
};

class BinaryExprAST : public ExprAST {
    char op;
    std::unique_ptr<ExprAST> lhs, rhs;

    public:
        BinaryExprAST(char operation, std::unique_ptr<ExprAST> left, std::unique_ptr<ExprAST> right) :
        op(operation), lhs(std::move(left)), rhs(std::move(right)) {}
};

