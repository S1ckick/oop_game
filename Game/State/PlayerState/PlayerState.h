//
// Created by Максим on 23.11.2020.
//

#ifndef GAME_PLAYERSTATE_H
#define GAME_PLAYERSTATE_H
#include "../State.h"
#include "../../Game.h"

class PlayerState : public State {
public:
    bool makeMove() const;
    void setGame(Game *game);

private:
    Game *game;
};


#endif //GAME_PLAYERSTATE_H
