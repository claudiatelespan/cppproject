#pragma once
#include <iostream>

class StackOperanzi {

private:
    int top;
    int capacity;
    double* stack;
    static const int DEFAULT_STACK_SIZE = 100;
    void resize(int newCapacity);

public:
    static const int STACK_SIZE = 100;

    StackOperanzi();
    StackOperanzi(int length);

    ~StackOperanzi();

    double getTop();
    bool isEmpty() const;
    int size();
    StackOperanzi& operator+(double number);  // Push an element
    StackOperanzi& operator--();  // Pop an element
    void printStack() const;

    friend std::ostream& operator<<(std::ostream& out, const StackOperanzi& stack);
    friend std::istream& operator>>(std::istream& in, StackOperanzi& stack);
};