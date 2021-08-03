//
// Created by Максим on 18.10.2020.
//

#include "StarElementLogs.h"
using namespace std;
void StarElementLogs::update(ElementTypes elem, std::ostream &stream) {
    if(elem == STAR) {
        stream << "Предмет: Очко" << endl;
        stream << "Предмет подействовал на героя и добавил ему 1 очко " << endl << endl;
    }
}