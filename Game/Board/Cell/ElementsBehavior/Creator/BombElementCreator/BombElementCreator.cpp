//
// Created by Максим on 05.10.2020.
//

#include "BombElementCreator.h"
#include "../../BombElementBehavior/BombElementBehavior.h"
ElementBehavior* BombElementCreator::factoryMethod() const {
    return new BombElementBehavior();
}