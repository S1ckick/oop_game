//
// Created by Максим on 23.11.2020.
//

#ifndef GAME_ENEMYSTATE_H
#define GAME_ENEMYSTATE_H
#include "../State.h"
#include "../../Game.h"

class EnemyState : public State{
public:
    bool makeMove() const;
    void setGame(Game *game);

private:
    Game *game;
};


#endif //GAME_ENEMYSTATE_H
