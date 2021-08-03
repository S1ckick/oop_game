//
// Created by Максим on 27.11.2020.
//

#ifndef GAME_STAN_H
#define GAME_STAN_H


#include "../EnemyInterface.h"

class Stan {
public:
    void attack( EnemyInterface *enemy, Player &player);
    string getName();
};


#endif //GAME_STAN_H
