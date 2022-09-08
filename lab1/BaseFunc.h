//
// Created by kurya on 07.09.2022.
//

#ifndef LAB1_BASEFUNC_H
#define LAB1_BASEFUNC_H

#include <cmath>

class BaseFunc {
public:
    BaseFunc(double accuracy);

    double getAccuracy() const;

    void setAccuracy(double accuracy);

    bool isHitWithAccuracy(double funcValue);

private:
    double accuracy;
};


#endif //LAB1_BASEFUNC_H
