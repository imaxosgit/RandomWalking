#ifndef WOLF
#define WOLF
#include "creature.h"

class Wolf : public Creature  {

public:

    Wolf(Board *_board);

    Wolf(Board *_board, Cell *currentCell);
    virtual Cell *chooseCell() const;
    virtual Cell *simpleStep();
};

#endif // WOLF

