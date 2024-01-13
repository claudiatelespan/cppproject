#include <iostream>

#include "Expresie.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 2) {
        char* ecuatie = argv[1];
        Expresie ex(ecuatie);
        ex.evaluateExpresie();
        cout << ex;
    }
    else {
        Expresie e;
        int tipComanda=-1;
        while (tipComanda != 0) {
            e.afiseazaOptiuni();
            cout << "Introduceti optiunea dvs.: ";
            cin>>tipComanda;
            cin.ignore();
            e.executaComanda(tipComanda);
            
        }
    }

	return 0;
}