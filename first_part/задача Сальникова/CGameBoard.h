//
// Created by riv on 10.09.16.
//

#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <atomic>
#include <mutex>
#include "CTorus.h"
#include "names.h"



class CGameBoard {
public:
    CGameBoard();

    std::vector<CTorus> threeToruses;
    std::vector<IBacterium*> configuredCreatures;
    int now;

public:
    CGameBoard(long len, long heig);

    void configBacterium(std::vector<long>& properties);

    void changeMode();

    void countCell(long index);

    void printTorus();
};

