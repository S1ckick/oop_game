//
// Created by Максим on 05.10.2020.
//

#ifndef GAME_BEHAVIORSTRATEGY_H
#define GAME_BEHAVIORSTRATEGY_H

#include "../../../Player/Player.h"

class BehaviorStrategy {
public:
    virtual void executeBehavior(Player &player, ElementTypes elem) const = 0;
    virtual ~BehaviorStrategy() {};
};
#endif //GAME_BEHAVIORSTRATEGY_H
