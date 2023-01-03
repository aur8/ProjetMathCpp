#pragma once
#include <cmath>
#include <iostream>
#include <numeric>
#include <fstream>
#include <cassert>
#include <stdexcept>

class rationalNumber {

    private :

    int m_numerator;
    unsigned int m_denominator;

    public :

    // Constructors
    rationalNumber(int numerator=0, unsigned int denominator=1);
    rationalNumber(const rationalNumber &rn) = default;

    // Destructors
    ~rationalNumber() = default;

    // Getters
    [[nodiscard]] int getNumerator() const;
    [[nodiscard]] int getDenominator() const;

    // Methods
    void display() const;
    rationalNumber irreducible();
    rationalNumber square();
    rationalNumber squareRoot();
    double convertRatioToFloat() const;
    rationalNumber inverse() const;
    rationalNumber absolute();
    int integralPart();
    rationalNumber power(int k);
    [[nodiscard]] rationalNumber rnCos() const;
    /*rationalNumber rnExp();
    rationalNumber rnLn() const;*/

    // Operators
    rationalNumber & operator=(const rationalNumber &rn);
    rationalNumber operator+(const rationalNumber &rn) const;
    rationalNumber operator+(const double &x) const;
    rationalNumber operator-(const rationalNumber &rn) const;
    rationalNumber operator-(const double &x) const;
    const rationalNumber operator*(const rationalNumber &rn);
    rationalNumber operator*(const double &x);
    rationalNumber operator/(const rationalNumber &rn) const;
    rationalNumber operator/(const double &x) const;
    const rationalNumber operator-(); //moins unaire
    rationalNumber operator+=(const rationalNumber &rn);
    rationalNumber operator+=(const double &x);
    rationalNumber operator-=(const rationalNumber &rn);
    rationalNumber operator-=(const double &x);

    bool operator==(const rationalNumber &rn) const;
    bool operator!=(const rationalNumber &rn) const;
    bool operator>(const rationalNumber &rn) const;
    bool operator<(const rationalNumber &rn) const;
    bool operator>=(const rationalNumber &rn) const;
    bool operator<=(const rationalNumber &rn) const;

    friend std::ostream& operator<< (std::ostream& stream, const rationalNumber& rn);

    template <typename T>
    friend T operator+=(T &x, const rationalNumber &rn){
        double y = rn.convertRatioToFloat();
        x += y;
        return x;
    }

    template <typename T>
    friend T operator-=(T &x, const rationalNumber &rn){
        double y = rn.convertRatioToFloat();
        x -= y;
        return x;
    }
};

// Non-member operators

rationalNumber operator+(const double &x, const rationalNumber &rn);
rationalNumber operator-(const double &x, const rationalNumber &rn);
rationalNumber operator*(const double &x, const rationalNumber &rn);
rationalNumber operator/(const double &x, const rationalNumber &rn);

// Non-member functions

template <typename T>
rationalNumber convertRealToRatio(const T &x, const int &nb_iter){
    if (std::is_floating_point<T>::value == true){
        if (x == 0){
            return {0,1};
        }

        if (nb_iter == 0){
            return {0, 1};
        }

        if (x < 1){
            return convertRealToRatio(1/x, nb_iter).power(-1);
        }

        if (x > 1){
            int q = std::floor(x);
            rationalNumber rn(q, 1);
            return rn + convertRealToRatio(x-q, nb_iter-1);
        }
    } else if (std::is_integral<T>::value == true){
        return {(int)x, 1};
    }

    throw std::invalid_argument("The variable to convert should be a integer or a floating point.");
}