//
// Created by riv on 10.09.16.
//

#include "CTorus.h"



CTorus::CTorus(unsigned long len, unsigned long heig):length(len), height(heig){
    torus.resize(length*height,  new Sell());
}


void CTorus::print(){
    std::cout << "Torus: " << std::endl;

    std::cout << "end." << std::endl << std::endl;
}



void CTorus::countCell( long x, long y){
}



