#include <iostream>
#include "ratio.hpp"

int main() {

    rationalNumber rn1(2,6);
    rationalNumber rn2(1,3);
    rationalNumber rn3 = rn1+rn2;
    rationalNumber rn4 = rn3.inverse();

    std::cout << rn1 << std::endl;
    std::cout << rn2 << std::endl;
    std::cout << rn3 << std::endl;
    std::cout << rn4 << std::endl;

    return 0;
}
