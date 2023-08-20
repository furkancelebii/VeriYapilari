#include "FileReader.hpp"
//Dosya açma için fonksiyonları döndürüyoruz.
FileReader::FileReader(const std::string& fileName) {
    inputFile.open(fileName);
}

FileReader::~FileReader() {
    if (inputFile.is_open()) {
        inputFile.close();
    }
}

bool FileReader::isOpened() const {
    return inputFile.is_open();
}

bool FileReader::getNextLine(std::string& line) {
    return static_cast<bool>(std::getline(inputFile, line));
}