//
// Created by Максим on 24.10.2020.
//

#include "MovePlayerCommand.h"
bool MovePlayerCommand::execute() const {
    return game->makeMove();
}
