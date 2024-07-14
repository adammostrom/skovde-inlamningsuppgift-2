#ifndef MYHEADER_H
#define MYHEADER_H


const int allowed_amounts [] = {100,300,500};
int balance = 0;
int bet = 0;


bool check_input(int bet);
int min_amount();
int take_deposit();
int take_bet();
char* randomize_board();
int calculate_board(char* board_array, int bet);
int check_rows(char* board_array);
int check_cols(char* board_array);
int check_diags(char* board_array);
bool same_character(char a, char b, char c);
void delete_board_array(char* board);
void print_balance();
void print_board(char* board);
void print_deposits();


#endif