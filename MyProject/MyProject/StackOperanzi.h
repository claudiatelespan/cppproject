#pragma once
#include <iostream>

class StackOperanzi {
public:
    static const int STACK_SIZE = 100;

    StackOperanzi();
    StackOperanzi(int length);
    StackOperanzi(double* array, int length);

    ~StackOperanzi();

    double getTop();
    bool isEmpty();
    int size();
    StackOperanzi& operator+(double number);  // Push an element
    StackOperanzi& operator--();  // Pop an element
    void printStack() const;

private:
    int top;
    int capacity;
    double* stack;
    static const int DEFAULT_STACK_SIZE = 100;
    void resize(int newCapacity);
};