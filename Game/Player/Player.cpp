//
// Created by Максим on 03.10.2020.
//

#include "Player.h"
#include "../Board/Cell/BehaviorContext/BehaviorContext.h"
#include "../Board/Cell/BehaviorStrategy/ElementPassing/ElementPassing.h"
#include "../Board/Cell/BehaviorStrategy/ElementInteraction/ElementInteraction.h"
int Player::getHealth() {
    return this->health;
}

int Player::getStars() {
    return this->stars;
}

void Player::setHealth(int health) {
    this->health = health;
}

void Player::setStars(int stars) {
    this->stars = stars;
}

int Player::getCurrentX() {
    return this->currentX;
}

int Player::getCurrentY() {
    return this->currentY;
}

void Player::setCurrentX(int currentX) {
    this->currentX = currentX;
}

void Player::setCurrentY(int currentY) {
    this->currentY = currentY;
}

int Player::getStan() {
    return stan;
}

void Player::setStan(int stan) {
    this->stan = stan;
}

Player& operator+=(Player &player, ElementTypes elem) {
    BehaviorContext *context = new BehaviorContext(new ElementPassing);
    if((elem == HEAL && player.getHealth() == 10)){
        context->interactWithPlayer(player, elem);
    }
    else {
        context->setStrategy(new ElementInteraction);
        context->interactWithPlayer(player, elem);
    }
    delete context;
    return player;
}

Player& operator+=(Player &player, EnemyInterface *enemy){
    enemy->attack(player);
    return player;
}


std::ostream& operator<<(std::ostream &out, Player &player) {
    out << "Текущие координаты игрока: строка " << player.getCurrentX() << " ,столбец " << player.getCurrentY() <<"\n";
    out << "Здоровье: " << player.getHealth() << "\n";
    out << "Очки: "  <<player.getStars() << " из 3 \n";

    return out;
}