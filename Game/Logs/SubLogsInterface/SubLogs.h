//
// Created by Максим on 18.10.2020.
//

#ifndef GAME_SUBLOGS_H
#define GAME_SUBLOGS_H
#include <fstream>
#include "../../Enum/ElementTypes.h"
class SubLogs{
public:
    virtual void update(ElementTypes elem, std::ostream &file) = 0;
    virtual ~SubLogs() {}
};
#endif //GAME_SUBLOGS_H
