#include <iostream>
#include "ratio.hpp"

int main() {

    int a = 9;
    std::cout << a << std::endl;

    rationalNumber rn(1,3);
    std::cout << rn.m_numerator << std::endl;

    return 0;
}
