#include "Operand.h"
#include <stdexcept>

using namespace std;

Operand::Operand() :values(nullptr), count(0) {

}

Operand::Operand(double val) : count(1) {
	values = new double[count];
	values[0] = val;
}

Operand::Operand(const Operand& other) : count(other.count) {
	values = new double[count];
	for (int i = 0; i < count; ++i) {
		values[i] = other.values[i];
	}
}

Operand& Operand::operator=(const Operand& other) {
	if (this != &other) {
		if (values != nullptr)
			delete[] values;
		count = other.count;
		values = new double[count];
		for (int i = 0; i < count; ++i) {
			values[i] = other.values[i];
		}
	}
	return *this;
}

Operand::~Operand() {
	if (values != nullptr)
	{
		delete[] values;
		values = nullptr;
	}
}

void Operand::addValue(double val) {
	double* newValues = new double[count + 1];
	for (int i = 0; i < count; ++i) {
		newValues[i] = values[i];
	}
	newValues[count++] = val;
	if (values != nullptr)
		delete[] values;
	values = newValues;
}

double Operand::getValue(int index) const {
	if (index >= 0 && index < count) {
		return values[index];
	}
	throw std::out_of_range("Index invalid");
}

int Operand::getCount() const {
	return count;
}

bool Operand::isSingleValue() const {
	return (count == 1);
}

double Operand::getSingleValue() const {
	if (count == 1) {
		return values[0];
	}
	else {
		throw std::invalid_argument("Operand invalid");
	}
}
	
void setOperands(double* op, int nr) {

}


	

	