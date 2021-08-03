//
// Created by Максим on 24.10.2020.
//

#ifndef GAME_MOVEPLAYERCOMMAND_H
#define GAME_MOVEPLAYERCOMMAND_H

#include "../../Game.h"

class MovePlayerCommand {
public:
    MovePlayerCommand(Game *game) : game(game){}
    bool execute() const;
private:
    Game *game;


};


#endif //GAME_MOVEPLAYERCOMMAND_H
