//
// Created by Максим on 18.12.2020.
//

#ifndef GAME_PRINTER_H
#define GAME_PRINTER_H

#include <SFML/Graphics.hpp>
#include "../../json.hpp"
using nlohmann::json;

#define SIZE 80

class Printer {
public:
    void reset();
    sf::RenderWindow window;
    static std::shared_ptr<Printer> getInstance(json data);
    static std::shared_ptr<Printer> getInstance();
    ~Printer();
    void print(json data);

    bool getTurn(char &ch);
    bool isNewGame();
    char menuChoice();

private:
    Printer(int width, int height);
    static std::shared_ptr<Printer> printerInstance;
    sf::Texture textures[14];
    sf::Sprite sprite;
    sf::Text text;
    sf::Font font;
    int width;
    int height;


};


#endif //GAME_PRINTER_H
