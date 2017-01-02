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
    bool initialised = false;

    bool settled = false;
    IBacterium* bacterium;
    long* properties = new long[3];
    long starvation_limits = inf_lives;

    Sell();
    void init_empty(IBacterium* empty);

};


