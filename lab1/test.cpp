//
// Created by kurya on 10.09.2022.
//

#include <gtest/gtest.h>
//#include <gtest/>
#include "Segment.h"
#include "SquarPolynomial.h"
#include "BaseFunc.h"
#include "Bisection.h"

TEST(SegmentTest, WorkTest) {
    Segment segment(0, 1);
    BaseFunc baseFunc(0.001);
    SquarPolynomial squarPolynomial(1, 0, -3, baseFunc);
    segment.findInfinitySegment(&squarPolynomial, false);
    ASSERT_EQ(segment.getA(), -2);
    ASSERT_EQ(segment.getB(), -1);

    Segment segment1(0, 1);
    segment1.findInfinitySegment(&squarPolynomial, true);
    ASSERT_EQ(segment1.getA(), 1);
    ASSERT_EQ(segment1.getB(), 2);
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