#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "header.h"
#include "printers.cpp"


int main () {

    bool replay = true;
    char input = 'n';

    while(replay){
        print_balance();

        balance = take_deposit();
        bet = take_bet();

        char* board_array = randomize_board();
        int wol = calculate_board(board_array, bet);

        balance = balance + wol;
        std::cout << "You won " << wol << std::endl;
        print_balance();

        std::cout << "Press any key to play again, press q to quit. \n";
        std::cin >> input;
        if(input == 'q') { replay = false; std::cout << "Exiting, thanks for playing";} 
        delete_board_array(board_array);
    }
    
    return 0;
}



/**
 * @brief Denna funktionen kollar om ett inkommande belopp är ett utav de godkända: 100, 300, 500. 
 * Returnerar true eller false.
 * 
 * @param bet Den inkommande insättningen.
 * @return true 
 * @return false 
 */
bool check_input(int bet){
    for(int amount : allowed_amounts){
        if (bet == amount) return true;
    }
    return false;
}


/**
 * @brief Hittar det minsta värdet i board_arrayen av legitima insatser, detta för att hålla programmet modulärt.
 * 
 * @return int 
 */
int min_amount(){
    int min = allowed_amounts[0];
    int size = sizeof(allowed_amounts) / sizeof(allowed_amounts[0]);
    for(int i = 1; i < size; i++){
        if (allowed_amounts[i] < min){
            min = allowed_amounts[i];
        }
    }
    return min;
}




/**
 * Funktion som tar emot en insattning. Insattningen maste
 * vara 100, 300 eller 500. Detta ser "check input" till.
 */
int take_deposit(){
    int deposit;
    bool valid_bet = false;

    std::cout << "How much money do you want to deposit?\n ";
    while(!valid_bet) 
    {
        std::cin >> deposit;
        if(!check_input(deposit))
        {
            print_deposits();
        }
        else {
            valid_bet = true;
        }
    }
    std::cout << "Money deposited: " << deposit << std::endl;
    return deposit;
}



/**
 * Tar ett bet. Enda kravet ar att bet inte kan overstiga insattningen.
 */
int take_bet(){

    bool bet_ok = false;

    while(!bet_ok){
        std::cout << "\n How much would you like to bet? \n";
        std::cin >> bet;

        if(bet <= balance){
            bet_ok = true;
        } 
    }

    balance = balance - bet;
    std::cout << "Money withdrawn from account: " << bet << std::endl;
    print_balance();

    return bet;
}

/**
 * Funktionen skapar en array av characters, i for loopen avgors vilken char
 * som placeras i arrayen utifran en slumpad siffra mellan 0 och 2, dar dessa
 * siffror har en ekvivales for en char. Arrayen ar av typen pointer
 * for att kunna passera den till andra funktioner.
 */
char* randomize_board(){
    srand(time(0));
    char* board_array = new char [9];
    int length = sizeof( board_array) / sizeof( board_array[0]);
    for(int i = 0; i < length + 1; i++){
        int digit = rand() % 3;
        switch(digit){
                case 0:   board_array[i] = 'A'; break;
                case 1:   board_array[i] = 'O'; break;
                case 2:   board_array[i] = 'X'; break;
            }
    }
    return board_array;
}


/**
 * Denna funktionen ar central for att avgora hur manga rader, kolumner och 
 * diagonaler som innehaller samma character. wins variabeln ar additionen
 * av de olika helper functions, och utifran givna regler beraknas vinstsumman
 * i ett switch case. Notera att fler an 6 rader ger 10 ganger insattningen.
 */
int calculate_board(char* board_array, int bet){

    print_board(board_array);

    int wins = check_rows(board_array) + check_cols(board_array) + check_diags(board_array);
    if(wins >= 6){
        bet = bet * 10;
        return bet;
    } 
    switch(wins){
        case 0: bet = bet * 0; break;
        case 1: bet = bet * 2; break;
        case 2: bet = bet * 3; break;
        case 3: bet = bet * 4; break;
        case 4: bet = bet * 5; break;
        case 5: bet = bet * 7; break;
    } 
    return bet;
}


/**
 * Hjalpfunktion som raknar hur manga chars per rad som ar samma. 
 * Da spelplanen ar ett 3x3 grid hoppar iterationen 3 steg for varje ny radkoll.
 */
int check_rows(char* board_array){
    int rows = 0;
    for(int i = 0; i < 9; i += 3){
        if(same_character (board_array[i], board_array[i+1], board_array[i+2]))
        rows = rows + 1 ;
    }
    return rows;
}

/**
 * Kollar lika chars for alla kolumner. Iterationen behover bara hoppa 3 steg.
 * Varje "koll" skippar 3 characters i arrayen for att landa pa nasta element i kolumnen.
 */
int check_cols(char* board_array){
    int cols = 0;
    for(int i = 0; i < 3; i += 1){
        if(same_character(board_array[i], board_array[i+3], board_array[i+6]))
        cols = cols + 1;
    }
    return cols;
}

/**
 * Kollar diagonalerna. Hardkodat.
 */
int check_diags(char* board_array){
    int diags = 0;
    if(same_character(board_array[0], board_array[4], board_array[8])) diags = diags + 1;
    if(same_character(board_array[2], board_array[4], board_array[6])) diags = diags + 1;
    return diags;
}

/**
 * Hjalpfunktion som kollar om 3 chars ar lika.
 */
bool same_character(char a, char b, char c){
    if(a == b && b == c) return true;
    else return false;
}


// För att städa rent dynamiskt minne som upptagits av deklarerad char board_array.
void delete_board_array(char* board){
    delete [] board;
}






