

int randomize(int seed){
    srand(time(0) + seed);
    return rand() % 3;
}