#include <iostream>
#include "Expresie.h"
using namespace std;

int main() {

	Expresie e;
	StackOperanzi s;
	cin >> s;
	cout << s;
	e.runCalculator();

	return 0;
}