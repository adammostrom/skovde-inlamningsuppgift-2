#include "header.h"

void print_board(char* board){
    for (int i = 0; i < 9; i += 3) {
        std::cout << board[i] << ' ' << board[i + 1] << ' ' << board[i + 2] << std::endl;
        std::cout << "\n" << std::endl;
    }
}


void print_deposits(){
    std::cout << "Possible amounts to deposit: \n 100 \n 300 \n 500\n";
}
void print_balance(){
    std::cout << "Balance: " << balance << " \n";
}