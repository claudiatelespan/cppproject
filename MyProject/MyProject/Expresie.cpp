#include "Expresie.h"
#include <iomanip>

using namespace std;

const double Expresie::REZULTAT_DEFAULT = -1.0;

Expresie::Expresie() :expresie(nullptr), rezultat(REZULTAT_DEFAULT), operatori(nullptr), operanzi() {

}

Expresie::Expresie(const char* expr) :operatori(nullptr), operanzi() {
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
	if (expresie != nullptr)
		delete[] expresie;
	expresie = new char[strlen(expr) + 1];
	strcpy_s(expresie, strlen(expr) + 1, expr);
}

void Expresie::evaluateExpresie() {
    const int maxOperatori = 10;
    Operator stivaOperatori[maxOperatori];
    int topOperatori = -1;

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
            while (i + 1 < strlen(expresie) && (isdigit(expresie[i + 1]) || expresie[i + 1] == '.')) {
                ++i;
            }
        }
        else if (expresie[i] == '+' || expresie[i] == '-' || expresie[i] == '*' || expresie[i] == '/' || expresie[i] == '^' || expresie[i] == '#') {
            // Construieste operatorul
            Operator currentOperator(expresie[i]);
            // Proceseaza operatorii existenti cu precedenta mai mare sau egala
            while (topOperatori >= 0 &&
                !stivaOperatori[topOperatori].isOpenParenthesis() &&
                stivaOperatori[topOperatori] >= currentOperator &&
                ((currentOperator.isLeftAssociative() && stivaOperatori[topOperatori] == currentOperator) ||
                    stivaOperatori[topOperatori] > currentOperator)) {
                double operand2 = operanzi.getTop();
                --operanzi;
                double operand1 = operanzi.getTop();
                --operanzi;
                Operator op = stivaOperatori[topOperatori--];
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
            stivaOperatori[++topOperatori] = currentOperator;
        }
        else if (expresie[i] == '(') {
            // Adauga paranteza deschisa la stivaOperatori
            stivaOperatori[++topOperatori] = Operator('(');
        }
        else if (expresie[i] == ')') {
            // Proceseaza operatorii pana la paranteza deschisa corespunzatoare
            while (topOperatori >= 0 && !stivaOperatori[topOperatori].isOpenParenthesis()) {
                double operand2 = operanzi.getTop();
                --operanzi;
                double operand1 = operanzi.getTop();
                --operanzi;
                Operator op = stivaOperatori[topOperatori--];
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
            if (topOperatori >= 0 && stivaOperatori[topOperatori].isOpenParenthesis()) {
                --topOperatori;
            }
            else {
                throw std::invalid_argument("Paranteza inchisa fara corespondent deschis");
            }
        }
    }

    // Proceseaza operatorii ramasi
    while (topOperatori >= 0) {
        double operand2 = operanzi.getTop();
        --operanzi;
        double operand1 = operanzi.getTop();
        --operanzi;
        Operator op = stivaOperatori[topOperatori--];
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
        --operanzi;
    }
    else {
        throw std::invalid_argument("Expresie invalida");
    }
}

double Expresie::getRezultat() const {
	return rezultat;
}

void Expresie::runCalculator() {
    cin >> *this;
    while (strcmp(this->getExpresie(), "exit") != 0) {
        this->evaluateExpresie();
        cout << *this;
        cin >> *this;
    }
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
    e.setExpresie(Expresie::removeSpaces(copie.c_str()));
	return in;
}

char* Expresie::removeSpaces(const char* input) {
    char* result = new char[strlen(input) + 1];
    int j = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] != ' ') {
            result[j++] = input[i];
        }
    }
    result[j] = '\0';
    return result;
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
}

	


