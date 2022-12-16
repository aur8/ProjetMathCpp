#include "ratio.hpp"

rationalNumber::rationalNumber(const int numerator, const unsigned int denominator)
{
    m_numerator = numerator;
    m_denominator = denominator;

}

//operator

const rationalNumber rationalNumber::operator+(const rationalNumber &rn){

    rationalNumber temp;
    temp.m_numerator = (m_numerator*rn.m_denominator)+(m_denominator*rn.m_numerator);
    temp.m_denominator = m_denominator*rn.m_denominator;
    return temp;
}