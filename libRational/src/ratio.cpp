#include "ratio.hpp"

#include <cmath>

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

rationalNumber rationalNumber::operator-(const rationalNumber &rn) const{
    rationalNumber temp;
    temp.m_numerator = (m_numerator*rn.m_denominator)-(m_denominator*rn.m_numerator);
    temp.m_denominator = m_denominator*rn.m_denominator;
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

double rationalNumber::convertRatioToFloat() const {
    return ((double)m_numerator/m_denominator);
}

//method square

rationalNumber rationalNumber::square(){
    rationalNumber temp;
    temp.m_numerator = m_numerator*m_numerator;
    temp.m_denominator = m_denominator*m_denominator;
    temp.irreducible();
    return temp;
}
//method square root
//je pense faudra ameliorer avec la fonction de conversion pour vraiment retourner un ratio
//le assert fonctionne pas
rationalNumber rationalNumber::squareRoot(){
    //assert(m_numerator < 0 == true) && "SquareRoot of an negative number impossible !";
    rationalNumber temp;
    float x = sqrt(m_numerator);
    float y = sqrt(m_denominator);
    float res = x/y;
    temp = convertFloatToRatio(res,20);
    return temp;
}


rationalNumber rationalNumber::inverse() const{
    // insérer une exception ou assert

    if (m_numerator != 0 && m_denominator != 0){
        if (m_numerator > 0){
            rationalNumber temp((int)m_denominator, m_numerator);
            return temp;
        } else {
            rationalNumber temp(-1*(int)m_denominator, -m_numerator);
            return temp;
        }
    }

    return 0;
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
    // les int des numérateurs et dénominateurs ne pourront sûrement pas contenir les valeurs
    // passé des puissances un peu élevées, il faudrait les convertir
}

std::ostream& operator<< (std::ostream& stream, const rationalNumber& rn) {
    /*if(v.size() == 0){
        stream << "Not initialized yet -> size is 0";
        return stream;
    }*/

    stream << rn.m_numerator << "/" << rn.m_denominator;

    return stream;
}

rationalNumber rationalNumber::rnCos(){
    rationalNumber temp;
    double res = cos (m_numerator/m_denominator);
    temp = convertFloatToRatio(res,20);
    return temp;
}