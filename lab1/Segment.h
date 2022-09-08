//
// Created by kurya on 07.09.2022.
//

#ifndef LAB1_SEGMENT_H
#define LAB1_SEGMENT_H

#include <cmath>
#include "Polynomial.h"

class Segment {
public:
    Segment(double a, double b);

    bool isDifferentSignInPoint();

    double getCenterOfSegment();

    void findInfinitySegment(Polynomial* polynomial, bool plusInfinity);

    void preparationVariables(bool plusInfinity);

    void updateA(double a);

    void updateB(double b);

private:
    double a;
    double b;
};


#endif //LAB1_SEGMENT_H
