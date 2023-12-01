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

class Expression {

private:

	char* expression = nullptr;
	char* operators = nullptr;
	double solution = 0;


public:

	//metode de acces
	char* getExpression() {
		char* copie = new char[strlen(expression) + 1];
		strcpy_s(copie, strlen(expression) + 1, expression);
		return copie;
	}
	double getSolution() {
		return solution;
	}
	

	void setExpression(const char* expr) {
		if (strlen(expr) < 3)
			throw exception("expresie vida");
		if (expression != nullptr)
			delete[] expression;
		expression = new char[strlen(expr) + 1];
		strcpy_s(expression, strlen(expr) + 1, expr);
	}
	
	void setOperands(double* op, int nr) {

	}

	//constructori
	Expression() :expression(nullptr), solution(0) {

	}

	Expression(const char* expr) {
		this->setExpression(expr);
	}

	Expression(const Expression& e) {
		this->setExpression(e.expression);
	}

	//supraincarcari si metode
	Expression& operator=(const Expression& e) {
		if (this == &e)
			return *this;
		this->setExpression(e.expression);
		return *this;
	}

	char& operator[](int index) {
		if (index < 0 || index >= strlen(expression))
			throw exception("index invalid");
		return expression[index];
	}

	
	/*void descompunere() {
		for (int i = 0; i < strlen(expression); i++)
		{

		}
	}*/

	friend ostream& operator<<(ostream&, const Expression&);
	friend istream& operator>>(istream&, Expression&);
		//destructor
	~Expression() {
		if (expression != nullptr)
		{
			delete[] expression;
			expression = nullptr;
		}
	}
	
};

