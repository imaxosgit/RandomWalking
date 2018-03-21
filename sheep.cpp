#include "sheep.h"

/* Sheep::Sheep(Board *_board) : Creature(_board) {
    setName("sheep");
    setDisplaySymbol('S');
} */

Sheep::Sheep(Board *_board, Cell *currentCell) : Creature(_board) {
    setCell(currentCell);
    setName("sheep");
    setDisplaySymbol('S');
}


