//
// Created by Максим on 05.10.2020.
//

#include "BehaviorContext.h"
BehaviorContext::BehaviorContext(BehaviorStrategy *strategy) : strategy_(strategy) {

}

BehaviorContext::~BehaviorContext() {
    delete this->strategy_;
}

void BehaviorContext::setStrategy(BehaviorStrategy *strategy) {
    delete this->strategy_;
    this->strategy_ = strategy;
}

void BehaviorContext::interactWithPlayer(Player &player, ElementTypes elem) {
    this->strategy_->executeBehavior(player, elem);
}

