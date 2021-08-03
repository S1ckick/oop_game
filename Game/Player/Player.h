//
// Created by Максим on 03.10.2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include "../Board/Cell/Cell.h"
#include "../Enemy/EnemyInterface.h"


class Player {
public:
    int getHealth();
    void setHealth(int health);

    int getStars();
    void setStars(int stars);

    int getCurrentX();
    void setCurrentX(int currentX);

    int getCurrentY();
    void setCurrentY(int currentY);

    int getStan();
    void setStan(int stan);

    friend Player &operator+=(Player &player, ElementTypes elem);
    friend Player &operator+=(Player &player, EnemyInterface *enemy);

    friend std::ostream &operator<<(std::ostream &out, Player &player);
private:
    int health;
    int stars;
    int currentX;
    int currentY;
    int stan;
};


#endif //GAME_PLAYER_H
