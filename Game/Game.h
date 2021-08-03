//
// Created by Максим on 22.10.2020.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H
#include "Player/Player.h"
#include "Logs/LogFile/LogFile.h"
#include "Saver/SaveFile/SaveFile.h"
#include "State/State.h"
#include "Enemy/EnemyInterface.h"
#include <vector>
#include "Saver/Memento.h"
#include "../UI/Printer/Printer.h"


class Game {
public:
    bool makeMove();
    bool playerMove();
    bool enemiesMove();

    void startGame();
    bool isPlayerDone();
    bool isPlayerDead();
    bool endGame(bool choice);
    void changeState(State *state);
    const std::vector<EnemyInterface*> &getEnemies();
    char menuChoice(json save);

    Memento * save();
    void restore(Memento *memento);

    void printBoard();

    void setPlaying(bool check);
    bool getPlaying();

private:
    LogFile *logFile;

    State *state;
    std::vector<EnemyInterface *> enemies;

    bool firstGame = true;
    bool isPlaying = true;
};


#endif //GAME_GAME_H
