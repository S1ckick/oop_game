//
// Created by Максим on 03.10.2020.
//

#include "BombElementBehavior.h"


void BombElementBehavior::doEffect(Player &player) {
    int currentHealth = player.getHealth();
    player.setHealth(currentHealth-1);
}