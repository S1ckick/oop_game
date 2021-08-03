//
// Created by Максим on 24.10.2020.
//

#ifndef GAME_ISENDEDCOMMAND_H
#define GAME_ISENDEDCOMMAND_H

#include "../../Game.h"
class IsEndedCommand {
public:
    IsEndedCommand(Game *game) : game(game){}
    bool execute() const;
private:
    Game *game;
};


#endif //GAME_ISENDEDCOMMAND_H
