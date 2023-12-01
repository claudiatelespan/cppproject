#include <iostream>
#include <string>
#include <cmath>
#include "Expresie.cpp"
using namespace std;

ostream& operator<<(ostream& out, const Expresie& e) {
	out << "Rezultatul expresiei:" << e.solution;
	return out;
}

istream& operator>>(istream& in, Expresie& e) {
	cout << "Introduceti expresie: ";
	string copie;
	in >> copie;
	e.setExpresie(copie.c_str());
	return in;
}

int main() {
	/*Expresie e;
	cin >> e;
	cout << e;*/

}