#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <omp.h>
#include "CGameBoard.h"
#include <stdlib.h>
#include <cstring>
#include "names.h"

void read_size(std::ifstream* state, unsigned long* len,unsigned long* hei ){
    std::string s, value1, value2;
    while (std::getline( *state, s ))
    {
        std::string::size_type begin = s.find_first_not_of( " \f\t\v" );

        if (begin == std::string::npos) continue;
        else if (std::string( "#" ).find( s[ begin ] ) != std::string::npos) continue;
        else {
            std::string::size_type end = s.find('x', begin);
            value1 = s.substr(begin, end - begin);
            value1.erase(value1.find_last_not_of(" \f\t\v") + 1);
            if (value1.empty()) continue;

            begin = s.find_first_not_of( " \f\n\r\t\v", end + 1 );
            end   = s.find_last_not_of(  " \f\n\r\t\v" ) + 1;

            value2 = s.substr( begin, end - begin );
            break;
        }
    }
    *len = strtoul(value1.data(),  NULL, 0);
    *hei = strtoul(value2.data(),  NULL, 0);
    return;
}

void read_config(std::ifstream * creatures,CGameBoard* board){
    std::string s;
    char* token;
    long value;

    std::vector<long> properties;
    properties.reserve(13);
    while (std::getline( *creatures, s ))
    {
        std::string::size_type begin = s.find_first_not_of( " \f\t\v" );

        if (begin == std::string::npos) continue;
        else if (std::string( "#" ).find( s[ begin ] ) != std::string::npos) continue;
        else {
            token = strtok((char *) s.data(), " ");
            while (token != NULL)
            {
                value = std::stol(token,  NULL, 0);
                properties.push_back(value);
                token = strtok (NULL, " ");
            }
            if (properties.size() != 13){
                std::cout<<"properties size: "<<properties.size()<<std::endl;
                throw new std::exception;
            }else{
                board->configBacterium(properties);
            }
            properties.clear();
        }
    }
}


int main(){
    std::ifstream state("/home/riv/concurrency/first_part/задача Сальникова/state.txt");
    std::ifstream creatures("/home/riv/concurrency/first_part/задача Сальникова/creatures.conf");

    unsigned long length, height;
    read_size(&state, &length, &height);

    CGameBoard* board = new CGameBoard(length,height);

    read_config(&creatures, board);


//    time_t start = time(NULL);
//    #pragma omp parallel num_threads(kernels)
//    {
//        size_t start;
//        int name = omp_get_thread_num();
//        if (name < rest) {
//            start = (size_t) ((size + 1) * name);
//        } else {
//            start = (size_t) (size * name + rest);
//        }
//        for (int j = 0; j < iterations; ++j) {
//            {
//                for (int i = 0; !(board_link->isCounted(start + i)); ++i) {
//                    board_link->countCell(start + i);
//                }
//                for (int i = -1; !(board_link->isCounted(start + i)); --i) {
//                    board_link->countCell(start + i);
//                }
//            }
//            #pragma omp barrier
//            if (name == 0) {
//                board_link->changeMode();
//            }
//            #pragma omp barrier
//        }
//    }
//    time_t end = time(NULL);
//    std::cout << "Execution Time: " << (double)(end-start) << " Seconds" <<std::endl;
    return 0;
}