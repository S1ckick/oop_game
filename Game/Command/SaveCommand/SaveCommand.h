//
// Created by Максим on 15.12.2020.
//

#ifndef GAME_SAVECOMMAND_H
#define GAME_SAVECOMMAND_H

#include "../../Game.h"

class SaveCommand {
public:
    SaveCommand(Game *game) : game(game){}
    void execute() const;
private:
    Game *game;
};


#endif //GAME_SAVECOMMAND_H
