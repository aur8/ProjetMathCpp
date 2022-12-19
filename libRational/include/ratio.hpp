#pragma once
#include <cmath>
#include <iostream>
#include <numeric>
#include <fstream>

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
    rationalNumber inverse();

    //operators

    rationalNumber & operator=(const rationalNumber &rn);
    const rationalNumber operator+(const rationalNumber &rn);
//     const rationalNumber operator*(const rationalNumber &rn);
//     const rationalNumber operator/(const rationalNumber &rn);
    friend std::ostream& operator<< (std::ostream& stream, const rationalNumber& rn);
//
};