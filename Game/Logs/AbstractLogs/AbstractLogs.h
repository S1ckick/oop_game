//
// Created by Максим on 19.10.2020.
//

#ifndef GAME_ABSTRACTLOGS_H
#define GAME_ABSTRACTLOGS_H
#include "../SubLogsInterface/SubLogs.h"
class AbstractLogs{
public:
    explicit AbstractLogs(SubLogs &logs) : subLogs(logs){}
    virtual void update(ElementTypes elem, std::ostream &file) = 0;
    virtual ~AbstractLogs(){}
private:
    SubLogs &subLogs;
};

#endif //GAME_ABSTRACTLOGS_H
