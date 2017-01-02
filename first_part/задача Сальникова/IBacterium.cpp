//
// Created by riv on 02.01.17.
//

#include "IBacterium.h"
#include <iostream>
#include <exception>


IBacterium::IBacterium(){}
void IBacterium::print(){
    if (type == not_initialised){
        std::cout<< "Not initialised type of bacterium"<<std::endl;
        return;
    } else if (type == first_type_bacterium){
        std::cout<< "Hi! I'm first type bacterium"<<std::endl;
    }else if(type == second_type_bacterium){
        std::cout<< "Hi! I'm second type bacterium"<<std::endl;
    } else{
        throw new std::exception();
        return;
    }
    std::cout << "I can't live when there is lower then:"<<living_bound[breeding_ground]<<" of breeding ground, ";
    std::cout <<living_bound[first_substance]<<" of first substance, " << living_bound[second_substance] << " of second substance"<<std::endl;

    std::cout << "I can consumpt(produce):"<<consumption_secretion[breeding_ground]<<" of breeding ground, ";
    std::cout <<consumption_secretion[first_substance]<<" of first substance, " << consumption_secretion[second_substance] << " of second substance"<<std::endl;

    std::cout << "I can divide when it is: "<<cell_division[breeding_ground]<<" of breeding ground, ";
    std::cout <<cell_division[first_substance]<<" of first substance, " << cell_division[second_substance] << " of second substance"<<std::endl;

    if (type == first_type_bacterium){
        std::cout << "I can devide twice if it is bigger then :"<<extra_mode[breeding_ground]<<" of breeding ground, ";
        std::cout <<extra_mode[first_substance]<<" of first substance, " << extra_mode[second_substance] << " of second substance"<<std::endl;
    }else if(type == second_type_bacterium){
        std::cout << "I can load starvation mode if it is :"<<extra_mode[breeding_ground]<<" of breeding ground, ";
        std::cout <<extra_mode[first_substance]<<" of first substance, " << extra_mode[second_substance] << " of second substance"<<std::endl;
    }

}