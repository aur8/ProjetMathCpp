#include <iostream>
#include "ratio.hpp"

int main() {

    int a = 9;
    std::cout << a << std::endl;

    rationalNumber rn(1,3);
    std::cout << rn.m_numerator << std::endl;

    rationalNumber rn2(48, 5);
    rn2.display();

    rationalNumber rn3(19, 187);
    rn2 = rn3;
    rn2.display();

    return 0;
}
