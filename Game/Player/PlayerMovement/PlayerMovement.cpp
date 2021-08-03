//
// Created by Максим on 03.10.2020.
//

#include "PlayerMovement.h"
#include "../../Board/ArrayBoard/ArrayBoard.h"

void PlayerMovement::move(char movement) const {
    Player &player = ArrayBoard::getInstance().getPlayer();
    if(player.getStan() > 0){
        player.setStan(player.getStan()-1);
        return;
    }
    int currentX = player.getCurrentX();
    int currentY = player.getCurrentY();
    if(movement == 'w'){
        bool isInBounds = currentX < ArrayBoard::getInstance().getWidth() && currentX >=0 && currentY-1 < ArrayBoard::getInstance().getHeight() && currentY-1>=0;
        if(isInBounds && ArrayBoard::getInstance().getItem(currentX, currentY-1).isPassible()){
            player.setCurrentY(currentY-1);
        }
    }
    else if(movement == 's'){
        bool isInBounds = currentX < ArrayBoard::getInstance().getWidth() && currentX >=0 && currentY+1 < ArrayBoard::getInstance().getHeight() && currentY+1>=0;
        if(isInBounds && ArrayBoard::getInstance().getItem(currentX, currentY+1).isPassible()){
            player.setCurrentY(currentY+1);
        }
    }
    else if(movement == 'd'){
        bool isInBounds = currentX+1 < ArrayBoard::getInstance().getWidth() && currentX+1 >=0 && currentY < ArrayBoard::getInstance().getHeight() && currentY>=0;
        if(isInBounds && ArrayBoard::getInstance().getItem(currentX+1, currentY).isPassible()){
            player.setCurrentX(currentX+1);
        }
    }
    else if(movement =='a'){
        bool isInBounds = currentX-1 < ArrayBoard::getInstance().getWidth() && currentX-1 >=0 && currentY < ArrayBoard::getInstance().getHeight() && currentY>=0;
        if(isInBounds && ArrayBoard::getInstance().getItem(currentX-1, currentY).isPassible()){
            player.setCurrentX(currentX-1);
        }
    }
}

