//
// Created by Максим on 19.10.2020.
//

#ifndef GAME_LOGFILEOUT_H
#define GAME_LOGFILEOUT_H
#include "../../AbstractLogs/AbstractLogs.h"

class LogFileOut : public AbstractLogs {
public:
    LogFileOut(SubLogs &subLogs) : AbstractLogs(subLogs), subLogs(subLogs) {}
    void update(ElementTypes elem,std::ostream &file);
private:
    SubLogs &subLogs;
};


#endif //GAME_LOGFILEOUT_H
