//
// Created by Максим on 02.11.2020.
//

#ifndef GAME_BOMB_H
#define GAME_BOMB_H
#include "../ElementInterface.h"
#include "../../../../Logs/ElementsLogs/BombElementLogs/BombElementLogs.h"
class Bomb : public ElementInterface{
public:
    string getName() const;
    ElementTypes getType() const;
    SubLogs* getSubLog() const;
private:
    string elem = "Бомба";
    ElementTypes type = BOMB;
    SubLogs *subLog = new BombElementLogs();
};


#endif //GAME_BOMB_H
