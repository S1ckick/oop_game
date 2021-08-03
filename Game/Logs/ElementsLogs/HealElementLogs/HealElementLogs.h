//
// Created by Максим on 18.10.2020.
//

#ifndef GAME_HEALELEMENTLOGS_H
#define GAME_HEALELEMENTLOGS_H
#include "../../SubLogsInterface/SubLogs.h"
class HealElementLogs : public SubLogs {
public:
    void update(ElementTypes elem, std::ostream &stream);
};


#endif //GAME_HEALELEMENTLOGS_H
