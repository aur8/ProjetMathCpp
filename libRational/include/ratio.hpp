#pragma once
#include <cmath>
#include <iostream>

class rationalNumber {

    double m_data;

    //constructor
    rationalNumber(const int Numerator=0, const int Denominator=0);

    rationalNumber(const rationalNumber &rn) = default;

    //destructor

    ~rationalNumber() = default;

    //methods

    //operators

    rationalNumber& operator=(const rationalNumber &rn);
    const rationalNumber operator+(const rationalNumber &rn);
    const rationalNumber operator*(const rationalNumber &rn);
    const rationalNumber operator/(const rationalNumber &rn);
    friend std::ostream& operator<< (std::ostream& stream, const rationalNumber& rn);
};