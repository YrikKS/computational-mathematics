cmake_minimum_required(VERSION 3.20)
project(lab1)

set(CMAKE_CXX_STANDARD 23)
include_directories(googletest-release-1.12.1/googletest/include)
add_subdirectory(googletest-release-1.12.1)

add_executable(lab1
        main.cpp
        Bisection.cpp
        BaseFunc.cpp
        SquarPolynomial.cpp
        CubicPolynomial.cpp
        Segment.cpp
        Polynomial.h
        FindRootCubicPol.cpp
        Reader.cpp
        )

add_executable(
        Test
        test.cpp
        Bisection.cpp
        BaseFunc.cpp
        SquarPolynomial.cpp
        CubicPolynomial.cpp
        Segment.cpp
        Polynomial.h
        FindRootCubicPol.cpp
        Reader.cpp
)

#add_executable(Test test.cpp Bisection.cpp BaseFunc.cpp SquarPolynomial.cpp CubicPolynomial.cpp Segment.cpp Polynomial.h FindRootCubicPol.cpp)
target_link_libraries(Test gtest gtest_main)

#include(GoogleTest)
#add_executable(
#        Test test.cpp
#        Bisection.cpp
#        BaseFunc.cpp
#        SquarPolynomial.cpp
#        CubicPolynomial.cpp
#        Segment.cpp
#        Polynomial.h
#        FindRootCubicPol.cpp
#)
#
#gtest_add_tests(TARGET      Test
#        TEST_SUFFIX .noArgs
#        TEST_LIST   noArgsTests
#        )
#gtest_add_tests(TARGET      Test
#        EXTRA_ARGS  --someArg someValue
#        TEST_SUFFIX .withArgs
#        TEST_LIST   withArgsTests
#        )
#set_tests_properties(${noArgsTests}   PROPERTIES TIMEOUT 10)
#set_tests_properties(${withArgsTests} PROPERTIES TIMEOUT 20)
