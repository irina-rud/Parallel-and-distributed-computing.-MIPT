//
// Created by riv on 01.01.17.
//

#pragma once
#include "IBacterium.h"
#include "names.h"
#include <iostream>

//. В каждой клетке может находиться питательная среда, а также два вида бактерий. Питательная среда изменяется по некоторому закону от времени и координат клетки в пространстве.

class Sell {
public:
    bool initialised_bacterium;
    bool initialised_properties;

    bool settled;
    IBacterium* bacterium;
    long* properties;
    long starvation_limits;

    Sell();
    void init_empty(IBacterium* empty);
    void set_not_init();
};


