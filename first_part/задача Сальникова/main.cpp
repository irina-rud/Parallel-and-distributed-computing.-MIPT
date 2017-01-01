#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <omp.h>
#include "CGameBoard.h"



int main(){
    std::ifstream F("/home/riv/concurrency/first_part/задача Сальникова/input.txt");

    long kernels;
    long iterations;
    long higth;
    long length;

    F >> kernels >> iterations >> higth >> length;

    CGameBoard* board_link = & board;
    long all_size = length * higth;
    long size = length * higth / (kernels);
    long rest = length * higth - size*kernels;

    time_t start = time(NULL);
    #pragma omp parallel num_threads(kernels)
    {
        size_t start;
        int name = omp_get_thread_num();
        if (name < rest) {
            start = (size_t) ((size + 1) * name);
        } else {
            start = (size_t) (size * name + rest);
        }
        for (int j = 0; j < iterations; ++j) {
            {
                for (int i = 0; !(board_link->isCounted(start + i)); ++i) {
                    board_link->countCell(start + i);
                }
                for (int i = -1; !(board_link->isCounted(start + i)); --i) {
                    board_link->countCell(start + i);
                }
            }
            #pragma omp barrier
            if (name == 0) {
                board_link->changeMode();
            }
            #pragma omp barrier
        }
    }
    time_t end = time(NULL);
    std::cout << "Execution Time: " << (double)(end-start) << " Seconds" <<std::endl;
    return 0;
}