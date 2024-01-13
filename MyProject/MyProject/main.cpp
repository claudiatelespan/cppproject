#include <iostream>
#include "Expresie.h"
using namespace std;

int main(int argc, char* argv[]) {

    Expresie e;
    string fisierCitire;
    cout << "Introduceti numele fisierului cu ecuatii: ";
    cin >> fisierCitire;
    e.citesteEcuatiiDinFisier(fisierCitire.c_str());



    /*if (argc == 2) {
        char* ecuatie = argv[1];
        Expresie ex(ecuatie);
        ex.evaluateExpresie();
        cout << ex;
    }
    else {
        
        Expresie e;
        e.runCalculator();
    }*/


	return 0;
}