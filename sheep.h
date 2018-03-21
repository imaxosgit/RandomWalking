#ifndef SHEEP
#define SHEEP
#include "creature.h"

class Sheep : public Creature {


public:

  //  Sheep(Board *_board);

    Sheep(Board *_board, Cell *currentCell);
    virtual bool isSheep() const { return true;}

  //  virtual Cell *getCell() const;

  //  virtual void setCell(Cell *cell);

  //  virtual Cell *chooseCell() const;

  //  virtual void simpleStep();

 //   virtual string getName() const;

  //  virtual char getDisplaySymbol() const;
};


#endif // SHEEP

