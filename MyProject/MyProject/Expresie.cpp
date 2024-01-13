#include "Expresie.h"
#include <iomanip>
#include <fstream> 
#include <sstream>
#include <stack>
using namespace std;

const double Expresie::REZULTAT_DEFAULT = -1.0;

Expresie::Expresie() :expresie(nullptr), rezultat(REZULTAT_DEFAULT), operatori(nullptr), operanzi(),folosit(false) {

}

Expresie::Expresie(const char* expr) :operatori(nullptr), operanzi(), folosit(false) {
	this->setExpresie(expr);
}

Expresie::Expresie(const Expresie& e) {
	this->setExpresie(e.expresie);
	operanzi = e.operanzi;
	operatori = e.operatori;
    folosit = e.folosit;
}
	
Expresie& Expresie::operator=(const Expresie& e) {
	if (this != &e) {
		this->setExpresie(e.expresie);
		operatori = e.operatori;
		operanzi = e.operanzi;
        folosit = e.folosit;
	}
	return *this;
}

char* Expresie::getExpresie() const {
	return expresie;
}

void Expresie::setExpresie(const char* expr) {
	if (expr == nullptr || strlen(expr) < 3)
		throw exception("Expresie invalida");
	if (operatori != nullptr)
	{
		delete[] operatori;
		operatori = nullptr;
	}
	if (expresie != nullptr)
		delete[] expresie;

	expresie = new char[strlen(expr) + 1];
	strcpy_s(expresie, strlen(expr) + 1, expr);
}

void Expresie::evaluateExpresie() {
    stack<Operator> stivaOperatori;
    
    //Inlocuiesc parantezele patrate cu rotunde
    for (int i = 0; i < strlen(expresie); ++i) {
        if (expresie[i] == '[')
            expresie[i] = '(';
        else if (expresie[i] == ']')
            expresie[i] = ')';
    }
        
    for (int i = 0; i < strlen(expresie); ++i) {
        if (isdigit(expresie[i])) {
            // Construieste operandul
            double val = stod(&expresie[i]);
            operanzi = operanzi + val;
            int temp = 0;
            while (i + 1 < strlen(expresie) && (isdigit(expresie[i + 1]) || expresie[i + 1] == '.')) {
                if (expresie[i + 1] == '.')
                    temp++;
                ++i;
            }
            if (temp > 1)
                throw std::invalid_argument("Numar invalid");
        }
        else if (expresie[i] == '+' || expresie[i] == '-' || expresie[i] == '*' || expresie[i] == '/' || expresie[i] == '^' || expresie[i] == '#') {
            // Construieste operatorul
            Operator currentOperator(expresie[i]);
            // Proceseaza operatorii existenti cu precedenta mai mare sau egala
            while (stivaOperatori.size() > 0 &&
                !stivaOperatori.top().isOpenParenthesis() &&
                stivaOperatori.top() >= currentOperator &&
                ((currentOperator.isLeftAssociative() && stivaOperatori.top() == currentOperator) ||
                    stivaOperatori.top() > currentOperator)) {
                double operand2 = operanzi.getTop();
                --operanzi;
                double operand1 = operanzi.getTop();
                --operanzi;
                Operator op = stivaOperatori.top();
                stivaOperatori.pop();
                switch (op.getOperator()) {
                case '+':
                    operanzi = operanzi + (operand1 + operand2);
                    break;
                case '-':
                    operanzi = operanzi + (operand1 - operand2);
                    break;
                case '*':
                    operanzi = operanzi + (operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        operanzi = operanzi + (operand1 / operand2);
                    }
                    else {
                        throw std::invalid_argument("Impartire la zero");
                    }
                    break;
                case '^':
                    operanzi = operanzi + pow(operand1, operand2);
                    break;
                case '#':
                    operanzi = operanzi + pow(operand1, 1 / operand2);
                    break;
                }
            }

            // Adauga operatorul curent la stivaOperatori
            stivaOperatori.push(currentOperator);
        }
        else if (expresie[i] == '(') {
            // Adauga paranteza deschisa la stivaOperatori
            stivaOperatori.push(Operator('('));
        }
        else if (expresie[i] == ')') {
            // Proceseaza operatorii pana la paranteza deschisa corespunzatoare
            while (stivaOperatori.size() > 0 && !stivaOperatori.top().isOpenParenthesis()) {
                double operand2 = operanzi.getTop();
                --operanzi;
                double operand1 = operanzi.getTop();
                --operanzi;
                Operator op = stivaOperatori.top();
                stivaOperatori.pop();
                switch (op.getOperator()) {
                case '+':
                    operanzi = operanzi + (operand1 + operand2);
                    break;
                case '-':
                    operanzi = operanzi + (operand1 - operand2);
                    break;
                case '*':
                    operanzi = operanzi + (operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        operanzi = operanzi + (operand1 / operand2);
                    }
                    else {
                        throw std::invalid_argument("Impartire la zero");
                    }
                    break;
                case '^':
                    operanzi = operanzi + pow(operand1, operand2);
                    break;
                case '#':
                    operanzi = operanzi + pow(operand1, 1 / operand2);
                    break;
                }
            }

            // Elimina paranteza deschisa din stivaOperatori
            if (stivaOperatori.size() > 0 && stivaOperatori.top().isOpenParenthesis()) {
                stivaOperatori.pop();
            }
            else {
                throw std::invalid_argument("Paranteza inchisa fara corespondent deschis");
            }
        }
    }

    // Proceseaza operatorii ramasi
    while (stivaOperatori.size() > 0) {
        double operand2 = operanzi.getTop();
        --operanzi;
        double operand1 = operanzi.getTop();
        --operanzi;
        Operator op = stivaOperatori.top();
        stivaOperatori.pop();
        switch (op.getOperator()) {
        case '+':
            operanzi = operanzi + (operand1 + operand2);
            break;
        case '-':
            operanzi = operanzi + (operand1 - operand2);
            break;
        case '*':
            operanzi = operanzi + (operand1 * operand2);
            break;
        case '/':
            if (operand2 != 0) {
                operanzi = operanzi + (operand1 / operand2);
            }
            else {
                throw std::invalid_argument("Impartire la zero");
            }
            break;
        case '^':
            operanzi = operanzi + pow(operand1, operand2);
            break;
        case '#':
            operanzi = operanzi + pow(operand1, 1 / operand2);
            break;
        }
    }

    // Verifica rezultatul final
    if (operanzi.size() == 1) {
        rezultat = operanzi.getTop();
        folosit = true;
        --operanzi;
    }
    else {
        throw std::invalid_argument("Expresie invalida");
    }
}

double Expresie::getRezultat() const {
	return rezultat;
}

bool Expresie::getFolosit() const {
    return folosit;
}

void Expresie::runCalculator() {
    cin >> *this;
    this->evaluateExpresie();
    cout << *this;
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
    if (e.getRezultat() == (int)e.getRezultat()) {
        out << "Rezultatul expresiei: " << (int)e.getRezultat() << endl;
    }
    else {
        out << "Rezultatul expresiei: " << e.getRezultat() << endl;
    }
    return out;
}

istream& operator>>(istream& in, Expresie& e) {
    cout << endl << "Introduceti expresie: ";
	string copie;
    getline(in, copie);
    e.setExpresie(copie.c_str());
	return in;
}

//FAZA 2

void Expresie::citesteEcuatiiDinFisier(const char* fisierCitire) {
    ifstream fisier(fisierCitire);
    if (!fisier.is_open()) {
        cout << "Eroare la deschiderea fisierului!" << endl;
        return;
    }
    
    int optiune;
    cout << "Alegeti modul de afisare:" << endl << "1. Afisare la consola" << endl << "2. Salvare in fisier text" << endl;
    cin >> optiune;

    string fisierAfisare;
    ofstream outFile;

    if(optiune==2){
        cout << "Introduceti numele fisierului pentru salvare: ";
        cin >> fisierAfisare;
        outFile.open(fisierAfisare, ios::trunc);
        if (!outFile.is_open()) {
            cout << "Eroare la deschiderea fisierului pentru scriere!" << endl;
            return;
        }
    }
        
    string linie;
    while (getline(fisier, linie)) {
        this->setExpresie(linie.c_str());
        this->evaluateExpresie();
        if (optiune == 1) {
            cout << "Rezultat: " << this->getRezultat() << endl;
        }
        else if (optiune == 2) {
            outFile << "Rezultat: " << this->getRezultat() << endl;
            cout << "Rezultatul a fost salvat in " << fisierAfisare << endl;
        }
        else {
            cout << "Optiune invalida!" << endl;
        }
    }

    outFile.close();
    fisier.close();
}

void Expresie::afiseazaOptiuni() {
    cout << endl << "Meniu de comenzi" << endl;
    cout << "0. Iesire" << endl;
    cout << "1. Introducere ecuatie" << endl;
    cout << "2. Preluare ecuatii din fisier text" << endl;
    cout << "3. Salvare rezultat precedent" << endl << endl;
}

void Expresie::executaComanda(int tipComanda){
    switch (tipComanda) {
    case 0:
        cout << "La revedere!" << endl;
        break;
    case 1: {
        this->runCalculator();
    }
        break;
    case 2:
    { 
        string fisierCitire;
        cout << "Introduceti numele fisierului cu ecuatii: ";
        cin >> fisierCitire;
        this->citesteEcuatiiDinFisier(fisierCitire.c_str()); 
    }
        break;
    case 3:
    {
        if (!this->getFolosit())
        {
            cout << endl <<"Nu exista rezultat de salvat!" << endl;
            break;
        }
        ofstream f("fisier.bin", ios::out | ios::binary);
        if(!f)
            cout << "Eroare la deschiderea fisierului pentru salvare!" << endl;
        f.write((char*)&this->rezultat, sizeof(this->rezultat));
        cout << endl << "Salvare reusita!" << endl;
    }
        break;
    default:
        cout << "Optiune invalida!" << endl;
        break;
    }
}

//destructori

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
}

	


