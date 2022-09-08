//
// Created by kurya on 08.09.2022.
//

#ifndef LAB1_FINDROOTCUBICPOL_H
#define LAB1_FINDROOTCUBICPOL_H


#include <vector>
#include "CubicPolynomial.h"
#include "Bisection.h"

class FindRootCubicPol {
public:
    FindRootCubicPol(double accuracy, double a, double b, double c, double d);

    void findRoot();

private:
    double root0 = 0;
    double root1 = 0;
    double root2 = 0;
    std::vector<int> multiplicityVector;
    void findRootWithDerivativeZeroRoot();
    void findRootWithDerivativeOneRoot(SquarPolynomial derivative);
    void findRootWithDerivativeTwoRoot(SquarPolynomial derivative);
    RootCount rootCount = RootCount::ZERO;
    CubicPolynomial cubicPolynomial = CubicPolynomial(0, 0, 0, 0);
    Bisection bisection;
    Segment segment = Segment(0, 0);
    BaseFunc baseFunc = BaseFunc(0);
};


#endif //LAB1_FINDROOTCUBICPOL_H
