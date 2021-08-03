//
// Created by Максим on 24.10.2020.
//

#ifndef GAME_ENDCOMMAND_H
#define GAME_ENDCOMMAND_H
#include "../CommandInterface.h"
#include "../../../Game.h"

class EndCommand : public CommandInterface{
public:
    EndCommand(Game *game, bool choice) : game(game), choice(choice){}
    bool execute() const;
private:
    Game *game;
    bool choice;

};


#endif //GAME_ENDCOMMAND_H
