#include "ratio.hpp"


rationalNumber::rationalNumber(const int numerator, const unsigned int denominator)
{
    m_numerator = numerator;
    m_denominator = denominator;

}



rationalNumber & rationalNumber::operator=(const rationalNumber &rn){
    m_numerator = rn.m_numerator;
    m_denominator = rn.m_denominator;

    this->irreducible();

    return *this;
}


const rationalNumber rationalNumber::operator+(const rationalNumber &rn){

    rationalNumber temp;
    temp.m_numerator = (m_numerator*rn.m_denominator)+(m_denominator*rn.m_numerator);
    temp.m_denominator = m_denominator*rn.m_denominator;

    temp.irreducible();

    return temp;
}

void rationalNumber::display() const{
    std::cout << m_numerator << "/" << m_denominator << std::endl;
}

rationalNumber rationalNumber::irreducible() {
    int gcd = std::gcd(m_numerator, m_denominator);
    m_numerator = m_numerator/gcd;
    m_denominator = m_denominator/gcd;

    return *this;
}

const rationalNumber rationalNumber::operator*(const rationalNumber &rn){
    rationalNumber temp;
    temp.m_numerator = m_numerator*rn.m_numerator;
    temp.m_denominator = m_denominator*rn.m_denominator;
    temp.irreducible();
    return temp;
}

const rationalNumber rationalNumber::operator/(const rationalNumber &rn){
    rationalNumber temp;
    temp.m_numerator = m_numerator*rn.m_denominator;
    temp.m_denominator = m_denominator*rn.m_numerator;
    return temp;
}

const rationalNumber rationalNumber::operator-(const rationalNumber &rn){
    rationalNumber temp;
    temp.m_numerator = (m_numerator*rn.m_denominator)-(m_denominator*rn.m_numerator);
    temp.m_denominator = m_denominator*rn.m_denominator;
    return temp;
}

const rationalNumber rationalNumber::operator--(){
    rationalNumber temp;
    temp.m_numerator = -1*m_numerator;
    temp.m_denominator = m_denominator;
    return temp;
}


//method square

rationalNumber rationalNumber::square(){
    rationalNumber temp;
    temp.m_numerator = m_numerator*m_numerator;
    temp.m_denominator = m_denominator*m_denominator;
    temp.irreducible();
    return temp;
}

//
// rationalNumber rationalNumber::squareRoot(){
//     rationalNumber temp;
//     temp.m_numerator = m_numerator;
//     temp.m_denominator = m_denominator*m_denominator;
//     temp.irreducible();
//     return temp;
// }