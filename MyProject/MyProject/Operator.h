#pragma once

class Operator {
private:
    char op;

public:
    Operator();
    Operator(char operation);

    char getOperator() const;
    int getPrecedenta() const;
    bool isLeftAssociative() const;
    bool isOpenParenthesis() const;
    bool isCloseParenthesis() const;
    bool isParenthesis() const;

    bool operator==(const Operator& other) const;
    bool operator!=(const Operator& other) const;
    bool operator<(const Operator& other) const;
    bool operator>(const Operator& other) const;
    bool operator<=(const Operator& other) const;
    bool operator>=(const Operator& other) const;
};