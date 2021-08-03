//
// Created by Максим on 18.10.2020.
//

#include "PlayerSubLogs.h"
#include <iostream>
#include "../LogFile/LogFile.h"
using namespace std;
void PlayerSubLogs::update(ElementTypes elem, std::ostream &stream) {
    stream << player;
    if(elem != NONE){
        stream << "Герой взаимодействует с предметом.";
    }
    stream << endl;
}