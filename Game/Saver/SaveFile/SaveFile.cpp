//
// Created by Максим on 14.12.2020.
//

#include "SaveFile.h"
#include <iostream>

SaveFile::SaveFile(const char *filename, bool deleteAll){
    if(deleteAll){
        file.open(filename, std::ios::in | std::ios::out | std::ios::trunc);
    }
    else {
        file.open(filename, std::ios::in | std::ios::out);
    }
    try {
        if (!file) {
            throw "Can't open file!!!";
        }
    }
    catch(const char* exception){
        std::cerr << exception << std::endl;
        file.open("../Game/Saver/SaveFile/save.json");
    }
}

SaveFile::~SaveFile() {
    file.close();
}


std::fstream & SaveFile::fileStream() {
    return file;
}