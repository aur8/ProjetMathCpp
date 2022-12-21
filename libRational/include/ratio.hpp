#pragma once
#include <cmath>
#include <iostream>
#include <numeric>
#include <fstream>
#include <cassert>

class rationalNumber {

    public :

    int m_numerator;
    unsigned int m_denominator;

    //constructor
    rationalNumber(const int numerator=0, const unsigned int denominator=1);

    rationalNumber(const rationalNumber &rn) = default;

    //destructor

    ~rationalNumber() = default;

    //methods
    void display() const;
    rationalNumber irreducible();
    rationalNumber square();
    rationalNumber squareRoot();
    rationalNumber convertFloatToRatio(const float &x, const int &nb_iter);
    double convertRatioToFloat() const;
    rationalNumber checkNoNegativeOnDenominator();
    rationalNumber inverse() const;
    rationalNumber absolute();
    int integralPart();
    rationalNumber power(int k);

    //operators

    rationalNumber & operator=(const rationalNumber &rn);
    const rationalNumber operator+(const rationalNumber &rn);
    const rationalNumber operator-(const rationalNumber &rn);
    const rationalNumber operator*(const rationalNumber &rn);
    const rationalNumber operator/(const rationalNumber &rn);
    const rationalNumber operator-(); //moins unaire
    bool operator==(const rationalNumber &rn) const;
    bool operator!=(const rationalNumber &rn) const;
    bool operator>(const rationalNumber &rn) const;
    bool operator<(const rationalNumber &rn) const;
    bool operator>=(const rationalNumber &rn) const;
    bool operator<=(const rationalNumber &rn) const;
    friend std::ostream& operator<< (std::ostream& stream, const rationalNumber& rn);
//
};