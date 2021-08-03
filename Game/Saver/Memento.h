//
// Created by Максим on 14.12.2020.
//

#ifndef GAME_MEMENTO_H
#define GAME_MEMENTO_H

#include "../../json.hpp"

using nlohmann::json;
class Memento {
public:
    virtual json getState() const = 0;
};

class GameMemento : public Memento{
public:
    GameMemento(json state) : state(state){}
    json getState() const {return state;}
private:
    json state;
};



#endif //GAME_MEMENTO_H
