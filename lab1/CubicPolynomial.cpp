//
// Created by kurya on 07.09.2022.
//

#include "CubicPolynomial.h"

CubicPolynomial::CubicPolynomial(double a, double b, double c, double d) {
    CubicPolynomial::a = a;
    CubicPolynomial::b = b;
    CubicPolynomial::c = c;
    CubicPolynomial::d = d;
    CubicPolynomial::derivative = SquarPolynomial(3*a, 2*b, c);
}

double CubicPolynomial::getA() const {
    return a;
}

double CubicPolynomial::getB() const {
    return b;
}

double CubicPolynomial::getC() const {
    return c;
}

double CubicPolynomial::getD() const {
    return d;
}

double CubicPolynomial::findValueInPoint(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

SquarPolynomial CubicPolynomial::getDerivative() {
    return derivative;
}
