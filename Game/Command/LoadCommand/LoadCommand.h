//
// Created by Максим on 15.12.2020.
//

#ifndef GAME_LOADCOMMAND_H
#define GAME_LOADCOMMAND_H

#include "../../Game.h"

class LoadCommand {
public:
    LoadCommand(Game *game) : game(game){}
    void execute() const;
private:
    Game *game;
};


#endif //GAME_LOADCOMMAND_H
