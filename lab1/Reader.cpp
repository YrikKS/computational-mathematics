//
// Created by kurya on 12.09.2022.
//

#include <iostream>
#include "Reader.h"

void Reader::readParameters() {
    std::cout << "Input a" << std::endl;
    std::cin >> a;

    std::cout << "Input b" << std::endl;
    std::cin >> b;

    std::cout << "Input c" << std::endl;
    std::cin >> c;

    std::cout << "Input d" << std::endl;
    std::cin >> d;

    std::cout << "Input accuracy" << std::endl;
    std::cin >> accuracy;

//    std::cout << "Input delta";
//    std::cin >> delta;
}

double Reader::getA()  {
    return a;
}

double Reader::getB()  {
    return b;
}

double Reader::getC()  {
    return c;
}

double Reader::getD()  {
    return d;
}

double Reader::getAccuracy()  {
    return accuracy;
}

double Reader::getDelta()  {
    return delta;
}

Reader::Reader() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    accuracy = 0;
}

