//
// Created by Максим on 18.10.2020.
//

#ifndef GAME_PLAYERSUBLOGS_H
#define GAME_PLAYERSUBLOGS_H

#include "../SubLogsInterface/SubLogs.h"
#include "../../Player/Player.h"

class PlayerSubLogs : public SubLogs{
public:
    PlayerSubLogs(Player &player) : player(player){};
    void update(ElementTypes elem, std::ostream &stream);
private:
    Player &player;
};


#endif //GAME_PLAYERSUBLOGS_H
