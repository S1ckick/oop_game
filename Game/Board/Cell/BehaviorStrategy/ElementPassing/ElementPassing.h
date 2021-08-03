//
// Created by Максим on 05.10.2020.
//

#ifndef GAME_ELEMENTPASSING_H
#define GAME_ELEMENTPASSING_H
#include "../BehaviorStrategy.h"

class ElementPassing : public BehaviorStrategy {
    void executeBehavior(Player &player, ElementTypes elem) const;
};


#endif //GAME_ELEMENTPASSING_H
