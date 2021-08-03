//
// Created by Максим on 18.10.2020.
//

#include "LogFile.h"
#include <iostream>
LogFile::LogFile(const char *filename): file(filename,std::ios::out){
    try {
        if (!file) {
            throw "Can't open file!!!";
        }
    }
    catch(const char* exception){
        std::cerr << exception << std::endl;
        file.open("../Game/Logs/logs.txt", std::ios::out);
    }
}

LogFile::~LogFile() {
    file.close();
}

std::ofstream& LogFile::fileStream() {
    return file;
}

