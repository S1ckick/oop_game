//
// Created by Максим on 18.10.2020.
//

#include "HealElementLogs.h"
using namespace std;
void HealElementLogs::update(ElementTypes elem, std::ostream &stream) {
    if(elem == HEAL) {
        stream << "Предмет: Хилка" << endl;
        stream << "Предмет подействовал на героя и прибавил ему единицу здоровья " << endl << endl;
    }
}