//
// Created by Максим on 02.11.2020.
//

#include "None.h"
string None::getName() const{
    return elem;
}
ElementTypes None::getType() const {
    return type;
}

SubLogs* None::getSubLog() const {
    return subLog;
}