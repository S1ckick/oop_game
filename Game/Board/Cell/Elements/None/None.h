//
// Created by Максим on 02.11.2020.
//

#ifndef GAME_NONE_H
#define GAME_NONE_H
#include "../ElementInterface.h"
#include "../../../../Logs/ElementsLogs/NoneElementLogs/NoneElementLogs.h"
class None : public ElementInterface{
public:
    string getName() const;
    ElementTypes getType() const;
    SubLogs* getSubLog() const;
private:
    string elem = "Ничего";
    ElementTypes type = NONE;
    SubLogs *subLog = new NoneElementLogs();
};


#endif //GAME_NONE_H
