#pragma once
#include <cmath>
#include <iostream>

class rationalNumber {

    public :

    int m_numerator;
    unsigned int m_denominator;

    //constructor
    rationalNumber(const int numerator=0, const unsigned int denominator=0);

    rationalNumber(const rationalNumber &rn) = default;

    //destructor

    ~rationalNumber() = default;

    //methods

    //operators

//     rationalNumber& operator=(const rationalNumber &rn);
    const rationalNumber operator+(const rationalNumber &rn);
//     const rationalNumber operator*(const rationalNumber &rn);
//     const rationalNumber operator/(const rationalNumber &rn);
//     friend std::ostream& operator<< (std::ostream& stream, const rationalNumber& rn);
// 
};