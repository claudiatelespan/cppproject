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

	}
	int getNoOperands() {
		return noOperands;
	}

	void addValue(double val) {
		double* newValues = new double[noOperands + 1];
		for (int i = 0; i < noOperands; ++i) {
			newValues[i] = operands[i];
		}
		newValues[noOperands++] = val;
		delete[] operands;
		operands = newValues;
	}
};