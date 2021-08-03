//
// Created by Максим on 15.12.2020.
//

#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include <exception>
#include <string>

class handException : public std::exception {
public:
    handException(std::string error) : err(error){}

    const char* what() const noexcept { return err.c_str(); }

    const std::string error(){ return err;}
private:
    std::string err;
};

#endif //GAME_EXCEPTION_H
