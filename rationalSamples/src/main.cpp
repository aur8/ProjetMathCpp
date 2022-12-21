#include <iostream>
#include "ratio.hpp"

int main() {

    rationalNumber rn1(-3,4);
    rationalNumber rn2(-5,10);
    rationalNumber rn3 = rn1+rn2;
    rationalNumber rn4 = rn3.inverse();
    rationalNumber rn5 = rn4.absolute();
    rationalNumber rn6 = rn5.power(3);
    rationalNumber rn7 = -rn6;

    std::cout << "1 : " << rn1 << std::endl;
    std::cout << "2 : " << rn2 << std::endl;
    std::cout << "3 : Sum : " << rn3 << std::endl;
    std::cout << "4 : Inverse of Rational 3 : " << rn4 << std::endl;
    std::cout << "      Integral part of Rational 4 : " << rn4.integralPart() << std::endl;
    std::cout << "5 : Absolute value of Rational 4 : " << rn5 << std::endl;
    std::cout << "6 : Rational 5 power 3 : " << rn6 << std::endl;
    std::cout << "7 : Unary minus with Rational 6 : " << rn7 << std::endl;

    return 0;
}
