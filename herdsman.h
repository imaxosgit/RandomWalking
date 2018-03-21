#ifndef HERDSMAN
#define HERDSMAN
#include "creature.h"

class Herdsman : public Creature {

public:

   // Herdsman(Board *_board);

    Herdsman(Board *_board, Cell *currentCell);
    virtual bool isHerdsman() const { return true; }
};

#endif // HERDSMAN

