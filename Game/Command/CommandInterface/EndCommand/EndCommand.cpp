//
// Created by Максим on 24.10.2020.
//

#include "EndCommand.h"
bool EndCommand::execute() const {
    return game->endGame(choice);
}