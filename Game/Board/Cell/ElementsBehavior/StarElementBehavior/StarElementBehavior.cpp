//
// Created by Максим on 03.10.2020.
//

#include "StarElementBehavior.h"
#include "../../../ArrayBoard/ArrayBoard.h"
void StarElementBehavior::doEffect(Player &player) {
    int currentStars = player.getStars();
    player.setStars(currentStars + 1);
}