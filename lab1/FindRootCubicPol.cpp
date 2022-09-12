//
// Created by kurya on 08.09.2022.
//

#include <iostream>
#include "FindRootCubicPol.h"

FindRootCubicPol::FindRootCubicPol(double accuracy, double a, double b, double c, double d) {
    FindRootCubicPol::baseFunc = BaseFunc(accuracy);
    FindRootCubicPol::cubicPolynomial = new CubicPolynomial();
    cubicPolynomial->setAll(a, b, c, d, baseFunc);
    multiplicityVector.resize(3);
    multiplicityVector[0] = 1;
    multiplicityVector[1] = 1;
    multiplicityVector[2] = 1;
}

void FindRootCubicPol::findRoot() {
    SquarPolynomial derivative = cubicPolynomial->getDerivative();
    if (derivative.getRootCount() == RootCount::ZERO) {
        findRootWithDerivativeZeroRoot();
    } else if (derivative.getRootCount() == RootCount::ONE) {
        std::cout << "Root " << derivative.getRoot().first << std::endl;
        findRootWithDerivativeOneRoot(derivative);
    } else if (derivative.getRootCount() == RootCount::TWO) {
        std::cout << "Root " << derivative.getRoot().first << " second " << derivative.getRoot().second << std::endl;
        findRootWithDerivativeTwoRoot(derivative);
    }
}

void FindRootCubicPol::findRootWithDerivativeZeroRoot() {
    rootCount = RootCount::ONE;
    if (cubicPolynomial->findValueInPoint(0) > 0) {
        Segment segment(0, 1);
        segment.findInfinitySegment(cubicPolynomial, true);
        root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
    } else {
        Segment segment(-1, 0);
        segment.findInfinitySegment(cubicPolynomial, false);
        root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
    }
}

void FindRootCubicPol::findRootWithDerivativeOneRoot(SquarPolynomial derivative) {
    rootCount = RootCount::TWO;
    double rootDerivative = derivative.getRoot().first;
    Segment segment1(rootDerivative, rootDerivative + 1);
    segment1.findInfinitySegment(cubicPolynomial, true);
    root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment1);

    Segment segment2(rootDerivative - 1, rootDerivative);
    segment2.findInfinitySegment(cubicPolynomial, false);
    root1 = bisection.findRoot(cubicPolynomial, baseFunc, segment2);
}

void FindRootCubicPol::findRootWithDerivativeTwoRoot(SquarPolynomial derivative) {
    std::cout << cubicPolynomial->findValueInPoint(derivative.getRoot().first) << std::endl;
    if (cubicPolynomial->findValueInPoint(derivative.getRoot().first) > baseFunc.getAccuracy()) {
        if (cubicPolynomial->findValueInPoint(derivative.getRoot().second) > baseFunc.getAccuracy()) { // 4
            rootCount = RootCount::ONE;
            Segment segment(derivative.getRoot().first - 1, derivative.getRoot().first);
            segment.findInfinitySegment(cubicPolynomial, false);
            root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
            return;
        } else if (std::abs(cubicPolynomial->findValueInPoint(derivative.getRoot().second)) <
                   baseFunc.getAccuracy()) { // 1
            rootCount = RootCount::TWO;
            root0 = cubicPolynomial->findValueInPoint(derivative.getRoot().second);
            multiplicityVector[0] = 2;

            Segment segment(derivative.getRoot().first - 1, derivative.getRoot().first);
            segment.findInfinitySegment(cubicPolynomial, false);
            root1 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
            return;
        } else if (cubicPolynomial->findValueInPoint(derivative.getRoot().second) < -1 * baseFunc.getAccuracy()) { // 3
            rootCount = RootCount::THREE;
            Segment segment(derivative.getRoot().first - 1, derivative.getRoot().first);
            segment.findInfinitySegment(cubicPolynomial, false);
            root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);

            Segment segment1(derivative.getRoot().first, derivative.getRoot().second);
//            segment1.findInfinitySegment(cubicPolynomial, false);
            root1 = bisection.findRoot(cubicPolynomial, baseFunc, segment1);

            Segment segment2(derivative.getRoot().second, derivative.getRoot().second + 1);
            segment2.findInfinitySegment(cubicPolynomial, true);
            root2 = bisection.findRoot(cubicPolynomial, baseFunc, segment2);
            return;
        }
    } else if (cubicPolynomial->findValueInPoint(derivative.getRoot().first) < -1 * baseFunc.getAccuracy()) {
        if (cubicPolynomial->findValueInPoint(derivative.getRoot().second) < -1 * baseFunc.getAccuracy()) { // 5
            rootCount = RootCount::ONE;
            Segment segment(derivative.getRoot().second, derivative.getRoot().second + 1);
            segment.findInfinitySegment(cubicPolynomial, true);
            root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
            return;
        }
    } else if (std::abs(cubicPolynomial->findValueInPoint(derivative.getRoot().first)) < baseFunc.getAccuracy()) {
        if (cubicPolynomial->findValueInPoint(derivative.getRoot().second) < -1 * baseFunc.getAccuracy()) { // 2
            rootCount = RootCount::TWO;
            root0 = cubicPolynomial->findValueInPoint(derivative.getRoot().first);
            multiplicityVector[0] = 2;

            Segment segment1(derivative.getRoot().second, derivative.getRoot().second + 1);
            segment1.findInfinitySegment(cubicPolynomial, true);
            root1 = bisection.findRoot(cubicPolynomial, baseFunc, segment1);
            return;
        } else if (
                std::abs(cubicPolynomial->findValueInPoint(derivative.getRoot().second)) <
                baseFunc.getAccuracy()) { // 6
            rootCount = RootCount::ONE;
            root0 = (derivative.getRoot().first + derivative.getRoot().second) / 2;
            multiplicityVector[0] = 3;
            return;
        }
    }
//    if (std::abs(cubicPolynomial.findValueInPoint(derivative.getRoot().first)) < baseFunc.getAccuracy() &&
//        std::abs(cubicPolynomial.findValueInPoint(derivative.getRoot().second)) < baseFunc.getAccuracy()) { // 6
//        rootCount = RootCount::ONE;
//        root0 = (derivative.getRoot().first + derivative.getRoot().second) / 2;
//        multiplicityVector[0] = 3;
//        return;
//    }
}

void FindRootCubicPol::printAll() {
    if (rootCount == RootCount::ONE) {
        std::cout << "x1 = " << root0;
        if (multiplicityVector[0] > 1)
            std::cout << " multiplicity " << multiplicityVector[0];
        std::cout << std::endl;
    } else if (rootCount == RootCount::TWO) {
        std::cout << "x1 = " << root0;
        if (multiplicityVector[0] > 1)
            std::cout << " multiplicity " << multiplicityVector[0];
        std::cout << std::endl;

        std::cout << "x2 = " << root1;
        if (multiplicityVector[1] > 1)
            std::cout << " multiplicity " << multiplicityVector[1];
        std::cout << std::endl;
    } else if (rootCount == RootCount::THREE) {
        std::cout << "x1 = " << root0;
        if (multiplicityVector[0] > 1)
            std::cout << " multiplicity " << multiplicityVector[0];
        std::cout << std::endl;

        std::cout << "x2 = " << root1;
        if (multiplicityVector[1] > 1)
            std::cout << " multiplicity " << multiplicityVector[1];
        std::cout << std::endl;

        std::cout << "x3 = " << root2;
        if (multiplicityVector[2] > 1)
            std::cout << " multiplicity " << multiplicityVector[2];
        std::cout << std::endl;
    }
}

FindRootCubicPol::~FindRootCubicPol() {
    if (cubicPolynomial != nullptr)
        delete cubicPolynomial;
    return;
}




