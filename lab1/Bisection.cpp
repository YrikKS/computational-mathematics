//
// Created by kurya on 07.09.2022.
//

#include <iostream>
#include "Bisection.h"

double Bisection::findRoot(Polynomial polynomial, BaseFunc baseFunc, Segment segment) {
    std::cout << polynomial.findValueInPoint(segment.getCenterOfSegment()) << std::endl << std::endl;
    std::cout << "centr segment " << segment.getCenterOfSegment() << std::endl;
    if (baseFunc.isHitWithAccuracy(polynomial.findValueInPoint(segment.getCenterOfSegment()))) {
        return segment.getCenterOfSegment();
    } else if (polynomial.findValueInPoint(segment.getCenterOfSegment()) > baseFunc.getAccuracy()) {
        segment.updateA(segment.getCenterOfSegment());
        return findRoot(polynomial, baseFunc, segment);
    } else if (polynomial.findValueInPoint(segment.getCenterOfSegment()) < (-1 * baseFunc.getAccuracy())) {
        segment.updateB(segment.getCenterOfSegment());
        return findRoot(polynomial, baseFunc, segment);
    }
    return 0;
}

// #TODO переделать else если не заробит!!!