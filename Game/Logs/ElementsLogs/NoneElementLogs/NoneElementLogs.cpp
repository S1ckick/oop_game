//
// Created by Максим on 18.10.2020.
//

#include "NoneElementLogs.h"
using namespace std;
void NoneElementLogs::update(ElementTypes elem, std::ostream &stream) {
    if(elem == NONE)
        stream << "Предмет: Ничего"<< endl << endl;
}