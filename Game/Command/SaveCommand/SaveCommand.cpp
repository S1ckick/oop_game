//
// Created by Максим on 15.12.2020.
//

#include "SaveCommand.h"
#include "../../Saver/CareTaker.h"
void SaveCommand::execute() const {

    if(!game->getPlaying())
        return;
    
    CareTaker *taker = new CareTaker(game);
    taker->backup();
    delete taker;
}