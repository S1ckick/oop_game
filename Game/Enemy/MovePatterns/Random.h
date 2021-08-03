//
// Created by Максим on 27.11.2020.
//

#ifndef GAME_RANDOM_H
#define GAME_RANDOM_H

#include "../EnemyInterface.h"


class Random {
public:
    void move(EnemyInterface *enemy, const std::vector<Cell *> &neighbors);
    string getName();
};


#endif //GAME_RANDOM_H
