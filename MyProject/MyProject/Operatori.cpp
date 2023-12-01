#include <iostream>
#include <string>
#include <cmath>
#include "Expresie.cpp"
using namespace std;

class Operator {
    char op;
public:
    char* getOperator() {

    }
    void setOperator(const char* op) {

    }
    bool esteOperator(char token) const {
        return (token == '+' || token == '-' || token == '*' || token == '/');
    }

    int precedentaOperator(char op) const {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^' || op == '#') return 3;
        return 0;
    }

    void aplicareOperator(Stack values, char op) {
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
    }
};

