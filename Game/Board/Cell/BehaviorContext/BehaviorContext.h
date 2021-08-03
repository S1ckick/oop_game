//
// Created by Максим on 05.10.2020.
//

#ifndef GAME_BEHAVIORCONTEXT_H
#define GAME_BEHAVIORCONTEXT_H

#include "../BehaviorStrategy/BehaviorStrategy.h"

class BehaviorContext {
private:
    BehaviorStrategy *strategy_;
public:
    BehaviorContext(BehaviorStrategy *strategy = nullptr);
    ~BehaviorContext();
    void setStrategy(BehaviorStrategy *strategy);
    void interactWithPlayer(Player &player, ElementTypes elem);
};


#endif //GAME_BEHAVIORCONTEXT_H
