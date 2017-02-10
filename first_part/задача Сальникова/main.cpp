#include <iostream>
#include <fstream>
#include <vector>
#include <omp.h>
#include "CGameBoard.h"
#include <stdlib.h>
#include <time.h>
#include <cstring>


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
            token = std::strtok((char *) s.data(), " ");
            while (token != NULL)
            {
                value = strtol(token,  NULL, 0);
                properties.push_back(value);
                token = std::strtok (NULL, " ");
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


void read_state(std::ifstream* state, CGameBoard* board ){
    std::string s;
    char* token;
    long value;

    board->prepareTorus();

    std::vector<long> properties;
    properties.reserve(8);
    while (std::getline( *state, s ))
    {
        std::string::size_type begin = s.find_first_not_of( " \f\t\v" );

        if (begin == std::string::npos) continue;
        else if (std::string( "#" ).find( s[ begin ] ) != std::string::npos) continue;
        else {
            token = strtok((char *) s.data(), " ");
            while (token != NULL)
            {
                value = strtol(token,  NULL, 0);
                properties.push_back(value);
                token = strtok (NULL, " ");
            }
            if (properties.size() != 8){
                continue;
            }else{
                board->configSell(properties);
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
    read_state(&state, board);
    //board->printTorus();
    if ((length %5 != 0) && (height %5 != 0)){
        std::cout<<"Это противозаконно. Я не готов к этому.";
        return 0;
    }


    long kernels = 2;

    std::cin>>kernels;
    std::cout <<"kernels amount is: " << kernels <<std::endl;

    srand(time(NULL));
    time_t start_time = time(NULL);

    long all_size = length * height / 25;
    long size = length * height / 25 / (kernels);
    long rest = length * height/25 - size*kernels;
    #pragma omp parallel num_threads(kernels)
    {
        size_t start_box;
        int name = omp_get_thread_num();
        if (name < rest) {
            start_box = (size_t) ((size + 1) * name);
        } else {
            start_box = (size_t) (size * name + rest);
        }
        for (int iter = 0; iter < 1000; ++iter){
//            std::cout<< " It's iteration "<< iter << " my name " << name <<std::endl;
            for (int small_len_index = 0; small_len_index <5; ++small_len_index){
                for (int small_hei_index = 0; small_hei_index <5; ++small_hei_index){
                    for (int i = 0; !(board->isCounted((start_box + i)%all_size, small_hei_index, small_len_index)); ++i) {
                        int random_increase = rand()%15;
//                        std::cout << "my name:" << name << " I'm going right "<< i <<std::endl;
                        board->set_not_init((start_box + i)%all_size, small_hei_index, small_len_index);
                        board->countCell_bacterium((start_box + i)%all_size, small_hei_index, small_len_index,random_increase);
                    }
                    for (int i = -1; !(board->isCounted((all_size + start_box + i)%all_size, small_hei_index, small_len_index)); --i) {
//                        std::cout << "my name:" << name << " I'm going left "<< i <<std::endl;
                        int random_increase = rand()%15;
                        board->set_not_init((all_size + start_box + i)%all_size, small_hei_index, small_len_index);
                        board->countCell_bacterium((all_size + start_box + i)%all_size, small_hei_index, small_len_index,random_increase);
                    }
//                    std::cout << "my name:" << name << " I've done " <<std::endl;
                    #pragma omp barrier

                }
            }
            #pragma omp singe
            {
                board->changeMode();
            }
        }
    }
    time_t end = time(NULL);
    std::cout << "Execution Time: " << (double)(end-start_time) << " Seconds" <<std::endl;
    return 0;
}