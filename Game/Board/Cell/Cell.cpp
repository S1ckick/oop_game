#include "Cell.h"
#include "Elements/Star/Star.h"
#include "Elements/Heal/Heal.h"
#include "Elements/Bomb/Bomb.h"

void Cell::setObject(CellTypes cellType){
    this->cellType = cellType;
    if(cellType == WALL){
        passability = false;
    }
    else{
        passability = true;
    }
}

CellTypes Cell::getObject(){
    return this->cellType;
}

void Cell::setPassability(bool passability){
    this->passability = passability;
}

bool Cell::isPassible(){
    return this->passability;
}

void Cell::setEl(ElementInterface *el) {
    this->el = el;
}

void Cell::setEltype(ElementTypes el) {
    switch (el) {
        case 1:
            this->el = new Bomb();
            return;
        case 2:
            this->el = new Heal();
            return;
        case 3:
            this->el = new Star();
            return;
        default:
            this->el = new None();
            return;
    }
}


ElementInterface* Cell::getEl() {
    return this->el;
}

void Cell::setX(int x) {
    this->x = x;
}

void Cell::setY(int y) {
    this->y = y;
}

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

std::ostream& operator<<(std::ostream &out, Cell &cell) {

    out << cell.getEl()->getName();
    return out;
}
