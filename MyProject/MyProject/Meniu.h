#pragma once
#include <iostream>

class Meniu {
public:
    virtual void afiseazaOptiuni() = 0;
    virtual void executaComanda(int optiune) = 0;
    virtual ~Meniu() {}
};
