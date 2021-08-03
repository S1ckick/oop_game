//
// Created by Максим on 18.10.2020.
//

#ifndef GAME_LOGFILE_H
#define GAME_LOGFILE_H
#include <fstream>
class LogFile {
public:
    LogFile(const char* filename);
    ~LogFile();
    std::ofstream& fileStream();
private:
    std::ofstream file;
};


#endif //GAME_LOGFILE_H
