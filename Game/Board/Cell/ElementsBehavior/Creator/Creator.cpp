//
// Created by Максим on 05.10.2020.
//

#include "Creator.h"
void Creator::doBehavior(Player &player){
    ElementBehavior * elementBehavior = this->factoryMethod();
    elementBehavior->doEffect(player);
    delete elementBehavior;
}