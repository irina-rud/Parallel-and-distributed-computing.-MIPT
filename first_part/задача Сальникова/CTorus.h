//
// Created by riv on 10.09.16.
//

#pragma once
#include <iostream>
#include <vector>
#include "Sell.h"
#include "names.h"

class CTorus {
public:
    std::vector<Sell*> torus;
    unsigned long length;
    unsigned long height;

    std::vector<IBacterium*> configured;

public:
    CTorus(unsigned long len,unsigned long heig);

    void print();

    void countCell(long x, long y);
};


