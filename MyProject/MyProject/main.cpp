#include <iostream>
#include <string>
#include <cmath>
#include "Expresie.cpp"
using namespace std;

ostream& operator<<(ostream& out, const Expression& e) {
	out << "Rezultatul expresiei:" << e.solution;
	return out;
}

istream& operator>>(istream& in, Expression& e) {
	cout << "Introduceti expresie: ";
	string copie;
	in >> copie;
	e.setExpression(copie.c_str());
	return in;
}

int main() {
	/*Expresie e;
	cin >> e;
	cout << e;*/

}