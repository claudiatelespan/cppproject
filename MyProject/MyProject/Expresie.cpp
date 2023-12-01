#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Stack {
	double* elements;
	int size;
	int capacity;

	Stack(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->elements = new double[capacity];
	}

	~Stack() {
		delete[] elements;
	}

	void push(double value) {
		if (size < capacity) {
			elements[size++] = value;
		}
	}

	double pop() {
		if (size > 0) {
			return elements[--size];
		}
		throw exception("stiva este goala");
	}

	double top() const {
		if (size > 0) {
			return elements[size - 1];
		}
		throw exception("stiva este goala");
	}

	bool isEmpty() const {
		return size == 0;
	}

};

class Expresie {

private:

	char* expression=nullptr;
	double* solution = nullptr;

public:

	char* getExpresie() {
		char* copie = new char[strlen(expression) + 1];
		strcpy_s(copie, strlen(expression) + 1, expression);
		return copie;
	}

	void setExpresie(const char* expr) {
		if (strlen(expr) < 3)
			throw exception("expresie vida");
		if (expression != nullptr)
			delete[] expression;
		expression = new char[strlen(expr) + 1];
		strcpy_s(expression, strlen(expr) + 1, expr);
	}

	Expresie():expression(nullptr), solution(nullptr){
		
	}

	Expresie(const char* expr) {
		this->setExpresie(expr);
	}

	Expresie(const Expresie& e) {
		this->setExpresie(e.expression);
	}

	Expresie& operator=(const Expresie& e) {
		if (this == &e)
			return *this;
		this->setExpresie(e.expression);
		return *this;
	}

	char& operator[](int index){
		if (index < 0 || index >= strlen(expression))
			throw exception("index invalid");
		return expression[index];
	}

	~Expresie() {
		if (expression != nullptr)
		{
			delete[] expression;
			expression = nullptr;
		}

		if (solution != nullptr) 
		{
			delete[] solution;
			solution = nullptr;
		}
	}

	friend ostream& operator<<(ostream&, const Expresie&);
	friend istream& operator>>(istream&, Expresie&);
};

