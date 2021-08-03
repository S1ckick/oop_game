//
// Created by Максим on 18.10.2020.
//

#ifndef GAME_NONEELEMENTLOGS_H
#define GAME_NONEELEMENTLOGS_H
#include "../../SubLogsInterface/SubLogs.h"
class Cell;

class NoneElementLogs : public SubLogs {
public:
    void update(ElementTypes elem, std::ostream &stream);
};


#endif //GAME_NONEELEMENTLOGS_H
