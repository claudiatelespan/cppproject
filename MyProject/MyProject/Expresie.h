#pragma once
#include "StackOperanzi.h"
#include "Operator.h"
#include "Meniu.h"
#include <iostream>
#include <string>

class Expresie : public Meniu{
private:
    char* expresie;
    StackOperanzi operanzi;
    Operator* operatori;
    double rezultat;
    bool folosit;
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
    void afiseazaOptiuni();
    void executaComanda(int optiune);

    friend std::ostream& operator<<(std::ostream& out, const Expresie& e);
    friend std::istream& operator>>(std::istream& in, Expresie& e);
};