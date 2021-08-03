//
// Created by Максим on 27.11.2020.
//

#ifndef GAME_ENEMYINTERFACE_H
#define GAME_ENEMYINTERFACE_H

#include "../Board/Cell/Cell.h"
#include <string>
class Player;

class EnemyInterface {
public:
    EnemyInterface(int x, int y) : x(x), y(y) {}
    virtual void move(const vector<Cell *> &neighbors) = 0;
    virtual void attack(Player &player) = 0;
    virtual string getAttack() = 0;
    virtual string getMove() = 0;

    void setX(int x) {this->x = x;}
    void setY(int y) {this->y = y;}
    int getX() {return this->x;}
    int getY() {return this->y;}

private:
    int x;
    int y;
};




#endif //GAME_ENEMYINTERFACE_H
