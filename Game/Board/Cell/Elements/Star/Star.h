//
// Created by Максим on 02.11.2020.
//

#ifndef GAME_STAR_H
#define GAME_STAR_H
#include "../ElementInterface.h"
#include "../../../../Logs/ElementsLogs/StarElementLogs/StarElementLogs.h"
class Star : public ElementInterface{
public:
    string getName() const;
    ElementTypes getType() const;
    SubLogs* getSubLog() const;
private:
    string elem = "Очко";
    ElementTypes type = STAR;
    SubLogs *subLog = new StarElementLogs();
};


#endif //GAME_STAR_H
