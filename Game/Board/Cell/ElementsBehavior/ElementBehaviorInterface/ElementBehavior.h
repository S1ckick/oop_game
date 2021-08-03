//
// Created by Максим on 03.10.2020.
//

#ifndef GAME_ELEMENTBEHAVIOR_H
#define GAME_ELEMENTBEHAVIOR_H

#include "../../../../Player/Player.h"

class ElementBehavior {
public:
    virtual void doEffect(Player &player) = 0;
    virtual ~ElementBehavior() {}
};

#endif //GAME_ELEMENTBEHAVIOR_H
