#include <iostream>
#include <string>
#include <cmath>
#include "Operator.cpp"
#include "Operand.cpp"
using namespace std;



class Expression {
private:
	char* expression = nullptr;
	Operator* operatori=nullptr;
	Operand* operanzi=nullptr;
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
		if (strlen(expr) < 3 || expr==nullptr)
			throw exception("expression vida");
		if (operatori != nullptr)
		{
			delete[] operatori;
			operatori = nullptr;
		}
		if (operanzi != nullptr)
		{
			delete[] operanzi;
			operanzi = nullptr;
		}
		if (expression != nullptr)
			delete[] expression;
		expression = new char[strlen(expr) + 1];
		strcpy_s(expression, strlen(expr) + 1, expr);

		/*parseExpression();
		evaluateExpression();*/
	}
	
	//constructori
	Expression() :expression(nullptr), solution(0), operatori(nullptr), operanzi(nullptr) {

	}

	Expression(const char* expr):operatori(nullptr), operanzi(nullptr) {
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

	void parseExpression() {
		int length = strlen(expression);
		operanzi = new Operand[length];
		operatori = new Operator[length];
		int operandIndex = 0;
		int operatorIndex = 0;
		for (int i = 0; i < length; i++) {
			if (isdigit(expression[i]) || (expression[i] == '-' && i + 1 < length && isdigit(expression[i + 1]))) {
				double val = stod(&expression[i]);
				operanzi[operandIndex++].addValue(val);
				while (i + 1 < length && (isdigit(expression[i + 1]) || expression[i + 1] == '.')) {
					++i;
				}
			}
			else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^' || expression[i] == '#') {
				operatori[operatorIndex++] = Operator(expression[i]);
			}
		}
	}


	friend ostream& operator<<(ostream&, const Expression&);
	friend istream& operator>>(istream&, Expression&);
		//destructor
	~Expression() {
		if (expression != nullptr)
		{
			delete[] expression;
			expression = nullptr;
		}

		if (operatori != nullptr)
		{
			delete[] operatori;
			operatori = nullptr;
		}

		if (operanzi != nullptr)
		{
			delete[] operanzi;
			operanzi = nullptr;
		}
	}
	
};

