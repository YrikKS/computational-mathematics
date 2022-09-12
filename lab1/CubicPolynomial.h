//
// Created by kurya on 07.09.2022.
//

#ifndef LAB1_CUBICPOLYNOMIAL_H
#define LAB1_CUBICPOLYNOMIAL_H


#include "Polynomial.h"
#include "SquarPolynomial.h"

class CubicPolynomial : public Polynomial{
public:
    CubicPolynomial();

    CubicPolynomial(double a, double b, double c, double d, BaseFunc baseFunc);
//    void setAll(double a, double b, double c, double d, BaseFunc baseFunc);

    double findValueInPoint(double x) override;

    SquarPolynomial getDerivative();

    double getA() const;

    double getB() const;

    double getC() const;

    double getD() const;

    void setAll(double a, double b, double c, double d, BaseFunc baseFunc1);

private:
    double a;
    double b;
    double c;
    double d;
    BaseFunc baseFunc = BaseFunc(0.0001);
    SquarPolynomial derivative;

};


#endif //LAB1_CUBICPOLYNOMIAL_H
