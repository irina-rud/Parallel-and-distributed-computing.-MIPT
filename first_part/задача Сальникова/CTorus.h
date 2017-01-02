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
    std::vector<Sell> torus;
    long length;
    long height;

    void* configured;

public:
    CTorus(long len,long heig);

    void print();

    void countCell(long x, long y);
};


