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

void Segment::findInfinitySegment(Polynomial *polynomial, bool plusInfinity, int n) {
    if (plusInfinity) {
        if (polynomial->findValueInPoint(a) >= 0) {
            n = 1;
            while (polynomial->findValueInPoint(a + n * delta) > 0) {
                n++;
            }
            a = a + (n - 1) * delta;
            b = a + delta;
            return;
        } else {
            n = 1;
            while (polynomial->findValueInPoint(a + n * delta) < 0) {
                n++;
            }
            a = a + (n - 1) * delta;
            b = a + n * delta;
            return;
        }
    } else {
        if (polynomial->findValueInPoint(b) >= 0) {
            n = 1;
            while (polynomial->findValueInPoint(b - n * delta) > 0) {
                n++;
            }
            b = b - (n - 1) * delta;
            a = a - n * delta;
            return;
        } else {
            n = 1;
            while (polynomial->findValueInPoint(b - n * delta) < 0) {
                n++;
            }
            b = b - (n - 1) * delta;
            a = a - n * delta;
            return;
        }
    }
//
//    if (plusInfinity) {
//        if ((polynomial->findValueInPoint(a) <= 0 && polynomial->findValueInPoint(b) >= 0) ||
//            (polynomial->findValueInPoint(a) >= 0 && polynomial->findValueInPoint(b) <= 0))
//            return;
//        else {
//            a = a + n * delta;
//            b = b + n * delta;
//            n++;
//            findInfinitySegment(polynomial, plusInfinity, n);
//        }
//    } else {
//        if ((polynomial->findValueInPoint(a) >= 0 && polynomial->findValueInPoint(b) <= 0) ||
//            (polynomial->findValueInPoint(a) <= 0 && polynomial->findValueInPoint(b) >= 0))
//            return;
//        else {
//            a = a - n * delta;
//            b = b - n * delta;
//            n++;
//            findInfinitySegment(polynomial, plusInfinity, n);
//        }
//    }
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
