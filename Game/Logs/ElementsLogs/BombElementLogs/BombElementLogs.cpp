//
// Created by Максим on 18.10.2020.
//

#include "BombElementLogs.h"
#include <iostream>
using namespace std;
void BombElementLogs::update(ElementTypes elem, std::ostream &stream) {
    if(elem == BOMB) {
        stream << "Предмет: Бомба" << endl;
        stream << "Предмет подействовал на героя и снял единицу здоровья " << endl << endl;
    }
}