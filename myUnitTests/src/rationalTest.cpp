#include <gtest/gtest.h>
#include <random>
#include <algorithm>
#include "ratio.hpp"

//fonctionne pas je sais pas pourquoi
TEST (rationalNumberConstructor, defaultConstructor){
  rationalNumber rn(0,1);
  ASSERT_EQ (rn.m_numerator, 0);
  ASSERT_EQ (rn.m_denominateur, 1);
}

//je comprend pas comment on peut comparer les resultats de notre addition
//avec autre chose de manière aléatoire
TEST (rationalNumberArtihmetic, plus) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> uniformIntDistribution(1,10);
  

  for(int run=0; run<100; ++run){
    int x1 = uniformIntDistribution(generator);
    unsigned int y1 = uniformIntDistribution(generator);
    int x2 = uniformIntDistribution(generator);
    unsigned int y2 = uniformIntDistribution(generator);

    //generate random data
    std::ratio<int> ratio1(x1,y1);
    std::ratio<int> ratio2(x2,y2);

    //build the corresponding rationalNumber
    rationalNumber rn1(x1,y1), rn2(x2,y2), rn3;
    rn3 = rn1 + rn2;

  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

