//
// Created by Максим on 19.10.2020.
//

#include "LogConsoleOut.h"
#include <iostream>
void LogConsoleOut::update(ElementTypes elem, std::ostream &file) {
    subLogs.update(elem,std::cout);
}