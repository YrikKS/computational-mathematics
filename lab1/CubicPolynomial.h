//
// Created by kurya on 07.09.2022.
//

#ifndef LAB1_CUBICPOLYNOMIAL_H
#define LAB1_CUBICPOLYNOMIAL_H


#include "Polynomial.h"
#include "SquarPolynomial.h"

class CubicPolynomial : public Polynomial{
public:
    CubicPolynomial(double a, double b, double c, double d);

    double findValueInPoint(double x) override;

    SquarPolynomial getDerivative();

    double getA() const;

    double getB() const;

    double getC() const;

    double getD() const;

private:
    double a;
    double b;
    double c;
    double d;
    SquarPolynomial derivative = SquarPolynomial(0, 0, 0);
};


#endif //LAB1_CUBICPOLYNOMIAL_H
