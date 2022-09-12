//
// Created by kurya on 07.09.2022.
//

#include <iostream>
#include "Segment.h"
#include "Const.h"

using namespace Constants;

double Segment::getCenterOfSegment() {
//    if ((a < 0 && b > 0) && std::abs(a) > b)
//        return -1.0 * (std::abs(a) + b) / 2;
//    else
    return (a + b) / 2;
}

bool Segment::isDifferentSignInPoint() {
    if ((a < 0 && b > 0) || a > 0 && b < 0)
        return true;
    else
        return false;
}

void Segment::updateA(double a) {
    Segment::a = a;
}

void Segment::updateB(double b) {
    Segment::b = b;
}

Segment::Segment(double a, double b) : a(a), b(b) {
    delta = Constants::delta;
}

void Segment::findInfinitySegment(Polynomial *polynomial, bool plusInfinity) {
    if (plusInfinity) {
        if ((polynomial->findValueInPoint(a) <= 0 && polynomial->findValueInPoint(b) >= 0) ||
            (polynomial->findValueInPoint(a) >= 0 && polynomial->findValueInPoint(b) <= 0))
            return;
        else {
            a = a + delta;
            b = b + delta;
            findInfinitySegment(polynomial, plusInfinity);
        }
    } else {
        if ((polynomial->findValueInPoint(a) >= 0 && polynomial->findValueInPoint(b) <= 0) ||
            (polynomial->findValueInPoint(a) <= 0 && polynomial->findValueInPoint(b) >= 0))
            return;
        else {
            a = a - delta;
            b = b - delta;
            findInfinitySegment(polynomial, plusInfinity);
        }
    }
}

void Segment::preparationVariables(bool plusInfinity) {
    if (plusInfinity) {
        a = 0.0;
        b = 1.0;
    } else {
        a = -1.0;
        b = 0.0;
    }

}

double Segment::getA() const {
    return a;
}

double Segment::getB() const {
    return b;
}

Segment::Segment(double a, double b, double del) : a(a), b(b), delta(Constants::delta) {}
