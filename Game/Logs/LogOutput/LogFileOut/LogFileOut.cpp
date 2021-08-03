//
// Created by Максим on 19.10.2020.
//

#include "LogFileOut.h"
void LogFileOut::update(ElementTypes elem,std::ostream &file) {
    subLogs.update(elem,file);
}