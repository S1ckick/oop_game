//
// Created by Максим on 23.11.2020.
//

#include "EnemyState.h"
#include "../PlayerState/PlayerState.h"

bool EnemyState::makeMove() const {
    bool check = this->game->enemiesMove();
    if(check)
        this->game->changeState(new PlayerState());
    return check;
}

void EnemyState::setGame(Game *game) {
    this->game = game;
}

