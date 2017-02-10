//
// Created by riv on 01.01.17.
//


#include "Sell.h"


Sell::Sell(){
    initialised_bacterium = false;
    initialised_properties = false;

    settled = false;
    bacterium;
    properties = new long[3];
    starvation_limits = inf_lives;

    properties[breeding_ground] = 0;
    properties[first_substance] = 0;
    properties[second_substance] = 0;
    bacterium = NULL;
}


void Sell::init_empty(IBacterium* empty){
    initialised_bacterium = true;
    initialised_properties = true;
    properties[breeding_ground] = 0;
    properties[first_substance] = 0;
    properties[second_substance] = 0;
    bacterium = empty;
}

void Sell::set_not_init(){
    initialised_bacterium = false;
    initialised_properties = false;
    properties[breeding_ground] = 0;
    properties[first_substance] = 0;
    properties[second_substance] = 0;
    bacterium = NULL;

}

