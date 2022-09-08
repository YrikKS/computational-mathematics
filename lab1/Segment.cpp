//
// Created by kurya on 07.09.2022.
//

#include <iostream>
#include "Segment.h"

double Segment::getCenterOfSegment() {
    if ((a < 0 && b > 0) && std::abs(a) > b)
        return -1.0 * (std::abs(a) + b) / 2;
    else
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

Segment::Segment(double a, double b) : a(a), b(b) {}

void Segment::findInfinitySegment(Polynomial* polynomial, bool plusInfinity) {
    std::cout << polynomial->findValueInPoint(a) << " and " << polynomial->findValueInPoint(b) << std::endl;
    if (plusInfinity) {
        if ((polynomial->findValueInPoint(a) < 0 && polynomial->findValueInPoint(b) > 0) ||
            (polynomial->findValueInPoint(a) > 0 && polynomial->findValueInPoint(b) < 0))
            return;
        else {
            a = a + 1.0;
            b = b + 1.0;
            findInfinitySegment(polynomial, plusInfinity);
        }
    } else {
        if ((polynomial->findValueInPoint(a) > 0 && polynomial->findValueInPoint(b) < 0) ||
            (polynomial->findValueInPoint(a) < 0 && polynomial->findValueInPoint(b) > 0))
            return;
        else {
            a = a - 1.0;
            b = b - 1.0;
            findInfinitySegment(polynomial, plusInfinity);
        }
    }
}

void Segment::preparationVariables(bool plusInfinity) {
    if (plusInfinity) {
        a = 0;
        b = 1;
    } else {
        a = -1;
        b = 0;
    }

}
