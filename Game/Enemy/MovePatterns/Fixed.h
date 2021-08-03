//
// Created by Максим on 27.11.2020.
//

#ifndef GAME_FIXED_H
#define GAME_FIXED_H

#include "../EnemyInterface.h"
#include <vector>

class Fixed {
public:
    void move(EnemyInterface *enemy, const std::vector<Cell *> &neighbors){
        //do nothing
    };
    string getName() { return "Fixed";}
};

#endif //GAME_FIXED_H
