#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Expresie {
private:
	char* expresie=nullptr;
	double* rezultate = nullptr;
public:

	char* getExpresie() {
		char* copie = new char[strlen(expresie) + 1];
		strcpy_s(copie, strlen(expresie) + 1, expresie);
		return copie;
	}

	void setExpresie(const char* expr) {
		if (strlen(expr) < 3)
			throw exception("expresie vida");
		if (expresie != nullptr)
			delete[] expresie;
		expresie = new char[strlen(expr) + 1];
		strcpy_s(expresie, strlen(expr) + 1, expr);
	}

	Expresie() {
		this->setExpresie("0");
	}

	Expresie(char* expr) {
		this->setExpresie(expr);
	}

	Expresie(const Expresie& e) {
		this->setExpresie(e.expresie);
	}

	Expresie& operator=(const Expresie& e) {
		if (this == &e)
			return *this;
		this->setExpresie(e.expresie);
		return *this;
	}

	~Expresie() {
		if (expresie != nullptr)
		{
			delete[] expresie;
			expresie = nullptr;
		}

		if (rezultate != nullptr) 
		{
			delete[] rezultate;
			rezultate = nullptr;
		}
	}
};