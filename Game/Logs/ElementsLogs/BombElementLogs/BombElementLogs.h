//
// Created by Максим on 18.10.2020.
//

#ifndef GAME_BOMBELEMENTLOGS_H
#define GAME_BOMBELEMENTLOGS_H
#include "../../SubLogsInterface/SubLogs.h"

class BombElementLogs : public SubLogs {
public:
    void update(ElementTypes elem, std::ostream &stream);

};


#endif //GAME_BOMBELEMENTLOGS_H
