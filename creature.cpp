#include "creature.h"
#include "board.h"

Creature::Creature(Board *_board) {
    cell = 0;
    board = _board;
}

Cell *Creature::getCell() const {
    return cell; //this
}

void Creature::setCell(Cell *currentCell) {
    cell = currentCell;
}

void Creature::setName(string cname) {
    name = cname;
}

void Creature::setDisplaySymbol(char symbol) {
    displaySymbol = symbol;
}


string Creature::getName() const {
    return name;
}

char Creature::getDisplaySymbol() const {
    return displaySymbol;
}

Cell *Creature::operator ++() {
    return simpleStep();
}

Cell *Creature::simpleStep() {
    setCell(chooseCell());
    return getCell();
}

Cell *Creature::chooseCell() const {
   return board->chooseCell(getCell());
}
