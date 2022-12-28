cmake_minimum_required(VERSION 3.13)

enable_testing()

# remplacer la partie suivante par la partie commentée quand on a fini avec les tests

add_executable(myTest src/rationalTest.cpp)
target_link_libraries(myTest gtest Rational)
target_compile_features(myTest PRIVATE cxx_std_14)

add_test(NAME myTest
        COMMAND myTest)

#[[find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(myUnitTests src/rationalTest.cpp)
target_link_libraries(myUnitTests PUBLIC VectorD GTest::GTest GTest::Main)
target_compile_features(myUnitTests PRIVATE cxx_std_14)

gtest_discover_tests(myUnitTests)]]



