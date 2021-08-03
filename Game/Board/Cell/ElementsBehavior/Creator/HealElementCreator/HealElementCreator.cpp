//
// Created by Максим on 05.10.2020.
//

#include "HealElementCreator.h"
#include "../../HealElementBehavior/HealElementBehavior.h"
ElementBehavior* HealElementCreator::factoryMethod() const {
    return new HealElementBehavior();
}