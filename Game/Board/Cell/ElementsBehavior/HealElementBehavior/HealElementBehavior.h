//
// Created by Максим on 03.10.2020.
//

#ifndef GAME_HEALELEMENTBEHAVIOR_H
#define GAME_HEALELEMENTBEHAVIOR_H
#include "../ElementBehaviorInterface/ElementBehavior.h"

class HealElementBehavior: public ElementBehavior{
public:
    void doEffect(Player &player);
};


#endif //GAME_HEALELEMENTBEHAVIOR_H
