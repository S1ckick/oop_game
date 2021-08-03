//
// Created by Максим on 27.11.2020.
//

#ifndef GAME_HIT_H
#define GAME_HIT_H

#include "../EnemyInterface.h"

class Hit {
public:
    void attack( EnemyInterface *enemy, Player &player);
    string getName();
};


#endif //GAME_HIT_H
