//
// Created by Максим on 24.10.2020.
//

#include "StartCommand.h"
bool StartCommand::execute() const {
    game->startGame();
    return true;
}