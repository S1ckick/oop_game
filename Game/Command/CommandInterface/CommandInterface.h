//
// Created by Максим on 24.10.2020.
//

#ifndef GAME_COMMANDINTERFACE_H
#define GAME_COMMANDINTERFACE_H
class CommandInterface{
public:
    virtual ~CommandInterface(){}
    virtual bool execute() const = 0;
};


#endif //GAME_COMMANDINTERFACE_H
