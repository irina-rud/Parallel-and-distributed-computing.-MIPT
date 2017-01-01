//
// Created by riv on 10.09.16.
//

#pragma once
#include <iostream>
#include <vector>
#include "Sell.h"

class CTorus {
private:
    std::vector<Sell> torus;
    long length;
    long height;
public:
    CTorus(long len, long heig);

    long getHeight();

    long getLength();

    int isLiving(long x, long y);

    int numOfNeighbours(long x, long y);

    void action(int act, int wasHere, long x, long y);

    int countCell( long x, long y);

    void print();

    void set_nothing(long x, long y);

    void set(std::vector<int>& input);

    int getCell(long x, long y);
};


