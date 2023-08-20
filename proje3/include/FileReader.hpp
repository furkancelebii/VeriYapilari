#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class FileReader {
private:
    std::ifstream inputFile;
    bool isOpen;

public:
    FileReader(const std::string& fileName);
    ~FileReader();
    bool isOpened() const;
    bool getNextLine(std::string& line);
};

#endif
