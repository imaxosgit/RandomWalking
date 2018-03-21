#ifndef CELL
#define CELL

class Cell {
    int x, y;

public:

    Cell(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int getX() const { return x; }
    int getY() const { return y; }




};

#endif // CELL

