//
// Created by Максим on 05.10.2020.
//

#ifndef GAME_HEALELEMENTCREATOR_H
#define GAME_HEALELEMENTCREATOR_H
#include "../Creator.h"

class HealElementCreator : public Creator {
public:
    ElementBehavior* factoryMethod() const;
};


#endif //GAME_HEALELEMENTCREATOR_H
