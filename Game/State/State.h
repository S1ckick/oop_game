//
// Created by Максим on 23.11.2020.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H

class Game;
class State {
public:
    virtual bool makeMove() const = 0;
    virtual void setGame(Game *game) = 0;
};


#endif //GAME_STATE_H
