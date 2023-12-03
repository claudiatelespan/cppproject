#pragma once

class Operand {
private:
    double* values;
    int count;

public:
    Operand();
    Operand(double val);
    Operand(const Operand& other);
    Operand& operator=(const Operand& other);
    ~Operand();

    void addValue(double val);
    double getValue(int index = 0) const;
    int getCount() const;
    bool isSingleValue() const;
    double getSingleValue() const;
};