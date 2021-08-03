//
// Created by Максим on 14.12.2020.
//

#ifndef GAME_SAVEFILE_H
#define GAME_SAVEFILE_H


#include <fstream>
class SaveFile {
public:
    SaveFile(const char* filename, bool deleteAll);
    ~SaveFile();
    std::fstream& fileStream();
private:
    std::fstream file;
};


#endif //GAME_SAVEFILE_H
