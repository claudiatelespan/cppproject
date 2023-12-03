#include "StackOperanzi.h"

using namespace std;

StackOperanzi::StackOperanzi() : top(-1), stack(nullptr), capacity(DEFAULT_STACK_SIZE) {
    stack = new double[DEFAULT_STACK_SIZE];
}

StackOperanzi::StackOperanzi(int capacity) : top(-1) {
    stack = new double[capacity];
    this->capacity = capacity;
}

StackOperanzi::~StackOperanzi() {
    if (stack != nullptr)
        delete[] stack;
}

StackOperanzi& StackOperanzi::operator+(double value) {
    if (top < capacity - 1)
        stack[++top] = value;
    else {
        resize(capacity * 2);
        stack[++top] = value;
    }

    return *this;
}

StackOperanzi& StackOperanzi::operator--() {
    if (top >= 0)
        --top;
    else {
        throw std::exception("Stackul este gol");
    }

    return *this;
}

void StackOperanzi::resize(int newCapacity) {
    double* newStack = new double[newCapacity];

    for (int i = 0; i <= top; ++i)
        newStack[i] = stack[i];

    delete[] stack;
    stack = newStack;
    capacity = newCapacity;
}

double StackOperanzi::getTop() {
    return stack[top];
}

bool StackOperanzi::isEmpty() {
    return top < 0;
}

int StackOperanzi::size() {
    return top + 1;
}

void StackOperanzi::printStack() const {
    cout << "Stackul contine: ";
    for (int i = 0; i <= top; ++i) {
        cout << stack[i] << " ";
    }
    cout << endl;
}