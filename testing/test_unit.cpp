#include <cassert>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "../header.h"



int check_rows(char* board_array){
    int rows = 0;
    for(int i = 0; i < 9; i += 3){
        if(same_character (board_array[i], board_array[i+1], board_array[i+2]))
        rows = rows + 1 ;
    }
    return rows;
}

bool same_character(char a, char b, char c){
    if(a == b && b == c) return true;
    else return false;
}


void test_check_rows() {
    char board3[9] = {'X', 'X', 'X', 'O', 'O', 'O', 'A', 'A', 'A'};
    assert(check_rows(board3) == 3);

    char board2[9] = {'A', 'X', 'X', 'O', 'O', 'O', 'A', 'A', 'A'};
    assert(check_rows(board2) == 2);
}

int main() {
    test_check_rows();
    return 0;
}