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
    double convertRatioToFloat() const;
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

template <typename T>
rationalNumber convertFloatToRatio(const T &x, const int &nb_iter){
    if (std::is_floating_point<T>::value == true){
        if (x == 0){
            return {0,1};
        }

        if (nb_iter == 0){
            return {0, 1};
        }

        if (x < 1){
            return convertFloatToRatio(1/x, nb_iter).power(-1);
        }

        if (x > 1){
            int q = std::floor(x);
            rationalNumber rn(q, 1);
            return rn + convertFloatToRatio(x-q, nb_iter-1);
        }
    } else if (std::is_integral<T>::value == true){
        return {(int)x, 1};
    }

    // x n'est ni un point flottant ni un entier, envoyer une exception
    return 0;
}