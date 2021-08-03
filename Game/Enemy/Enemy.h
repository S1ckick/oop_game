//
// Created by Максим on 23.11.2020.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include <iostream>
#include "EnemyInterface.h"
#include <random>


template <class MovementType, class HitType>
class Enemy : public EnemyInterface, MovementType, HitType{
public:
    Enemy(int x, int y) : EnemyInterface(x,y) {}

    void move(const std::vector<Cell*> &neighbors){
        MovementType::move(this, neighbors);
    }

    void attack(Player &player){
        HitType::attack(this, player);
    }

    string getAttack(){
        return HitType::getName();
    }

    string getMove(){
        return MovementType::getName();
    }
};

#endif //GAME_ENEMY_H
