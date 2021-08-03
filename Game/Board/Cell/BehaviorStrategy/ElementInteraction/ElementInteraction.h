//
// Created by Максим on 05.10.2020.
//

#ifndef GAME_ELEMENTINTERACTION_H
#define GAME_ELEMENTINTERACTION_H
#include "../BehaviorStrategy.h"

class ElementInteraction : public BehaviorStrategy {
public:
    //Factory method
    void executeBehavior(Player &player, ElementTypes elem) const;
};


#endif //GAME_ELEMENTINTERACTION_H
