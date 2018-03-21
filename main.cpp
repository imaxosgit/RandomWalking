#include <iostream>
#include "sheep.h"
#include "wolf.h"
#include "herdsman.h"
#include "board.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{   srand(time(0));
    Board *board = new Board();
    while(true) {
        board->printBoard();
        getchar();
        ++(*board);
    }
    return 0;
}

