//
// Created by Максим on 22.10.2020.
//

#include "Game.h"
#include "Board/ArrayBoard/ArrayBoard.h"
#include "State/EnemyState/EnemyState.h"
#include "Enemy/Enemy.h"
#include "Logs/LogOutput/LogFileOut/LogFileOut.h"
#include "Logs/LogOutput/LogConsoleOut/LogConsoleOut.h"
#include "Enemy/MovePatterns/Fixed.h"
#include "Enemy/MovePatterns/Random.h"
#include "Enemy/AttackPatterns/Hit.h"
#include "Enemy/AttackPatterns/Stan.h"
#include "Player/PlayerMovement/PlayerMovement.h"
#include "Logs/PlayerSubLogs/PlayerSubLogs.h"
#include <unordered_map>
#include "Saver/Exception.h"

bool Game::makeMove() {
    return getPlaying() && this->state->makeMove();
}

void Game::changeState(State *state) {
    this->state = state;
    this->state->setGame(this);
}

void Game::startGame() {
    this->logFile = new LogFile("../Game/Logs/logs.txt");
    this->state = new EnemyState();
    this->state->setGame(this);
    setPlaying(true);

    if(!firstGame){
        ArrayBoard::getInstance().rebuildData();
    }else {
        PlayerSubLogs *playerLogs = new PlayerSubLogs(ArrayBoard::getInstance().getPlayer());
        ArrayBoard::getInstance().subscribe(new LogFileOut(*playerLogs));
        ArrayBoard::getInstance().subscribe( new LogConsoleOut(*playerLogs));
    }
    enemies.clear();
    Cell& emptyCell = ArrayBoard::getInstance().emptyCell();
    enemies.push_back(new Enemy<Random, Stan>(emptyCell.getX(), emptyCell.getY()));
    emptyCell = ArrayBoard::getInstance().emptyCell();
    enemies.push_back(new Enemy<Random, Hit>(emptyCell.getX(), emptyCell.getY()));
    emptyCell = ArrayBoard::getInstance().emptyCell();
    enemies.push_back(new Enemy<Fixed, Hit>(emptyCell.getX(), emptyCell.getY()));
}

bool Game::isPlayerDone() {
    Player &player = ArrayBoard::getInstance().getPlayer();
    bool atExitPoint = player.getCurrentX() == ArrayBoard::getInstance().getExitX()
                       && player.getCurrentY() == ArrayBoard::getInstance().getExitY();

    if(atExitPoint && player.getStars()<3){
        std::cout << "Соберите достаточное количество звездочек для выхода!\n";
    }

    return atExitPoint && player.getStars()>=3;
}

bool Game::isPlayerDead(){
    return ArrayBoard::getInstance().getPlayer().getHealth() <=0;
}

bool Game::endGame(bool choice) {
    if(choice) {
        std::cout <<"Игра закончилась." << std::endl;
        SaveFile *saveFile = new SaveFile("../Game/Saver/SaveFile/save.json",true);
        firstGame = false;
        std::shared_ptr<Printer> p = Printer::getInstance();
        return p->isNewGame();
    }
    ArrayBoard::getInstance().clearData();
    logFile = nullptr;
    enemies.clear();
    state = nullptr;
    setPlaying(false);
}

char Game::menuChoice(json save) {
    std::shared_ptr<Printer> p = Printer::getInstance(save);
    return p->menuChoice();
}

bool Game::playerMove() {
    if(!getPlaying()){
        return false;
    }
    PlayerMovement movement;
    std::shared_ptr<Printer> p = Printer::getInstance();
    char move;
    if(!p->getTurn(move)){
        return false;
    }
    movement.move(move);
    Player &player = ArrayBoard::getInstance().getPlayer();
    //взаимодействие с элементом на клетке
    ElementTypes elem = ArrayBoard::getInstance().getItem(player.getCurrentX(),player.getCurrentY()).getEl()->getType();
    player+=elem;
    ArrayBoard::getInstance().notify(ArrayBoard::getInstance().getItem(player.getCurrentX(),player.getCurrentY()),this->logFile->fileStream());
    ArrayBoard::getInstance().moveElement(player.getCurrentX(),player.getCurrentY());
    return true;
}

bool Game::enemiesMove() {
    if(!getPlaying()){
        return false;
    }
    for(int i = 0; i<enemies.size(); i++){
        std::vector<Cell *> neighbors = ArrayBoard::getInstance().getNeighborRoads(enemies[i]->getX(), enemies[i]->getY());
        enemies[i]->move(neighbors);
        std::cout << "Враг " << i << " находится на x: " << enemies[i]->getX() << " y: " << enemies[i]->getY() << std::endl;
    }
    Player &player = ArrayBoard::getInstance().getPlayer();
    for(auto &enemy : enemies){
        player+=enemy;
    }
    return true;
}

const std::vector<EnemyInterface *> & Game::getEnemies() {
    return enemies;
}

Memento * Game::save() {
    json save;
    string hashStr = "";
    //saving board
    save["length"] = ArrayBoard::getInstance().getWidth();
    save["height"] = ArrayBoard::getInstance().getHeight();
    save["exitX"] = ArrayBoard::getInstance().getExitX();
    save["exitY"] = ArrayBoard::getInstance().getExitY();

    hashStr+= to_string(save["length"]) + to_string(save["height"]) + to_string(save["exitX"]) + to_string(save["exitY"]);

    for(int i = 0; i < save["length"]; i++){
        json row;
        for(int j = 0; j < save["height"]; j++){
            row.push_back({ArrayBoard::getInstance().getItem(i,j).getObject(),ArrayBoard::getInstance().getItem(i,j).getEl()->getType()});
            hashStr+= to_string(ArrayBoard::getInstance().getItem(i,j).getObject()) + to_string(ArrayBoard::getInstance().getItem(i,j).getEl()->getType());
        }
        save["board"].push_back(row);
    }

    //saving player
    save["player"]["hp"] = ArrayBoard::getInstance().getPlayer().getHealth();
    save["player"]["x"] = ArrayBoard::getInstance().getPlayer().getCurrentX();
    save["player"]["y"] = ArrayBoard::getInstance().getPlayer().getCurrentY();
    save["player"]["stars"] = ArrayBoard::getInstance().getPlayer().getStars();
    save["player"]["stan"] = ArrayBoard::getInstance().getPlayer().getStan();

    hashStr+=to_string(save["player"]["hp"]) + to_string(save["player"]["x"]) + to_string(save["player"]["y"]) + to_string(save["player"]["stars"]) + to_string(save["player"]["stan"]);

    //saving enemies
    save["enemies"]["n"] = getEnemies().size();
    hashStr+=to_string(save["enemies"]["n"]);
    for(auto enemy : getEnemies()){
        save["enemies"]["enemy"].push_back({enemy->getX(), enemy->getY(), enemy->getMove(), enemy->getAttack()});
        hashStr+=to_string(enemy->getX()) + to_string(enemy->getY()) + "\"" + enemy->getMove() + "\"" + "\"" + enemy->getAttack() + "\"";
    }

    hash<string> hasher;
    size_t hash = hasher(hashStr);
    save["hash"] = hash;

    SaveFile *saveFile = new SaveFile("../Game/Saver/SaveFile/save.json", false);
    saveFile->fileStream() << save << flush;
    ArrayBoard::getInstance().setState(save);
    return new GameMemento(save);
}

void Game::restore(Memento *memento) {
    json save = memento->getState();
    string hashStr = "";
    try {
        //set board
        ArrayBoard::getInstance().resetBoard(save["board"], save["length"], save["height"]);
        ArrayBoard::getInstance().setExitX(save["exitX"]);
        ArrayBoard::getInstance().setExitY(save["exitY"]);
        hashStr += to_string(save["length"]) + to_string(save["height"]) +
                   to_string(save["exitX"]) + to_string(save["exitY"]);
        for(auto row : save["board"]){
            for(auto item : row){
                hashStr+=to_string(item[0]) + to_string(item[1]);
            }
        }
        //set player
        ArrayBoard::getInstance().getPlayer().setHealth(save["player"]["hp"]);
        ArrayBoard::getInstance().getPlayer().setCurrentX(save["player"]["x"]);
        ArrayBoard::getInstance().getPlayer().setCurrentY(save["player"]["y"]);
        ArrayBoard::getInstance().getPlayer().setStars(save["player"]["stars"]);
        ArrayBoard::getInstance().getPlayer().setStan(save["player"]["stan"]);
        hashStr+=to_string(save["player"]["hp"]) + to_string(save["player"]["x"]) + to_string(save["player"]["y"]) + to_string(save["player"]["stars"]) + to_string(save["player"]["stan"]);


        //set enemies
        enemies.clear();
        hashStr+=to_string(save["enemies"]["n"]);
        for (int i = 0; i < save["enemies"]["n"]; i++) {
            if (save["enemies"]["enemy"][i][2] == "Random") {
                if (save["enemies"]["enemy"][i][3] == "Stan") {
                    enemies.push_back(
                            new Enemy<Random, Stan>(save["enemies"]["enemy"][i][0], save["enemies"]["enemy"][i][1]));
                } else if (save["enemies"]["enemy"][i][3] == "Hit") {
                    enemies.push_back(
                            new Enemy<Random, Hit>(save["enemies"]["enemy"][i][0], save["enemies"]["enemy"][i][1]));
                }
            } else if (save["enemies"]["enemy"][i][2] == "Fixed") {
                if (save["enemies"]["enemy"][i][3] == "Stan") {
                    enemies.push_back(
                            new Enemy<Fixed, Stan>(save["enemies"]["enemy"][i][0], save["enemies"]["enemy"][i][1]));
                } else if (save["enemies"]["enemy"][i][3] == "Hit") {
                    enemies.push_back(
                            new Enemy<Fixed, Hit>(save["enemies"]["enemy"][i][0], save["enemies"]["enemy"][i][1]));
                }
            }
            hashStr += to_string(save["enemies"]["enemy"][i][0]) + to_string(save["enemies"]["enemy"][i][1]) + to_string(save["enemies"]["enemy"][i][2]) + to_string(save["enemies"]["enemy"][i][3]);
        }
        ArrayBoard::getInstance().setState(save);
    }

    catch(...){
        throw handException("File was damaged");
    }

        hash<string> hasher;
        size_t hash = hasher(hashStr);

        if (hash != save["hash"]) {
            throw handException("File was damaged!");
        }
}

void Game::printBoard() {
    json state = ArrayBoard::getInstance().getState();
    Printer::getInstance(state)->print(state);
}

void Game::setPlaying(bool check) {
    isPlaying = check;
}

bool Game::getPlaying() {
    return isPlaying;
}