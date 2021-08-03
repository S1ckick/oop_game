
#ifndef GAME_ARRAYBOARD_H
#define GAME_ARRAYBOARD_H
#include "../../Iterators/BoardIterator/BoardIterator.h"
#include "../../Player/Player.h"
#include "../../Logs/AbstractLogs/AbstractLogs.h"
#include "../Cell/Elements/ElementInterface.h"
#include <list>
#include "../../../json.hpp"
using nlohmann::json;

class BoardIterator;

class ArrayBoard  {
public:
    static ArrayBoard& getInstance();
    ~ArrayBoard();

    //constructors
    ArrayBoard(const ArrayBoard& other);
    ArrayBoard& operator=(const ArrayBoard& other);
    ArrayBoard(ArrayBoard&& other);
    ArrayBoard& operator=(ArrayBoard&& other);

    //methods for iterator
    BoardIterator createIterator() const;
    BoardIterator end() const;
    BoardIterator begin() const;
    bool isRightMost(const BoardIterator &it) const;

    //board getters
    int getHeight() const;
    int getWidth() const;
    Cell& getItem(int x, int y) const;

    //Player getter
    Player& getPlayer();

    //exit point getters
    int getExitX() const;
    int getExitY() const;
    void setExitX(int x);
    void setExitY(int y);


    //logs
    void subscribe(AbstractLogs *subLog);
    void unsubscribe(AbstractLogs *subLog);
    void notify(Cell &cell, std::ostream &file);

    //game
    void clearData();
    void rebuildData();

    //cells
    void fillCells();
    Cell& emptyCell() const;
    bool isRoad(int x, int y);
    std::vector<Cell *> getNeighborRoads(int x, int y);

    void resetBoard(json jBoard, int width, int height);
    void setState(json data);
    json getState();

    void moveElement(int x, int y);



private:
    int height;
    int width;
    Cell **board;
    Player player;

    int exitX;
    int exitY;
    std::list<AbstractLogs *> subscribers;

    ArrayBoard(int width, int height);
    void generateBoard(int x, int y);

    void setExitPoint();
    void putElement(ElementInterface  *el);

    json state;
};




#endif //GAME_ARRAYBOARD_H
