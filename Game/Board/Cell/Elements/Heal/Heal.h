//
// Created by Максим on 02.11.2020.
//

#ifndef GAME_HEAL_H
#define GAME_HEAL_H
#include "../ElementInterface.h"
#include "../../../../Logs/ElementsLogs/HealElementLogs/HealElementLogs.h"
class Heal : public ElementInterface{
public:
    string getName() const;
    ElementTypes getType() const;
    SubLogs* getSubLog() const;
private:
    string elem = "Хилка";
    ElementTypes type = HEAL;
    SubLogs *subLog = new HealElementLogs();
};


#endif //GAME_HEAL_H
