//
// Created by kurya on 07.09.2022.
//

#ifndef LAB1_SQUARPOLYNOMIAL_H
#define LAB1_SQUARPOLYNOMIAL_H


#include <utility>
#include "Polynomial.h"
#include "BaseFunc.h"

enum RootCount {
    ZERO,
    ONE,
    TWO,
    THREE
};

class SquarPolynomial : public Polynomial {
public:
    SquarPolynomial(double a, double b, double c, BaseFunc baseFunc);

    SquarPolynomial();

    void findRoot();

    void findDiscriminant();

    double getA() const;

    double getB() const;

    double getC() const;

    double getDiscriminant() const;

    std::pair<double, double> getRoot();

    double findValueInPoint(double x) override;

    RootCount getRootCount() const;

    void setRootCount(RootCount rootCount);

    double findValueDerivate(double x);
private:
    RootCount rootCount;
    double a;
    double b;
    double c;
    double discriminant;
    BaseFunc baseFunc = BaseFunc(0);
    std::pair<double, double> root;
};


#endif //LAB1_SQUARPOLYNOMIAL_H
