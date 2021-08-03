//
// Created by Максим on 03.10.2020.
//

#ifndef GAME_BOMBELEMENTBEHAVIOR_H
#define GAME_BOMBELEMENTBEHAVIOR_H
#include "../ElementBehaviorInterface/ElementBehavior.h"

class BombElementBehavior: public  ElementBehavior{
public:
    void doEffect(Player &player);
};


#endif //GAME_BOMBELEMENTBEHAVIOR_H
