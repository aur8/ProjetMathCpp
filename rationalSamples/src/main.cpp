#include <iostream>
#include "ratio.hpp"

int main() {

    rationalNumber rn1(100,9);
    rationalNumber rn2(-5,10);
    rationalNumber rn3 = rn1+rn2;
    rationalNumber rn4 = rn3.inverse();
    rationalNumber rn5 = rn4.absolute();
    rationalNumber rn6 = rn5.power(-3);
    rationalNumber rn7 = -rn6;
    double x = 68.125;
    int y = 4;
    float z = 12.5;
    rationalNumber rn8 = convertRealToRatio(x, 20);
    rationalNumber rn9 = convertRealToRatio(y, 20);
    rationalNumber rn10 = convertRealToRatio(z, 20);
    rationalNumber rn11 = 4 - rn10;
    rationalNumber rn12 = rn10 * 2.5;
    rationalNumber rn13 = 2.5 * rn10;

    std::cout << "1 : " << rn1 << std::endl;
    std::cout << "2 : " << rn2 << std::endl;
    std::cout << "3 : Sum : " << rn3 << std::endl;
    std::cout << "4 : Inverse of Rational 3 : " << rn4 << std::endl;
    std::cout << "      Integral part of Rational 4 : " << rn4.integralPart() << std::endl;
    std::cout << "5 : Absolute value of Rational 4 : " << rn5 << std::endl;
    std::cout << "6 : Rational 5 power -3 : " << rn6 << std::endl;
    std::cout << "7 : Unary minus with Rational 6 : " << rn7 << std::endl;
    std::cout << "8 : Rational converted from double " << x << " : " << rn8 << std::endl;
    std::cout << "9 : Rational converted from int " << y << " : " << rn9 << std::endl;
    std::cout << "10 : Rational converted from float " << z << " : " << rn10 << std::endl;
    std::cout << "11 : 4 - Rational 10 : " << rn11 << std::endl;
    std::cout << "12 : Rational 10 * 2.5 : " << rn12 << std::endl;
    std::cout << "13 : 2.5 * Rational 10 : " << rn13 << std::endl;
    x-=rn13;
    std::cout << "      68.125 -= Rational 13 : " << x << std::endl;
    rn13-=rn9;
    std::cout << "      Rational 13 -= Rational 9 : " << rn13 << std::endl;
    std::cout << "14 : Square root of : " << rn1 << " = " << rn1.squareRoot() << std::endl;
    std::cout << "15 : Cos of : " << rn1 << " = " << rn1.rnCos() << std::endl;
    std::cout << "16 : Ln of : " << rn1 << " = " << rn1.rnLn() << std::endl;
    return 0;
}
