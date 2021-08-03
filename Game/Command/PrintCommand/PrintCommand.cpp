//
// Created by Максим on 15.12.2020.
//

#include "PrintCommand.h"
void PrintCommand::execute() const {
    if(!game->getPlaying()){
        return;
    }
    game->printBoard();
}