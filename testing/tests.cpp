#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "header.h"



int randomize(int seed){
    srand(time(0) + seed);
    return rand() % 3;
}


/**
 * @brief Property test
 * 
 */

bool assess_randomize_function(int high, int tests){

    for(int i = 0; i < tests + 1; i++){
        srand(time(0) + i);
        int rand = randomize(i);
        std::cout << rand << std::endl;
        if(rand > high){
            std::cout << "Failed after " << i << " tests\n";
            return false;
        }
    }
    std::cout << "All tests passed\n";
    return true;

}

int main(){
    assess_randomize_function(3, 1000);
}
