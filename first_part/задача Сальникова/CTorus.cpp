//
// Created by riv on 10.09.16.
//

#include "CTorus.h"



CTorus::CTorus(long len, long heig):length(len), height(heig){
    torus.resize((unsigned long) (length * height));
}


void CTorus::print(){
    std::cout << "Torus: " << std::endl;
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < length; ++j){
            if (!torus[i*length + j].initialised){
                std::cout << "? ";
            } else if (torus[i*length + j].bacterium->type == not_initialised){
                std::cout << "- ";
            } else if (torus[i*length + j].bacterium->type == first_type_bacterium){
                std::cout << "* ";
            } else if (torus[i*length + j].bacterium->type == second_type_bacterium){
                std::cout << "+ ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "end." << std::endl << std::endl;
}



void CTorus::countCell( long x, long y){
}



