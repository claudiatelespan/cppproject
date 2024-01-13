#pragma once
#include "StackOperanzi.h"
#include "Operator.h"
#include <iostream>
#include <string>

class Expresie {
private:
    char* expresie;
    StackOperanzi operanzi;
    Operator* operatori;
    double rezultat;
    static const double REZULTAT_DEFAULT;

public:
    Expresie();
    Expresie(const char* expr);
    Expresie(const Expresie& other);
    Expresie& operator=(const Expresie& other);
    ~Expresie();

    char* getExpresie() const;
    void setExpresie(const char* expr);
    void evaluateExpresie();
    double getRezultat() const;
    void runCalculator();
    operator float();
    char& operator[](int index) const;

    //faza 2
    void citesteEcuatiiDinFisier(const char* numeFisier);
    void proceseazaRezultat(double rezultat);

    friend std::ostream& operator<<(std::ostream& out, const Expresie& e);
    friend std::istream& operator>>(std::istream& in, Expresie& e);
};