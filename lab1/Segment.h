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

    Segment(double a, double b, double delta);

    bool isDifferentSignInPoint();

    double getCenterOfSegment();

    void findInfinitySegment(Polynomial *polynomial, bool plusInfinity, int n);

    void preparationVariables(bool plusInfinity);

    void updateA(double a);

    void updateB(double b);

    double getA() const;

    double getB() const;

private:
    double a;
    double b;
    double delta;
};


#endif //LAB1_SEGMENT_H
