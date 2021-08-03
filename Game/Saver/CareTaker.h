//
// Created by Максим on 14.12.2020.
//

#ifndef GAME_CARETAKER_H
#define GAME_CARETAKER_H

#include "Memento.h"
#include "../Game.h"
#include <vector>
#include "SaveFile/SaveFile.h"
#include "../Board/ArrayBoard/ArrayBoard.h"
#include "Exception.h"

class CareTaker {
public:
    CareTaker(Game *game) : game(game) {}

    void backup() {
        mementos.push_back(game->save());
    }

    bool undo() {
        if(this->mementos.empty()){
            SaveFile *saveFile = new SaveFile("../Game/Saver/SaveFile/save.json", false);
            json save;

            try {
                saveFile->fileStream() >> save;
            }
            catch (...){
                if(save.empty()){
                    return true;
                }
                throw handException("File was damaged");
            }

            char check = this->game->menuChoice(save);
            if(check == 'n'){
                return true;
            }
            else if(check == 'c'){
                game->setPlaying(false);
                return true;
            }

            Memento *memento = new GameMemento(save);
            this->game->restore(memento);
            return true;
        }
        Memento *memento = this->mementos.back();
        this->mementos.pop_back();

        try {
            this->game->restore(memento);
        }
        catch(handException& exception){
            cout << exception.error() << endl;
            return false;
        }

    }

private:
    Game *game;
    vector<Memento*> mementos;
};

#endif //GAME_CARETAKER_H
