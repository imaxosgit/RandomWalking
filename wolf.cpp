#include "wolf.h"
#include "board.h"
#include "creature.h"
#include <stdlib.h>

Wolf::Wolf(Board *_board, Cell *currentCell) : Creature(_board) {
    setCell(currentCell);
    setName("wolf");
    setDisplaySymbol('W');
}

Cell *Wolf::chooseCell() const {
    vector<Cell *> neighbours = board->getNeighbours(cell);
    for(vector<Cell *>::iterator it = neighbours.begin(); it != neighbours.end();)
        if(board->containsHerdsman(*it))
            it = neighbours.erase(it);
        else
            it++;
    if(neighbours.size() != 0) {
        int randomN = rand() % neighbours.size();
        return neighbours[randomN];
    }
    else return cell;
}

Cell *Wolf::simpleStep() {
    Creature::simpleStep();
    board->eatAllSheep(cell);
    return cell;
}
