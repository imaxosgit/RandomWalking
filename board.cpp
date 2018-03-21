#include "board.h"
#include "pair.h"
#include <iostream>
#include "sheep.h"
#include "herdsman.h"
#include "wolf.h"

using namespace std;

Board::Board() {
    for (int x = 0; x < WIDTH; x++)
        for (int y = 0; y < HEIGHT; y++)
            cells[x][y] = new Cell(x,y);

    for (int x = 0; x < WIDTH; x++)
        for (int y = 0; y < HEIGHT; y++ )
        {   if(x+1 < WIDTH) {
                Edge edge(cells[x][y], cells[x + 1][y]);
                edges.push_back(edge);
            }
            if(y+1 < HEIGHT) {
                //диагональ вниз влево
                if(y % 2 != 0) {                             // в нечетном ряду
                    if(x - 1 >= 0)
                        edges.push_back(Edge(cells[x][y], cells[x-1][y+1]));
                }
                else                        // в четном ряду
                    edges.push_back(Edge(cells[x][y], cells[x][y+1]));
                //диагональ вниз вправо
                if(y % 2 !=0)
                    edges.push_back(Edge(cells[x][y], cells[x][y+1]));
                else if(x+1 < WIDTH)
                    edges.push_back(Edge(cells[x][y], cells[x+1][y+1]));
            }
        }
    const int number = rand()%20 + 1;
    for (int i = 0; i < number; i++) {
        int random = rand()%3;
        Creature *creature;
        Cell *randomCell = cells[rand() % WIDTH][rand() % HEIGHT];
        switch (random) {
        case 0:
            creature = new Sheep(this, randomCell);
            break;

         case 1:
            creature = new Wolf(this, randomCell);
            break;
        case 2:
            creature = new Herdsman(this, randomCell);
            break;
        }
        creatures.push_back(creature);
    }

}

void Board::printBoard() const {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x< WIDTH; x++) {
            if(y % 2 == 0)
                cout << " ";

            Creature *found = findCreature(x,y);
            if(found)
                cout << found->getDisplaySymbol();
            else cout << "\"";

            if(y % 2 != 0)
                cout << " ";
        }
        cout << endl;
    }
    cout << "Current number of sheep: " << countSheep() << endl;
    for(int x = 0; x< WIDTH; x++) cout << "-";
    cout << endl;
}

Creature *Board::findCreature(int x, int y) const {
    for (unsigned int i = 0; i < creatures.size(); i++)
        if(creatures[i]->getCell()->getX() == x &&
           creatures[i]->getCell()->getY() == y)
            return creatures[i];
    return 0;
}

void Board::simpleStep() {
    for(vector<Creature *>::iterator it = creatures.begin(); it != creatures.end(); it++) {
        ++**it;
    }
}

void Board::operator ++() {
    simpleStep();
}

vector <Cell *> Board::getNeighbours(Cell *source) const {
    vector<Cell *> neighbours;
    for(vector<Edge>::const_iterator it = edges.begin(); it != edges.end(); it++) {
        if((*it).getFirst()==source)
            neighbours.push_back((*it).getSecond());
        else if((*it).getSecond()==source)
            neighbours.push_back((*it).getFirst());
    }
    return neighbours;
}

Cell *Board::chooseCell(Cell *source) const {
    vector<Cell *> neighbours = getNeighbours(source);
    if (neighbours.size() == 0) return source;
    int randomN = rand() % neighbours.size();
    return neighbours[randomN];
}

bool Board::containsHerdsman(Cell *currentCell) const {
    for(vector<Creature *>::const_iterator it = creatures.begin(); it != creatures.end(); it++)
        if((*it)->getCell() == currentCell && (*it)->isHerdsman())
            return true;
    return false;
}

void Board::eatAllSheep(Cell *cell) {
    if(containsHerdsman(cell)) return;
    for(vector<Creature *>::iterator it = creatures.begin(); it != creatures.end();)
        if((*it)->isSheep() && (*it)->getCell()==cell)
            it = creatures.erase(it);
        else
            it++;
}

int Board::countSheep() const {
    int count = 0;
    for(vector<Creature *>::const_iterator it = creatures.begin(); it != creatures.end(); it++)
        if((*it)->isSheep()) count++;
    return count;
}

Board::~Board() {
    for (int x = 0; x < WIDTH; x++)
        for (int y = 0; y < HEIGHT; y++)
            delete cells[x][y];
}
