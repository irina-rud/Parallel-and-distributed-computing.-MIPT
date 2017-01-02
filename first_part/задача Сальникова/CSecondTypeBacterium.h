//
// Created by riv on 01.01.17.
//

#pragma once
#include "IBacterium.h"
//Второй вид потребляет вещество 1 и производит вещество 2.

//Бактерии второго вида не могут голодать, однако при определённой концентрации вещества 1 могут почковаться двумя бактериями

class CSecondTypeBacterium : public IBacterium{
public:
    CSecondTypeBacterium();
};


