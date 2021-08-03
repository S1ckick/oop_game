//
// Created by Максим on 02.11.2020.
//

#include "Heal.h"
string Heal::getName() const{
    return elem;
}

ElementTypes Heal::getType() const {
    return type;
}

SubLogs* Heal::getSubLog() const {
    return subLog;
}