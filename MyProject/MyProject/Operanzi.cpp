#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Operand {

private:
	double* operands = nullptr;
	int noOperands = 0;

public:
	double* getOperands() {
		double* copie = new double[noOperands];
		for (int i = 0; i < noOperands; i++)
			copie[i] = operands[i];
		return copie;
	}
	int getNoOperands() {
		return noOperands;
	}

	void setOperands(double* op, int nr) {

	}

	Operand() :operands(nullptr), noOperands(0) {

	}

	Operand(double* val, int nr) : noOperands(nr) {
		operands = new double[nr];
		for(int i=0;i<noOperands;i++)
			operands[i] = val[i];
	}

	Operand(const Operand& other) : noOperands(other.noOperands) {
		operands = new double[noOperands];
		for (int i = 0; i < noOperands; ++i) {
			operands[i] = other.operands[i];
		}
	}

	Operand& operator=(const Operand& other) {
		if (this == &other)
			return *this;
		if(operands!=nullptr)
			delete[] operands;
		noOperands = other.noOperands;
		operands = new double[noOperands];
		for (int i = 0; i < noOperands; ++i) {
			operands[i] = other.operands[i];
			}
		
		return *this;
	}

	void addValue(double val) {
		double* newValues = new double[noOperands + 1];
		for (int i = 0; i < noOperands; ++i) {
			newValues[i] = operands[i];
		}
		newValues[noOperands++] = val;
		if (operands != nullptr)
			delete[] operands;
		operands = newValues;
	}

	~Operand() {
		if (operands != nullptr)
		{
			delete[] operands;
			operands = nullptr;
		}
	}
};