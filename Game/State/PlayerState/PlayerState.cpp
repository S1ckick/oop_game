//
// Created by Максим on 23.11.2020.
//

#include "PlayerState.h"

#include "../EnemyState/EnemyState.h"

bool PlayerState::makeMove() const {
    bool check = game->playerMove();
    if(check)
        this->game->changeState(new EnemyState());
    return check;
}

void PlayerState::setGame(Game *game) {
    this->game = game;
}