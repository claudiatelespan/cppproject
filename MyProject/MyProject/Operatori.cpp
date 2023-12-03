#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//struct Stack {
//    double* elements;
//    int size;
//    int capacity;
//
//    Stack(int capacity) {
//        this->capacity = capacity;
//        this->size = 0;
//        this->elements = new double[capacity];
//    }
//
//    ~Stack() {
//        delete[] elements;
//    }
//
//    void push(double value) {
//        if (size < capacity) {
//            elements[size++] = value;
//        }
//    }
//
//    double pop() {
//        if (size > 0) {
//            return elements[--size];
//        }
//        throw exception("stiva este goala");
//    }
//
//    double top() const {
//        if (size > 0) {
//            return elements[size - 1];
//        }
//        throw exception("stiva este goala");
//    }
//
//    bool isEmpty() const {
//        return size == 0;
//    }
//
//};

class Operator {

private:
    char op=0;

public:
    char getOperator() {
        return op;
    }
    void setOperator(const char* op) {

    }

    Operator() : op('\0') {
    }

    Operator(char operation) : op(operation) {
    }

    bool esteOperator(char token) const {
        return (token == '+' || token == '-' || token == '*' || token == '/' || token == '^' || token == '#');
    }

    int getPrecedenta() const {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^' || op == '#') return 3;
        return 0;
    }

    bool isLeftAssociative() const {
        return(op == '+' || op == '-' || op == '*' || op == '/');
    }

    bool isOpenParenthesis() const {
        return (op == '(');
    }

    bool isCloseParenthesis() const {
        return (op == ')');
    }

    bool isParenthesis() const {
        return(isOpenParenthesis() || isCloseParenthesis());
    }

    bool operator==(const Operator& other) const {
        return this->getPrecedenta() == other.getPrecedenta();
    }

    bool operator!=(const Operator& other) const {
        return this->getPrecedenta() != other.getPrecedenta();
    }

    bool operator<(const Operator& other) const {
        return this->getPrecedenta() < other.getPrecedenta();
    }

    bool operator>(const Operator& other) const {
        return this->getPrecedenta() > other.getPrecedenta();
    }

    bool operator<=(const Operator& other) const {
        return this->getPrecedenta() <= other.getPrecedenta();
    }

    bool operator>=(const Operator& other) const {
        return this->getPrecedenta() >= other.getPrecedenta();
    }

    /*void aplicareOperator(Stack values, char op) {
        double operand2 = values.top(); values.pop();
        double operand1 = values.top(); values.pop();

        switch (op) {
        case '+':
            values.push(operand1 + operand2);
            break;
        case '-':
            values.push(operand1 - operand2);
            break;
        case '*':
            values.push(operand1 * operand2);
            break;
        case '/':
            values.push(operand1 / operand2);
            break;
        }
    }*/
};

