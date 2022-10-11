//
// Created by kurya on 08.09.2022.
//

#include <iostream>
#include "FindRootCubicPol.h"

FindRootCubicPol::FindRootCubicPol(double accuracy, double a, double b, double c, double d) {
    FindRootCubicPol::baseFunc = BaseFunc(accuracy);
    FindRootCubicPol::cubicPolynomial = new CubicPolynomial(a, b, c, d, baseFunc);
//    cubicPolynomial->setAll(a, b, c, d, baseFunc);
    multiplicityVector.resize(3);
    multiplicityVector[0] = 1;
    multiplicityVector[1] = 1;
    multiplicityVector[2] = 1;
}

void FindRootCubicPol::findRoot() {
    SquarPolynomial derivative = cubicPolynomial->getDerivative();
    if (derivative.getRootCount() == RootCount::ZERO || derivative.getRootCount() == RootCount::ONE) {
        if (baseFunc.isHitWithAccuracy(cubicPolynomial->findValueInPoint(0))) {
            rootCount = RootCount::ONE;
//            multiplicityVector[0] = 3;
            root0 = 0;
        } else if (cubicPolynomial->findValueInPoint(0) < (-1 * baseFunc.getAccuracy())) {
            rootCount = RootCount::ONE;
            multiplicityVector[0] = 3;
            Segment segment(0, 7);
            segment.findInfinitySegment(cubicPolynomial, true, 0);
            root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
        } else if (cubicPolynomial->findValueInPoint(0) > baseFunc.getAccuracy()) {
            multiplicityVector[0] = 3;
            rootCount = RootCount::ONE;
            Segment segment(-7, 0);
            segment.findInfinitySegment(cubicPolynomial, false, 0);
            root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
        }
//        findRootWithDerivativeZeroRoot();
//    } else if (derivative.getRootCount() == RootCount::ONE) {
//        std::cout << "Root " << derivative.getRoot().first << std::endl;
//        findRootWithDerivativeOneRoot(derivative);
    } else if (derivative.getRootCount() == RootCount::TWO) {
//        std::cout << "Root " << derivative.getRoot().first << " second " << derivative.getRoot().second << std::endl;
        findRootWithDerivativeTwoRoot(derivative);
    }
}

void FindRootCubicPol::findRootWithDerivativeZeroRoot() {
    rootCount = RootCount::ONE;
    if (cubicPolynomial->findValueInPoint(0) > 0) {
        Segment segment(0, 7);
        segment.findInfinitySegment(cubicPolynomial, true, 0);
        root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
    } else {
        Segment segment(-7, 0);
        segment.findInfinitySegment(cubicPolynomial, false, 0);
        root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
    }
}

void FindRootCubicPol::findRootWithDerivativeOneRoot(SquarPolynomial derivative) {
    rootCount = RootCount::TWO;
    double rootDerivative = derivative.getRoot().first;
    Segment segment1(rootDerivative, rootDerivative + 7);
    segment1.findInfinitySegment(cubicPolynomial, true, 0);
    root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment1);

    Segment segment2(rootDerivative - 7, rootDerivative);
    segment2.findInfinitySegment(cubicPolynomial, false, 0);
    root1 = bisection.findRoot(cubicPolynomial, baseFunc, segment2);
}

void FindRootCubicPol::findRootWithDerivativeTwoRoot(SquarPolynomial derivative) {
    std::cout << cubicPolynomial->findValueInPoint(derivative.getRoot().first) << std::endl;
    std::cout << cubicPolynomial->findValueInPoint(derivative.getRoot().second) << std::endl;
    if (cubicPolynomial->findValueInPoint(derivative.getRoot().first) > baseFunc.getAccuracy()) {
        if (cubicPolynomial->findValueInPoint(derivative.getRoot().second) > baseFunc.getAccuracy()) { // 4
            rootCount = RootCount::ONE;
            Segment segment(derivative.getRoot().first - 7, derivative.getRoot().first);
            segment.findInfinitySegment(cubicPolynomial, false, 0);
            root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
            return;
        } else if (std::abs(cubicPolynomial->findValueInPoint(derivative.getRoot().second)) <
                   baseFunc.getAccuracy()) { // 1
            rootCount = RootCount::TWO;
            root0 = derivative.getRoot().second;
            multiplicityVector[0] = 2;

            Segment segment(derivative.getRoot().first - 7, derivative.getRoot().first);
            segment.findInfinitySegment(cubicPolynomial, false, 0);
            root1 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
            return;
        } else if (cubicPolynomial->findValueInPoint(derivative.getRoot().second) < -1 * baseFunc.getAccuracy()) { // 3
            rootCount = RootCount::THREE;
            Segment segment(derivative.getRoot().first - 7, derivative.getRoot().first);
            segment.findInfinitySegment(cubicPolynomial, false, 0);
            std::cout << segment.getA() << " --- " << segment.getB() << std::endl;
            root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);

            Segment segment1(derivative.getRoot().first, derivative.getRoot().second);
//            segment1.findInfinitySegment(cubicPolynomial, false);
            root1 = bisection.findRoot(cubicPolynomial, baseFunc, segment1);

            Segment segment2(derivative.getRoot().second, derivative.getRoot().second + 7);
            segment2.findInfinitySegment(cubicPolynomial, true, 0);
            root2 = bisection.findRoot(cubicPolynomial, baseFunc, segment2);
            return;
        }
    } else if (cubicPolynomial->findValueInPoint(derivative.getRoot().first) < (-1 * baseFunc.getAccuracy())) {
        if (cubicPolynomial->findValueInPoint(derivative.getRoot().second) < (-1 * baseFunc.getAccuracy())) { // 5
            rootCount = RootCount::ONE;
            Segment segment(derivative.getRoot().second, derivative.getRoot().second + 7);
            segment.findInfinitySegment(cubicPolynomial, true, 0);
            root0 = bisection.findRoot(cubicPolynomial, baseFunc, segment);
            return;
        }
    } else if (std::abs(cubicPolynomial->findValueInPoint(derivative.getRoot().first)) < baseFunc.getAccuracy()) {
        if (cubicPolynomial->findValueInPoint(derivative.getRoot().second) < (-1 * baseFunc.getAccuracy())) { // 2
            rootCount = RootCount::TWO;
            root0 = derivative.getRoot().first;
            multiplicityVector[0] = 2;

            Segment segment1(derivative.getRoot().second, derivative.getRoot().second + 7);
            segment1.findInfinitySegment(cubicPolynomial, true, 0);
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
    std::cout << "result " << std::endl;
    if (rootCount == RootCount::ONE) {
        std::cout << "x1 = " << root0;
//        if (multiplicityVector[0] > 1)
        calculateMultiplicityVector(0);
        std::cout << " multiplicity " << multiplicityVector[0];
        std::cout << std::endl;
    } else if (rootCount == RootCount::TWO) {
        std::cout << "x1 = " << root0;
//        if (multiplicityVector[0] > 1)
        calculateMultiplicityVector(0);
        std::cout << " multiplicity " << multiplicityVector[0];
        std::cout << std::endl;

        std::cout << "x2 = " << root1;
//        if (multiplicityVector[1] > 1)
        calculateMultiplicityVector(1);
        std::cout << " multiplicity " << multiplicityVector[1];
        std::cout << std::endl;
    } else if (rootCount == RootCount::THREE) {
        multiplicityVector[0] = 1;
        multiplicityVector[1] = 1;
        multiplicityVector[2] = 1;
        std::cout << "x1 = " << root0;
//        if (multiplicityVector[0] > 1)
//        calculateMultiplicityVector(0);
        std::cout << " multiplicity " << multiplicityVector[0];
        std::cout << std::endl;

        std::cout << "x2 = " << root1;
//        if (multiplicityVector[1] > 1)
//        calculateMultiplicityVector(1);
        std::cout << " multiplicity " << multiplicityVector[1];
        std::cout << std::endl;

        std::cout << "x3 = " << root2;
//        if (multiplicityVector[2] > 1)
//        calculateMultiplicityVector(2);
        std::cout << " multiplicity " << multiplicityVector[2];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

FindRootCubicPol::~FindRootCubicPol() {
    if (cubicPolynomial != nullptr)
        delete cubicPolynomial;
    return;
}

double FindRootCubicPol::getRoot0() const {
    return root0;
}

double FindRootCubicPol::getRoot1() const {
    return root1;
}

double FindRootCubicPol::getRoot2() const {
    return root2;
}

void FindRootCubicPol::setAll(double accuracy, double a, double b, double c, double d) {
    FindRootCubicPol::baseFunc = BaseFunc(accuracy);
    if (cubicPolynomial != nullptr)
        delete cubicPolynomial;
    FindRootCubicPol::cubicPolynomial = new CubicPolynomial(a, b, c, d, baseFunc);
//    cubicPolynomial->setAll(a, b, c, d, baseFunc);
    multiplicityVector.resize(3);
    multiplicityVector[0] = 1;
    multiplicityVector[1] = 1;
    multiplicityVector[2] = 1;
}

void FindRootCubicPol::calculateMultiplicityVector(int numbRoot) {
    double root = 0.0;
    if (numbRoot == 0) {
        root = root0;
    } else if (numbRoot == 1) {
        root = root1;
    } else if (numbRoot == 2) {
        root = root2;
    }
//    if (rootCount == RootCount::ONE) {
    if ((std::abs(cubicPolynomial->getDerivative().findValueInPoint(root)) < 0.5)) {
        if ((std::abs((cubicPolynomial->getDerivative().findValueDerivate(root))) < 0.5 )) {
            multiplicityVector[numbRoot] = 3;
        } else {
            multiplicityVector[numbRoot] = 2;
        }
    } else
        multiplicityVector[numbRoot] = 1;
//    }
}




