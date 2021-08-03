//
// Created by Максим on 05.10.2020.
//

#ifndef GAME_STARELEMENTCREATOR_H
#define GAME_STARELEMENTCREATOR_H
#include "../Creator.h"

class StarElementCreator : public Creator {
public:
    ElementBehavior* factoryMethod() const;
};


#endif //GAME_STARELEMENTCREATOR_H
