#include <string>
#include <memory>

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

    public:
        PhaseExprAST(std::string name) : phaseName(name) {}
};

class ActionExprAST : public ExprAST {
    std::string actionName;

    public:
        ActionExprAST(std::string name) : actionName(name) {}
};

class ObjectExprAST : public ExprAST {
    std::string ObjectName; 
    //for now it will just be a string later make every object you can call
    //is an actual object in the 'library' of the language
    //reminder = object -> spells and lands

    public:
        ObjectExprAST(std::string name) : ObjectName(name) {}
};

class BinaryExprAST : public ExprAST {
    char op;
    std::unique_ptr<ExprAST> lhs, rhs;

    public:
        BinaryExprAST(char operation, std::unique_ptr<ExprAST> left, std::unique_ptr<ExprAST> right) :
        op(operation), lhs(std::move(left)), rhs(std::move(right)) {}
};

