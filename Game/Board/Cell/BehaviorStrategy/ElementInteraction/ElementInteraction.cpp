//
// Created by Максим on 05.10.2020.
//

#include "ElementInteraction.h"
#include "../../ElementsBehavior/Creator/Creator.h"
#include "../../ElementsBehavior/Creator/StarElementCreator/StarElementCreator.h"
#include "../../ElementsBehavior/Creator/HealElementCreator/HealElementCreator.h"
#include "../../ElementsBehavior/Creator/BombElementCreator/BombElementCreator.h"
void ElementInteraction::executeBehavior(Player &player, ElementTypes elem) const{
    if(elem == STAR){
        Creator *creator = new StarElementCreator();
        creator->doBehavior(player);
        return;
    }
    else if(elem == BOMB){
        Creator *creator = new BombElementCreator();
        creator->doBehavior(player);
        return;
    }
    else if(elem == HEAL){
        Creator *creator = new HealElementCreator();
        creator->doBehavior(player);
        return;
    }
}