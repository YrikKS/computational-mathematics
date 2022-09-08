//
// Created by kurya on 07.09.2022.
//

#include <iostream>
#include <cmath>
#include "SquarPolynomial.h"

void SquarPolynomial::findRoot() {
    findDiscriminant();
    if (getRootCount() == RootCount::ZERO)
        return;
    root.second = (b + discriminant) / (2 * a);
    root.first = (b - discriminant) / (2 * a);
}

double SquarPolynomial::getA() const {
    return a;
}

double SquarPolynomial::getB() const {
    return b;
}

double SquarPolynomial::getC() const {
    return c;
}

double SquarPolynomial::getDiscriminant() const {
    if (getRootCount() == RootCount::ZERO)
        return -1;
    else
        return discriminant;
}

std::pair<double, double> SquarPolynomial::getRoot() {
    return root;
}

SquarPolynomial::SquarPolynomial(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
    findRoot();
}

void SquarPolynomial::findDiscriminant() {
    double disc = b * b - 4 * a * c;
    if (disc < 0) {
        setRootCount(RootCount::ZERO);
        discriminant = -1;
        return;
    } else if (disc == 0) {
        setRootCount(RootCount::ONE);
    } else {
        setRootCount(RootCount::TWO);
    }
    discriminant = sqrt(b * b - 4 * a * c);
}

double SquarPolynomial::findValueInPoint(double x)  {
//    std::cout << a << " * x^2 + " << b << "x + " << c << std::endl;
//    std::cout << "x == " << x << std::endl;
    return a * x * x + b * x + c;
}

RootCount SquarPolynomial::getRootCount() const {
    return rootCount;
}

void SquarPolynomial::setRootCount(RootCount rootCount) {
    SquarPolynomial::rootCount = rootCount;
}


