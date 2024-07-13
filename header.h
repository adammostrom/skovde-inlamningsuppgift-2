#ifndef MYHEADER_H
#define MYHEADER_H


const int allowed_amounts [] = {100,300,500};
int balance = 0;


bool check_input(int bet);
int min_amount();
int take_deposit();
void print_deposits();
void print_balance();
void print_board(char** board);
int randomize(int seed);
void test_board();
void delete_array(char** board);
int take_bet();

bool same_character(char a, char b, char c);
int calculate_board_alternative(char* board_array,int bet);
void delete_board_array(char** board);

char* randomize_board();
void print_board(char* board);
int check_rows(char* board_array);
void delete_board_array(char* board);
int randomize();

int check_cols(char* board_array);
int check_diags(char* board_array);

#endif