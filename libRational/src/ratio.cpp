#include "ratio.hpp"

#include <cmath>

// Constructors

rationalNumber::rationalNumber(const int numerator, const unsigned int denominator){
    m_numerator = numerator;
    m_denominator = denominator;
    this->irreducible();
}

// Getters

int rationalNumber::getNumerator() const{
    return m_numerator;
}

int rationalNumber::getDenominator() const{
    return (int)m_denominator;
}

// Methods

void rationalNumber::display() const{
    std::cout << m_numerator << "/" << m_denominator << std::endl;
}

rationalNumber rationalNumber::irreducible() {
    int gcd = std::gcd(m_numerator, m_denominator);
    m_numerator = m_numerator/gcd;
    m_denominator = m_denominator/gcd;
    return *this;
}

rationalNumber rationalNumber::square(){
    rationalNumber temp;
    temp.m_numerator = m_numerator*m_numerator;
    temp.m_denominator = m_denominator*m_denominator;
    temp.irreducible();
    return temp;
}

rationalNumber rationalNumber::squareRoot(){
    if (m_numerator < 0){
        throw std::invalid_argument("Square root of a negative number cannot be calculated.");
    }
    double x = sqrt(m_numerator);
    double y = sqrt(m_denominator);
    if (floor(x) == x && floor(y) == y){
        return {(int)x, (unsigned int)y};
    } else {
        rationalNumber temp;
        double res = x/y;
        temp = convertRealToRatio(res,20);
        return temp;
    }
}

rationalNumber rationalNumber::inverse() const{

    if (m_numerator != 0 && m_denominator != 0){
        if (m_numerator > 0){
            rationalNumber temp((int)m_denominator, m_numerator);
            return temp;
        } else {
            rationalNumber temp(-1*(int)m_denominator, -m_numerator);
            return temp;
        }
    } else {
        throw std::invalid_argument("The numerator and the denominator both can't be 0.");
    }
}

rationalNumber rationalNumber::absolute(){
    if (m_numerator < 0){
        rationalNumber temp(-m_numerator, m_denominator);
        return temp;
    } else {
        return *this;
    }
}

int rationalNumber::integralPart(){
    int part;
    if (m_numerator >= 0){
        part = floor(this->convertRatioToFloat());
    } else {
        part = ceil(this->convertRatioToFloat());
    }
    return part;
}

rationalNumber rationalNumber::power(int k){
    if (k > 0){
        rationalNumber temp((int)pow(m_numerator, k), (unsigned int)pow(m_denominator, k));
        return temp.irreducible();
    } else if (k == 0){
        return {1, 0};
    } else if (k < 0) {
        rationalNumber temp((int)pow(m_numerator, -k), (int)pow(m_denominator, -k));
        return temp.inverse().irreducible();
    }
}

double rationalNumber::convertRatioToFloat() const {
    return ((double)m_numerator/m_denominator);
}

rationalNumber rationalNumber::rnCos() const{
    rationalNumber temp;
    double res = cos (m_numerator/m_denominator);
    temp = convertRealToRatio(res,20);
    return temp;
}

/*rationalNumber rationalNumber::rnExp(){
    rationalNumber temp;
    double res = exp (m_numerator/m_denominator);
    temp = convertRealToRatio(res,20);
    return temp;
}

rationalNumber rationalNumber::rnLn() const{
    return log(m_numerator) - log(m_denominator);
}*/

// Operators

rationalNumber & rationalNumber::operator=(const rationalNumber &rn){
    m_numerator = rn.m_numerator;
    m_denominator = rn.m_denominator;

    this->irreducible();

    return *this;
}

rationalNumber rationalNumber::operator+(const rationalNumber &rn) const{
    rationalNumber temp;
    temp.m_numerator = (m_numerator*rn.m_denominator)+(m_denominator*rn.m_numerator);
    temp.m_denominator = m_denominator*rn.m_denominator;
    temp.irreducible();
    return temp;
}

rationalNumber rationalNumber::operator+(const double &x) const{
    rationalNumber rn = convertRealToRatio(x, 20);
    return *this+rn;
}

rationalNumber operator+(const double &x, const rationalNumber &rn){
    rationalNumber rn2 = convertRealToRatio(x, 20);
    return rn2+rn;
}

rationalNumber rationalNumber::operator-(const rationalNumber &rn) const{
    rationalNumber temp;
    temp.m_numerator = (m_numerator*rn.m_denominator)-(m_denominator*rn.m_numerator);
    temp.m_denominator = m_denominator*rn.m_denominator;
    temp.irreducible();
    return temp;
}

rationalNumber rationalNumber::operator-(const double &x) const{
    rationalNumber rn(x, 1);
    return *this-rn;
}

rationalNumber operator-(const double &x, const rationalNumber &rn){
    rationalNumber rn2(x, 1);
    return rn2-rn;
}

const rationalNumber rationalNumber::operator-(){
    rationalNumber temp;
    temp.m_numerator = -1*m_numerator;
    temp.m_denominator = m_denominator;
    return temp;
}

const rationalNumber rationalNumber::operator*(const rationalNumber &rn){
    rationalNumber temp;
    temp.m_numerator = m_numerator*rn.m_numerator;
    temp.m_denominator = m_denominator*rn.m_denominator;
    temp.irreducible();
    return temp;
}

rationalNumber rationalNumber::operator*(const double &x){
    rationalNumber rn = convertRealToRatio(x, 20);
    return *this*rn;
}

rationalNumber operator*(const double &x, const rationalNumber &rn){
    rationalNumber rn2 = convertRealToRatio(x, 20);
    return rn2*rn;
}

rationalNumber rationalNumber::operator/(const rationalNumber &rn) const{
    rationalNumber temp;
    temp.m_numerator = m_numerator*rn.m_denominator;
    temp.m_denominator = m_denominator*rn.m_numerator;
    temp.irreducible();
    return temp;
}

rationalNumber rationalNumber::operator/(const double &x) const{
    rationalNumber rn = convertRealToRatio(x, 20);
    return *this/rn;
}

rationalNumber operator/(const double &x, const rationalNumber & rn){
    rationalNumber rn2 = convertRealToRatio(x, 20);
    return rn2/rn;
}

rationalNumber rationalNumber::operator+=(const rationalNumber &rn){
    *this = *this + rn;
    return (*this).irreducible();
}

rationalNumber rationalNumber::operator+=(const double &x){
    rationalNumber rn = convertRealToRatio(x, 20);
    *this += rn;
    return (*this).irreducible();
}

rationalNumber rationalNumber::operator-=(const rationalNumber &rn){
    *this = *this - rn;
    return (*this).irreducible();
}

rationalNumber rationalNumber::operator-=(const double &x){
    rationalNumber rn = convertRealToRatio(x, 20);
    *this -= rn;
    return (*this).irreducible();
}

bool rationalNumber::operator==(const rationalNumber &rn) const{
    return (m_numerator == rn.m_numerator) && (m_denominator == rn.m_denominator);
}

bool rationalNumber::operator!=(const rationalNumber &rn) const{
    return (m_numerator != rn.m_numerator) || (m_denominator != rn.m_denominator);
}

bool rationalNumber::operator>(const rationalNumber &rn) const{
    return (this->convertRatioToFloat() > rn.convertRatioToFloat());
}

bool rationalNumber::operator<(const rationalNumber &rn) const{
    return (this->convertRatioToFloat() < rn.convertRatioToFloat());
}

bool rationalNumber::operator>=(const rationalNumber &rn) const{
    return (this->convertRatioToFloat() >= rn.convertRatioToFloat());
}


bool rationalNumber::operator<=(const rationalNumber &rn) const{
    return (this->convertRatioToFloat() <= rn.convertRatioToFloat());
}

std::ostream& operator<< (std::ostream& stream, const rationalNumber& rn) {
    stream << rn.m_numerator << "/" << rn.m_denominator;
    return stream;
}

