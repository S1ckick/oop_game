//
// Created by Максим on 02.11.2020.
//

#ifndef GAME_ELEMENTINTERFACE_H
#define GAME_ELEMENTINTERFACE_H

#include <string>
#include "../../../Logs/SubLogsInterface/SubLogs.h"
#include "../../../Enum/ElementTypes.h"

using namespace std;



class ElementInterface{
public:
    virtual string getName() const = 0;
    virtual ElementTypes getType() const = 0;
    virtual SubLogs* getSubLog() const = 0;
};

#endif //GAME_ELEMENTINTERFACE_H
