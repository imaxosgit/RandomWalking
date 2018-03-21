#ifndef CREATURE
#define CREATURE
#include "cell.h"
#include <string>
class Board;
using namespace std;

class Creature {

private:
    string name;
    char displaySymbol;

protected:
    Board *board;
    Cell *cell;
public:
    Creature(Board *_board);

    Cell *getCell() const;

    void setCell(Cell *cell);

    string getName() const;

    char getDisplaySymbol() const;

    void setName(string cname);

    void setDisplaySymbol(char symbol);
    virtual Cell *chooseCell() const;
    virtual Cell *simpleStep();
    Cell *operator ++();
    virtual bool isSheep() const { return false; }
    virtual bool isHerdsman() const { return false; }
};



#endif // CREATURE

