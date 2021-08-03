//
// Created by Максим on 27.11.2020.
//

#include "Stan.h"
#include "../../Player/Player.h"

void Stan::attack(EnemyInterface *enemy, Player &player) {
    if(enemy->getX() == player.getCurrentX() && enemy->getY() == player.getCurrentY()){
        player.setStan(player.getStan()+1);
    }
}

string Stan::getName() {
    return "Stan";
}
