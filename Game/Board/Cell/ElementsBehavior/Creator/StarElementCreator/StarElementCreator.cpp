//
// Created by Максим on 05.10.2020.
//

#include "StarElementCreator.h"
#include "../../StarElementBehavior/StarElementBehavior.h"
ElementBehavior* StarElementCreator::factoryMethod() const {
    return new StarElementBehavior();
}