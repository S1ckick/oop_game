//
// Created by Максим on 24.10.2020.
//

#ifndef GAME_INVOKER_H
#define GAME_INVOKER_H
#include "CommandInterface/CommandInterface.h"
#include "MovePlayerCommand/MovePlayerCommand.h"
#include "IsEndedCommand/IsEndedCommand.h"
#include "SaveCommand/SaveCommand.h"
#include "LoadCommand/LoadCommand.h"
#include "PrintCommand/PrintCommand.h"

class Invoker {
public:
    ~Invoker();
    void setGameCommand(CommandInterface *command);
    bool doGameCommand();

    void setMoveCommand(MovePlayerCommand *moveCommand);
    bool doMoveCommand();

    void setIsEndedCommand(IsEndedCommand *isEnded);
    bool isEndedCommand();

    void setLoadCommand(LoadCommand *loadCommand);
    void doLoadCommand();

    void setSaveCommand(SaveCommand *saveCommand);
    void doSaveCommand();

    void setPrintCommand(PrintCommand *printCommand);
    void doPrintCommand();

private:
    CommandInterface *command;
    MovePlayerCommand *moveCommand;
    IsEndedCommand *isEnded;
    LoadCommand *loadCommand;
    SaveCommand *saveCommand;
    PrintCommand *printCommand;
};


#endif //GAME_INVOKER_H
