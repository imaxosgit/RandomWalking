#include "herdsman.h"

/* Herdsman::Herdsman(Board *_board) : Creature(_board) {
    setName("herdsman");
    setDisplaySymbol('H');
} */

Herdsman::Herdsman(Board *_board, Cell *currentCell) : Creature(_board) {
    setCell(currentCell);
    setName("herdsman");
    setDisplaySymbol('H');

}
