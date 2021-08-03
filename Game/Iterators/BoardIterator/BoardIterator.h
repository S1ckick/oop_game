
#ifndef GAME_ARRAYBOARDITERATOR_H
#define GAME_ARRAYBOARDITERATOR_H


#include <iterator>
#include "../../Board/Cell/Cell.h"

class BoardIterator: public std::iterator<std::input_iterator_tag, Cell>{
    friend class ArrayBoard;
private:
    BoardIterator(Cell **board, int width, int height);
public:
    BoardIterator(const BoardIterator &it);

    bool operator==(const BoardIterator &other) const;
    bool operator!=(const BoardIterator &other) const;
    Cell& operator*() const;
    BoardIterator &operator++();


private:
    Cell** board;
    int currentX;
    int currentY;
    int height;
    int width;
};




#endif //GAME_ARRAYBOARDITERATOR_H
