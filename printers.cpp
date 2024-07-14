#include "header.h"
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>

void print_board(char* board) {
    for (int i = 0; i < 10; i += 3) {
        std::cout << board[i] << ' ' << board[i + 1] << ' ' << board[i + 2] << std::endl;
    }
    std::cout << std::endl;
}


void print_deposits(){
    std::cout << "Possible amounts to deposit: \n 100 \n 300 \n 500\n";
}
void print_balance(){
    std::cout << "Balance: " << balance << " \n";
}