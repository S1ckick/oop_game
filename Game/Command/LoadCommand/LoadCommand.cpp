//
// Created by Максим on 15.12.2020.
//

#include "LoadCommand.h"
#include "../../Saver/CareTaker.h"
void LoadCommand::execute() const {
    CareTaker *taker = new CareTaker(game);
    taker->undo();
    delete taker;
}