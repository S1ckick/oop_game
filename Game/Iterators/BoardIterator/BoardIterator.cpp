#include "../../Iterators/BoardIterator/BoardIterator.h"


BoardIterator::BoardIterator(Cell** board, int width, int height){
    this->board = board;
    this->width = width;
    this->height = height;
    currentX = 0;
    currentY = 0;
}

Cell& BoardIterator::operator*() const {
    return board[currentX][currentY];
}

BoardIterator& BoardIterator::operator++() {
    currentX++;
    if(currentX == width){
        currentX = 0;
        currentY++;
    }
    return *this;
}

bool BoardIterator::operator==(const BoardIterator &other) const {
    return this->currentX == other.currentX && this->currentY == other.currentY;
}

bool BoardIterator::operator!=(const BoardIterator &other) const {
    return !(this->currentX == other.currentX && this->currentY == other.currentY);
}


BoardIterator::BoardIterator(const BoardIterator &it) {
    this->currentX = it.currentX;
    this->currentY = it.currentY;
    this->board = it.board;
}




















