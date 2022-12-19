#include "ratio.hpp"

rationalNumber::rationalNumber(const int numerator, const unsigned int denominator)
{
    m_numerator = numerator;
    m_denominator = denominator;

    this->irreducible();
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

rationalNumber rationalNumber::inverse() {
    // insérer une exception ou assert

    if (m_numerator != 0 && m_denominator != 0){
        rationalNumber temp(m_denominator, m_numerator);
        return temp;
    }

    return 0;
}

std::ostream& operator<< (std::ostream& stream, const rationalNumber& rn) {
    /*if(v.size() == 0){
        stream << "Not initialized yet -> size is 0";
        return stream;
    }*/

    stream << rn.m_numerator << "/" << rn.m_denominator;

    return stream;
}