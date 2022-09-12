//
// Created by kurya on 12.09.2022.
//

#ifndef LAB1_READER_H
#define LAB1_READER_H


class Reader {
public:
    Reader();

    double getA() ;

    double getB() ;

    double getC() ;

    double getD() ;

    double getAccuracy() ;

    double getDelta() ;

    void readParameters();

private:
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;
    double accuracy = 0.0;
    double delta = 0.0;
};


#endif //LAB1_READER_H
