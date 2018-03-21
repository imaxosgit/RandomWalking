#ifndef BOARD
#define BOARD
#include <vector>
#include "pair.h"
#include "cell.h"
#include "creature.h"

const int HEIGHT = 10;
const int WIDTH = 10;

using namespace std;
typedef Pair<Cell *> Edge;

class Board {
    Cell *cells[WIDTH][HEIGHT];
    vector<Edge> edges;
    vector<Creature *> creatures;
public:
    Board();
    void printBoard() const;
    Creature *findCreature(int x,int y) const;
    Cell *chooseCell(Cell *source) const;
    vector <Cell *> getNeighbours(Cell *source) const;
    void simpleStep();
    void operator ++();
    bool containsHerdsman(Cell *currentCell) const;
    void eatAllSheep(Cell *cell);
    int countSheep() const;
    ~Board();

};

#endif // BOARD

