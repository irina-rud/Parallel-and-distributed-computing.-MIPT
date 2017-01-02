//
// Created by riv on 01.01.17.
//


#include "Sell.h"


Sell::Sell(){ }


void Sell::init_empty(IBacterium* empty){
    initialised = true;
    properties[breeding_ground] = 0;
    properties[first_substance] = 0;
    properties[second_substance] = 0;
    bacterium = empty;
}


