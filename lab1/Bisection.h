//
// Created by kurya on 07.09.2022.
//

#ifndef LAB1_BISECTION_H
#define LAB1_BISECTION_H


#include "SquarPolynomial.h"
#include "BaseFunc.h"
#include "Segment.h"

class Bisection {
public:
    double findRoot(Polynomial* polynomial, BaseFunc baseFunc, Segment segment);
};


#endif //LAB1_BISECTION_H
