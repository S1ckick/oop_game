//
// Created by Максим on 18.12.2020.
//

#include "Printer.h"
#include "../../Game/Saver/Exception.h"

std::shared_ptr<Printer> Printer::printerInstance=nullptr;

std::shared_ptr<Printer> Printer::getInstance(json data) {
    if(!printerInstance){
        printerInstance = std::shared_ptr<Printer>(new Printer(data["length"],data["height"]));
    }
    return printerInstance;
}

std::shared_ptr<Printer> Printer::getInstance() {
    return printerInstance;
}

Printer::~Printer() {
    printerInstance->window.close();
    printerInstance = nullptr;
}

void Printer::reset() {
    printerInstance = nullptr;
}

Printer::Printer(int width, int height) : window(sf::VideoMode(width*SIZE+600,height*SIZE), "Game"), width(width), height(height){
    if(!textures[0].loadFromFile("../UI/Images/sand.jpg") ||
       !textures[1].loadFromFile("../UI/Images/water.jpg") ||
       !textures[2].loadFromFile("../UI/Images/exit.jpg") ||
       !textures[3].loadFromFile("../UI/Images/heal.png") ||
       !textures[4].loadFromFile("../UI/Images/star.png") ||
       !textures[5].loadFromFile("../UI/Images/bomb.png") ||
       !textures[6].loadFromFile("../UI/Images/enemy1.png") ||
       !textures[7].loadFromFile("../UI/Images/enemy2.png") ||
       !textures[8].loadFromFile("../UI/Images/enemy3.png") ||
       !textures[9].loadFromFile("../UI/Images/enemy4.png") ||
       !textures[10].loadFromFile("../UI/Images/hero.png") ||
       !font.loadFromFile("../UI/font.otf")){
        throw handException("Bad texture loading!");
    }
}

void Printer::print(json data) {


    int n_row = 0;
    int n_col = 0;
    window.clear(sf::Color(97, 225, 232));
    for(auto row : data["board"]){

        for(auto item : row){
            sprite.setPosition(n_row*SIZE,n_col*SIZE);
            switch((int)item[0]){
                case 0:
                    sprite.setTexture(textures[0],true);
                    break;
                case 1:
                    sprite.setTexture(textures[1],true);
                    break;
                case 2:
                    sprite.setTexture(textures[1],true);
                    break;
                case 3:
                    sprite.setTexture(textures[2],true);
                    break;
                default:
                    sprite.setTexture(textures[0],true);
                    break;
            }

            window.draw(sprite);

            switch((int)item[1]){
                //bomb
                case 1:
                    sprite.setTexture(textures[5],true);
                    break;
                //heal
                case 2:
                    sprite.setTexture(textures[3],true);
                    break;
                //star
                case 3:
                    sprite.setTexture(textures[4],true);
                    break;
            }
            window.draw(sprite);
            n_col = (n_col + 1) % ((int)data["length"]);
        }
        n_row++;

        for(auto enemy : data["enemies"]["enemy"]){
            if(enemy[2] == "Fixed"){
                if(enemy[3] == "Stan"){
                    sprite.setTexture(textures[7],true);
                }
                else if(enemy[3] == "Hit"){
                    sprite.setTexture(textures[6],true);
                }
            }
            else if(enemy[2] == "Random"){
                if(enemy[3] == "Stan"){
                    sprite.setTexture(textures[9],true);
                }
                else if(enemy[3] == "Hit"){
                    sprite.setTexture(textures[8],true);
                }
            }
            sprite.setPosition((int)enemy[0]*SIZE,(int)enemy[1]*SIZE);
            window.draw(sprite);
        }

        sprite.setPosition((int)data["player"]["x"]*SIZE,(int)data["player"]["y"]*SIZE);
        sprite.setTexture(textures[10],true);
        window.draw(sprite);

        text.setFont(font);
        int size = 60;
        text.setCharacterSize(size);
        text.setString("Player");
        text.setFillColor(sf::Color::Black);
        text.setPosition((int)data["length"]*SIZE+10,10);
        window.draw(text);

        int hp = ((int)data["player"]["hp"]);
        text.setString("hp: " + std::to_string(hp));
        text.setPosition((int)data["length"]*SIZE+10,80);
        window.draw(text);

        int stars = (int)data["player"]["stars"];
        text.setString("stars: " + std::to_string(stars) + " need 3");
        text.setPosition((int)data["length"]*SIZE+10, 150);
        window.draw(text);

        int stan = (int)data["player"]["stan"];
        if(stan!=0){
            text.setString("stanned for " + std::to_string(stan) + " turns");
            text.setPosition((int)data["length"]*SIZE+10, 220);
            window.draw(text);
        }
    }
    window.display();
}

bool Printer::isNewGame() {
    window.clear(sf::Color(97, 225, 232));

    text.setFont(font);
    int size = 60;
    text.setCharacterSize(size);
    text.setString("Type anything to start new game");
    text.setFillColor(sf::Color::Black);
    text.setPosition(width*SIZE/2,height*SIZE/2);
    window.draw(text);

    window.display();

    sf::Event event;
    while(window.isOpen()){
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
                return false;
            }

            if (event.type == sf::Event::KeyReleased) {
                return true;
            }

        }

    }
}

bool Printer::getTurn(char &ch) {
    sf::Event event;
    while(window.isOpen()){
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
                return false;
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W) {
                ch = 'w';
                return true;
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) {
                ch = 'a';
                return true;
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S) {
                ch = 's';
                return true;
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D) {
                ch = 'd';
                return true;
            }
        }

    }
}

char Printer::menuChoice() {
    window.clear(sf::Color(97, 225, 232));

    text.setFont(font);
    int size = 60;
    text.setCharacterSize(size);
    text.setString("Type n to start new game");
    text.setFillColor(sf::Color::Black);
    text.setPosition(width*SIZE/2,height*SIZE/2 - 60);
    window.draw(text);

    text.setString("Type l to load game");
    text.setPosition(width*SIZE/2,height*SIZE/2 + 40);
    window.draw(text);

    window.display();

    sf::Event event;
    while(window.isOpen()){
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
                return 'c';
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::N) {
                return 'n';
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::L) {
                return 'l';
            }

        }

    }
}
