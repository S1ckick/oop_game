//
// Created by Максим on 05.10.2020.
//

#ifndef GAME_CREATOR_H
#define GAME_CREATOR_H
#include "../ElementBehaviorInterface/ElementBehavior.h"

class Creator {
public:
    virtual ~Creator(){};
    virtual ElementBehavior* factoryMethod() const = 0;
    void doBehavior(Player &player);
};


#endif //GAME_CREATOR_H
