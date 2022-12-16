#include <iostream>
#include "ratio.hpp"

int main() {

    int a = 9;
    std::cout << a << std::endl;

    rationalNumber rn1(1,3);
    rationalNumber rn2(1,3);
    rationalNumber rn3 = rn1+rn2;
    std::cout << rn1.m_numerator << std::endl;
    std::cout << rn3.m_numerator << std::endl;
    std::cout << rn3.m_denominator << std::endl;

    rationalNumber rn2(48, 5);
    rn2.display();

    rationalNumber rn3(19, 187);
    rn2 = rn3;
    rn2.display();

    return 0;
}
