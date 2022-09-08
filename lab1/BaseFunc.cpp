//
// Created by kurya on 07.09.2022.
//

#include <iostream>
#include "BaseFunc.h"

BaseFunc::BaseFunc(double accuracy) {
    BaseFunc::accuracy = accuracy;
}

double BaseFunc::getAccuracy() const {
    return accuracy;
}

void BaseFunc::setAccuracy(double accuracy) {
    BaseFunc::accuracy = accuracy;
}

bool BaseFunc::isHitWithAccuracy(double funcValue) {
    std::cout << "compair " << std::abs(funcValue) << " and " << accuracy << std::endl;
    if (std::abs(funcValue) <= accuracy)
        return true;
    else
        return false;
}
