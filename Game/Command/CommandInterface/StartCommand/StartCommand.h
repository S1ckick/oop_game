//
// Created by Максим on 24.10.2020.
//

#ifndef GAME_STARTCOMMAND_H
#define GAME_STARTCOMMAND_H
#include "../../../Game.h"
#include "../CommandInterface.h"

class StartCommand : public CommandInterface {
public:
    StartCommand(Game *game) : game(game){}
    bool execute() const;
private:
    Game *game;
};


#endif //GAME_STARTCOMMAND_H
