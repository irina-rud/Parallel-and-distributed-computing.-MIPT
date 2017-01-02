//
// Created by riv on 01.01.17.
//

#pragma once
#include "names.h"
//Обоим видам необходима определённая концентрация питательных веществ для жизни.

//Бактерии могут потреблять ресурс из соседних с собой клеток, но потреблённый ресурс
// изымается из окружающих клеток пространства таким образом, чтобы концентрация уменьшилась равномерно по пространству на величину потреблённого ресурса.

//При определённой концентрации веществ бактерия делится, в результате случайно, на одной из соседних клеток появляется ещё
//бактерия того же вида (розыгрыш производится среди клеток, где ещё нет бактерии данного вида)




class IBacterium {
public:
    int type = not_initialised;

    long* living_bound = new long[3];
    long* consumption_secretion = new long[3];
    long* cell_division = new long[3];

    long* extra_mode = new long[3];
    bool turbo_division_mode;
    bool starvation_mode;

    IBacterium();
    void print();

};


