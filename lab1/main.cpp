#include <iostream>
#include "BaseFunc.h"
#include "Bisection.h"
#include "CubicPolynomial.h"
#include "FindRootCubicPol.h"

int main() {
    FindRootCubicPol finder(0.0001, 1, 0, -1, 0);
    finder.findRoot();
    finder.printAll();
//    Bisection bisection;
//    CubicPolynomial cubicPolynomial(1, 2, 3, 4);
//    Segment segment(-8, 1);
//    SquarPolynomial squarPolynomial(1, 4, -9);
//    BaseFunc baseFunc(0.000000001);
//    double rez = bisection.findRoot(squarPolynomial, baseFunc, segment);
//    std::cout << " rez = " << rez << std::endl;
//    std::cout << squarPolynomial.findValueInPoint(rez) << std::endl;
//    std::cout << "real rez == " << squarPolynomial.getRoot().first << " and " << squarPolynomial.getRoot().second
//              << std::endl;
    return 0;
}
