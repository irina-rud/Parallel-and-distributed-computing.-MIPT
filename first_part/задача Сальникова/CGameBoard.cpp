//
// Created by riv on 10.09.16.
//

#include "CGameBoard.h"
#include "CSecondTypeBacterium.h"
#include "CFirstTypeBacterium.h"

CGameBoard::CGameBoard(long len, long heig){
    now = 0;
    if (heig < 0 || len < 0)
        throw new std::exception();
    else{
        threeToruses.push_back(CTorus(len,heig));
        threeToruses.push_back(CTorus(len,heig));
        threeToruses.push_back(CTorus(len,heig));
    }
    configuredCreatures.resize(3);
}


void CGameBoard::changeMode(){
    now = (now + next_board) %3;
}


void CGameBoard::countCell( long index) {
}

void CGameBoard::printTorus(){
    threeToruses[(now + prev_board) % 3].print();
}

CGameBoard::CGameBoard() {

}

void CGameBoard::configBacterium(std::vector<long> &properties) {
    if (properties.size() != 13) {
        throw new std::exception;
        return;
    }
    IBacterium* bact;
    if (properties[0] == first_type_bacterium){
        configuredCreatures[first_type_bacterium] = new CFirstTypeBacterium();
        bact = configuredCreatures[first_type_bacterium];
    }else if(properties[0] == second_type_bacterium){
        configuredCreatures[second_type_bacterium] = new CSecondTypeBacterium();
        bact = configuredCreatures[second_type_bacterium];
    } else{
        throw new std::exception;
        return;
    }

    bact->living_bound[breeding_ground] = properties[1];
    bact->living_bound[first_substance] = properties[2];
    bact->living_bound[second_substance] = properties[3];

    bact->consumption_secretion[breeding_ground] = properties[4];
    bact->consumption_secretion[first_substance] = properties[5];
    bact->consumption_secretion[second_substance] = properties[6];

    bact->cell_division[breeding_ground] = properties[7];
    bact->cell_division[first_substance] = properties[8];
    bact->cell_division[second_substance] = properties[9];

    bact->extra_mode[breeding_ground] = properties[10];
    bact->extra_mode[first_substance] = properties[11];
    bact->extra_mode[second_substance] = properties[12];


}















