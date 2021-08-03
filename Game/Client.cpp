//
// Created by Максим on 23.10.2020.
//

#include "Client.h"
#include "Game.h"
#include "Command/Invoker.h"
#include "Command/CommandInterface/StartCommand/StartCommand.h"
#include "Command/CommandInterface/EndCommand/EndCommand.h"
#include "Command/MovePlayerCommand/MovePlayerCommand.h"
#include "Command/IsEndedCommand/IsEndedCommand.h"
#include "Command/LoadCommand/LoadCommand.h"
#include "Command/SaveCommand/SaveCommand.h"
#include "Command/PrintCommand/PrintCommand.h"
#include <iostream>

using namespace std;
void Client::clientDoSome() {
    Game *game = new Game;
    Invoker *invoker = new Invoker;

        bool playing = true;
        while(playing) {
            invoker->setGameCommand(new StartCommand(game));
            invoker->doGameCommand();


            invoker->setLoadCommand(new LoadCommand(game));
            invoker->doLoadCommand();
            invoker->setSaveCommand(new SaveCommand(game));
            invoker->doSaveCommand();

            invoker->setPrintCommand(new PrintCommand(game));
            invoker->doPrintCommand();

            invoker->setMoveCommand(new MovePlayerCommand(game));

            invoker->setIsEndedCommand(new IsEndedCommand(game));

            while (!invoker->isEndedCommand() && invoker->doMoveCommand()) {
                invoker->doSaveCommand();
                invoker->doPrintCommand();
            }

            invoker->setGameCommand(new EndCommand(game, invoker->isEndedCommand()));
            playing = invoker->doGameCommand();
        }

    delete invoker;
    delete game;
}