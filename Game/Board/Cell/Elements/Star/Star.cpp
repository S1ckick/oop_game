//
// Created by Максим on 02.11.2020.
//

#include "Star.h"

string Star::getName() const{
    return elem;
}

ElementTypes Star::getType() const {
    return type;
}

SubLogs* Star::getSubLog() const {
    return subLog;
}