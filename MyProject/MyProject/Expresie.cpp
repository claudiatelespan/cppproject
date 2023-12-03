#include "Expresie.h"
#include <iomanip>

using namespace std;

const double Expresie::REZULTAT_DEFAULT = -1.0;

Expresie::Expresie() :expresie(nullptr), rezultat(REZULTAT_DEFAULT), operatori(nullptr), operanzi(nullptr) {

}

Expresie::Expresie(const char* expr) :operatori(nullptr), operanzi(nullptr) {
	this->setExpresie(expr);
}

Expresie::Expresie(const Expresie& e) {
	this->setExpresie(e.expresie);
	operanzi = e.operanzi;
	operatori = e.operatori;
}
	
Expresie& Expresie::operator=(const Expresie& e) {
	if (this != &e) {
		this->setExpresie(e.expresie);
		operatori = e.operatori;
		operanzi = e.operanzi;
	}
	return *this;
}

char* Expresie::getExpresie() const {
	return expresie;
}

void Expresie::setExpresie(const char* expr) {
	if (strlen(expr) < 3 || expr == nullptr)
		throw exception("Expresie invalida");
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
	if (expresie != nullptr)
		delete[] expresie;
	expresie = new char[strlen(expr) + 1];
	strcpy_s(expresie, strlen(expr) + 1, expr);

	/*parseExpression();
	evaluateExpresie();*/
}

double Expresie::getRezultat() const {
	return rezultat;
}

Expresie::operator float() {
	if (rezultat == REZULTAT_DEFAULT) {
		evaluateExpresie();
	}

	return static_cast<float>(rezultat);
}


char& Expresie::operator[](int index) const {
	if (index < 0 || index >= strlen(expresie))
		throw std::invalid_argument("Index invalid!");
	return expresie[index];
}

ostream& operator<<(ostream& out, const Expresie& e) {
	out << "Rezultatul expresiei:" << to_string(e.getRezultat());
	return out;
}

istream& operator>>(istream& in, Expresie& e) {
	cout << endl << "Introduceti expresie: ";
	string copie;
	in >> copie;
	e.setExpresie(copie.c_str());
	return in;
}

Expresie::~Expresie() {
	if (expresie != nullptr)
	{
		delete[] expresie;
		expresie = nullptr;
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
	


