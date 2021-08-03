//
// Created by Максим on 27.11.2020.
//

#include "Hit.h"
#include "../../Player/Player.h"

void Hit::attack(EnemyInterface *enemy, Player &player) {
    if(enemy->getX() == player.getCurrentX() && enemy->getY() == player.getCurrentY()){
        player.setHealth(player.getHealth()-1);
    }
}

string Hit::getName() {
    return "Hit";
}