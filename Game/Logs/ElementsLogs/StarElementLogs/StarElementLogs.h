//
// Created by Максим on 18.10.2020.
//

#ifndef GAME_STARELEMENTLOGS_H
#define GAME_STARELEMENTLOGS_H
#include "../../SubLogsInterface/SubLogs.h"

class StarElementLogs : public SubLogs{
public:
    void update(ElementTypes elem, std::ostream &stream);
};


#endif //GAME_STARELEMENTLOGS_H
