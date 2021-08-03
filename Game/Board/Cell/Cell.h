#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "Elements/ElementInterface.h"
#include "Elements/None/None.h"
#include "../../Enum/ElementTypes.h"

class Cell {
public:
    void setObject(CellTypes cellType);
    CellTypes getObject();

    void setPassability(bool passability);
    bool isPassible();

    void setEl(ElementInterface *el);
    ElementInterface *getEl();

    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

    void setEltype(ElementTypes el);

    friend std::ostream &operator<<(std::ostream &out, Cell &cell);

private:
    CellTypes cellType = WALL;
    bool passability= false;
    ElementInterface *el = new None();
    int x=-1;
    int y=-1;

};

#endif // CELL_H
