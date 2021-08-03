//
// Created by Максим on 24.10.2020.
//

#include "IsEndedCommand.h"
bool IsEndedCommand::execute() const {
    return game->isPlayerDone() || game->isPlayerDead();
}
