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

bool StackOperanzi::isEmpty() const{
    return top < 0;
}

int StackOperanzi::size() {
    return top + 1;
}

ostream& operator<<(ostream& out, const StackOperanzi& stack) {
    if (stack.isEmpty()) {
        out << "Stack-ul este gol.";
    }
    else {
        out << "Stack-ul contine elementele:";
        for (int i = 0; i <= stack.top; ++i) {
            out << stack.stack[stack.top-i] << " ";
        }
    }
    return out;
}

istream& operator>>(istream& in, StackOperanzi& stack) {
    int size;
    std::cout << "Introduceti dimensiunea stack-ului:";
    in >> size;

    double value;
    for (int i = 0; i < size; ++i) {
        std::cout << "Introduceti elementul" << i + 1 << ": ";
        in >> value;
        stack = stack + value;
    }

    return in;
}