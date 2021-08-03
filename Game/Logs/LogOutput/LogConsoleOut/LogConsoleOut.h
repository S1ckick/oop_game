//
// Created by Максим on 19.10.2020.
//

#ifndef GAME_LOGCONSOLEOUT_H
#define GAME_LOGCONSOLEOUT_H
#include "../../AbstractLogs/AbstractLogs.h"

class LogConsoleOut : public AbstractLogs{
public:
    LogConsoleOut(SubLogs &subLogs) : AbstractLogs(subLogs), subLogs(subLogs) {}
    void update(ElementTypes elem, std::ostream &file);
private:
    SubLogs &subLogs;
};


#endif //GAME_LOGCONSOLEOUT_H
