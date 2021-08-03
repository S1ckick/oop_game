//
// Created by Максим on 05.10.2020.
//

#ifndef GAME_BOMBELEMENTCREATOR_H
#define GAME_BOMBELEMENTCREATOR_H
#include "../Creator.h"

class BombElementCreator: public Creator {
public:
    ElementBehavior* factoryMethod() const;
};


#endif //GAME_BOMBELEMENTCREATOR_H
