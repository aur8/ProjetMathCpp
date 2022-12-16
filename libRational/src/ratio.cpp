#include "ratio.hpp"

rationalNumber::rationalNumber(const int numerator, const unsigned int denominator)
{
    m_numerator = numerator;
    m_denominator = denominator;

}

rationalNumber & rationalNumber::operator=(const rationalNumber &rn){
    m_numerator = rn.m_numerator;
    m_denominator = rn.m_denominator;

    return *this;
}


const rationalNumber rationalNumber::operator+(const rationalNumber &rn){

    rationalNumber ratio();
    
    return rn;
}

void rationalNumber::display() const{
    std::cout << m_numerator << "/" << m_denominator << std::endl;
}