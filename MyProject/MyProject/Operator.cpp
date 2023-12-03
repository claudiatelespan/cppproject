#include "Operator.h"

Operator::Operator() : op('\0') {
}

Operator::Operator(char operation) : op(operation) {
}

char Operator::getOperator() const {
        return op;
}

int Operator::getPrecedenta() const {
    if (op == '+' || op == '-') 
        return 1;
    if (op == '*' || op == '/') 
        return 2;
    if (op == '^' || op == '#') 
        return 3;
    return 0;
}

bool Operator::isLeftAssociative() const {
        return(op == '+' || op == '-' || op == '*' || op == '/');
}

bool Operator::isOpenParenthesis() const {
        return (op == '(');
}

bool Operator::isCloseParenthesis() const {
        return (op == ')');
}

bool Operator::isParenthesis() const {
        return(isOpenParenthesis() || isCloseParenthesis());
}

bool Operator::operator==(const Operator& other) const {
        return this->getPrecedenta() == other.getPrecedenta();
}

bool Operator::operator!=(const Operator& other) const {
        return this->getPrecedenta() != other.getPrecedenta();
}

bool Operator::operator<(const Operator& other) const {
        return this->getPrecedenta() < other.getPrecedenta();
}

bool Operator::operator>(const Operator& other) const {
        return this->getPrecedenta() > other.getPrecedenta();
}

bool Operator::operator<=(const Operator& other) const {
        return this->getPrecedenta() <= other.getPrecedenta();
}

bool Operator::operator>=(const Operator& other) const {
        return this->getPrecedenta() >= other.getPrecedenta();
}



