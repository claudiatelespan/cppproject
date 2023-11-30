#include <iostream>
#include <string>
#include <cmath>
#include "Expresie.cpp"
using namespace std;

ostream& operator<<(ostream& out, const Expresie& e) {
	out << "Rezultatul expresiei:" << e.rezultate;
	return out;
}

istream& operator>>(istream& in, Expresie& e) {
	cout << "Introduceti expresie: ";
	string copie;
	in >> copie;
	if (copie.size() < 3) throw exception("expresie invalida");
	if (e.expresie != nullptr)
	{
		delete[] e.expresie;
	}
	e.expresie = new char[copie.size() + 1];
	strcpy_s(e.expresie, copie.size() + 1, copie.c_str());
	return in;
}

int main() {
	Expresie e;
	cin >> e;
	cout << e;
}