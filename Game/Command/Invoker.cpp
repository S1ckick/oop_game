//
// Created by Максим on 24.10.2020.
//

#include "Invoker.h"
void Invoker::setGameCommand(CommandInterface *command) {
    this->command = command;
}
bool Invoker::doGameCommand() {
    return command->execute();
}

void Invoker::setMoveCommand(MovePlayerCommand *moveCommand) {
    this->moveCommand = moveCommand;
}

bool Invoker::doMoveCommand() {
    return moveCommand->execute();
}

void Invoker::setIsEndedCommand(IsEndedCommand *isEnded) {
    this->isEnded = isEnded;
}

bool Invoker::isEndedCommand() {
    return isEnded->execute();
}

void Invoker::setLoadCommand(LoadCommand *loadCommand) {
    this->loadCommand = loadCommand;
}

void Invoker::doLoadCommand() {
    loadCommand->execute();
}

void Invoker::setSaveCommand(SaveCommand *saveCommand) {
    this->saveCommand = saveCommand;
}

void Invoker::doSaveCommand() {
    saveCommand->execute();
}

void Invoker::setPrintCommand(PrintCommand *printCommand) {
    this->printCommand = printCommand;
}

void Invoker::doPrintCommand() {
    printCommand->execute();
}

Invoker::~Invoker() {
    delete command;
    delete moveCommand;
    delete isEnded;
    delete loadCommand;
    delete saveCommand;
    delete printCommand;
}