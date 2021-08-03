//
// Created by Максим on 15.12.2020.
//

#ifndef GAME_PRINTCOMMAND_H
#define GAME_PRINTCOMMAND_H

#include "../../Game.h"



class PrintCommand {
public:
    PrintCommand(Game *game) : game(game){}
    void execute() const;
private:
    Game *game;
};


#endif //GAME_PRINTCOMMAND_H
