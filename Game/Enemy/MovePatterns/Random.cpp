//
// Created by Максим on 27.11.2020.
//
#include "Random.h"
#include <random>

void Random::move(EnemyInterface *enemy, const std::vector<Cell *> &neighbors) {
    int max = neighbors.size();
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, max-1);
    int idx = dist(mt);
    enemy->setX(neighbors[idx]->getX());
    enemy->setY(neighbors[idx]->getY());
}

string Random::getName() {
    return "Random";
}
