//
// Created by Максим on 03.10.2020.
//

#ifndef GAME_STARELEMENTBEHAVIOR_H
#define GAME_STARELEMENTBEHAVIOR_H
#include "../ElementBehaviorInterface/ElementBehavior.h"

class StarElementBehavior: public ElementBehavior {
public:
    void doEffect(Player &player);

};


#endif //GAME_STARELEMENTBEHAVIOR_H
