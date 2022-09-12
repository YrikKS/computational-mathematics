//
// Created by kurya on 10.09.2022.
//

#include <gtest/gtest.h>
//#include <gtest/>
#include "Segment.h"
#include "SquarPolynomial.h"
#include "BaseFunc.h"
#include "Bisection.h"
#include "FindRootCubicPol.h"

TEST(SegmentTest, WorkTest) {
    Segment segment(-7, 0);
    BaseFunc baseFunc(0.001);
    SquarPolynomial squarPolynomial(1, 0, -3, baseFunc);
    segment.findInfinitySegment(&squarPolynomial, false, 0);
    std::cout << segment.getA() << std::endl;
//    ASSERT_EQ(segment.getA(), -7);
    ASSERT_EQ(segment.getB(), 0);

    Segment segment1(0, 7);
    segment1.findInfinitySegment(&squarPolynomial, true, 0);
    ASSERT_EQ(segment1.getA(), 0);
    ASSERT_EQ(segment1.getB(), 7);
}

TEST(SquarPolynomial, WorkTest) {
    BaseFunc baseFunc(0.001);
    SquarPolynomial squarPolynomial(1, 0, -4, baseFunc);
    ASSERT_EQ(squarPolynomial.getRoot().first, -2);
    ASSERT_EQ(2, squarPolynomial.getRoot().second);
    ASSERT_EQ(squarPolynomial.getRootCount(), RootCount::TWO);

    SquarPolynomial squarPolynomial1(1, 0, 0, baseFunc);
    ASSERT_EQ(squarPolynomial1.getRoot().first, 0);
    ASSERT_EQ(RootCount::ONE, squarPolynomial1.getRootCount());

    SquarPolynomial squarPolynomial2(1, 0, 4, baseFunc);
    ASSERT_EQ(RootCount::ZERO, squarPolynomial2.getRootCount());
}

TEST(BaseFunc, WorkTest) {
    BaseFunc baseFunc(0.01);
    ASSERT_TRUE(baseFunc.isHitWithAccuracy(0.001));
    ASSERT_TRUE(baseFunc.isHitWithAccuracy(-0.001));
    ASSERT_FALSE(baseFunc.isHitWithAccuracy(0.1));
}

TEST(Bisection, WorkTEst) {
    Bisection bisection;
    BaseFunc baseFunc(0.001);
    SquarPolynomial squarPolynomial(1, 0, -4, baseFunc);
    Segment segment(0, 6);
    ASSERT_LE(bisection.findRoot(&squarPolynomial, baseFunc, segment) - 2, baseFunc.getAccuracy());

    Segment segment1(-6, 0);
    ASSERT_LE(bisection.findRoot(&squarPolynomial, baseFunc, segment1) + 2, baseFunc.getAccuracy());
}

TEST(FindAllTEst, WorkTest){
    FindRootCubicPol finder(0.0001, 1, -107, 710, -1000);
    BaseFunc baseFunc(0.0001);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0() - 2), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot1() - 5), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot2() - 100), baseFunc.getAccuracy());

    finder.setAll(0.00001, 1, 27, 150, 200);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0() + 20), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot1() + 5), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot2() + 2), baseFunc.getAccuracy());

    finder.setAll(0.0001, 1, 8, 20, 16);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0() + 2), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot1() + 4), baseFunc.getAccuracy());
//    ASSERT_LE(std::abs(finder.getRoot2() - 20), baseFunc.getAccuracy());

    finder.setAll(0.0001, 1, 103, 290, -1000);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0() + 100), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot1() + 5), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot2() - 2), baseFunc.getAccuracy());

    finder.setAll(0.0001, 1, 0, -12, 16);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0() - 2), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot1() + 4), baseFunc.getAccuracy());

    finder.setAll(0.0001, 1, -8, 20, -16);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0() - 2), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot1() - 4), baseFunc.getAccuracy());

    finder.setAll(0.0001, 1, -2, 0, 0);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0()), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot1() - 2), baseFunc.getAccuracy());

    finder.setAll(0.0001, 1, 200000, 0, 0);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0()), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot1() + 200000), baseFunc.getAccuracy());

    finder.setAll(0.0001, 1, -100000, 0, 0);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0()), baseFunc.getAccuracy());
    ASSERT_LE(std::abs(finder.getRoot1() - 100000), baseFunc.getAccuracy());

    finder.setAll(0.0001, 1, 0, 0, 0);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0()), baseFunc.getAccuracy());


    finder.setAll(0.0001, 1, 0, 0, 0);
    finder.findRoot();
    finder.printAll();
    ASSERT_LE(std::abs(finder.getRoot0()), baseFunc.getAccuracy());

}