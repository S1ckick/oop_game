//
// Created by Максим on 02.11.2020.
//

#include "Bomb.h"
string Bomb::getName() const{
    return elem;
}

ElementTypes Bomb::getType() const {
    return type;
}

SubLogs* Bomb::getSubLog() const {
    return subLog;
}