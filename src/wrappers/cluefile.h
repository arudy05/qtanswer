#ifndef CLUEFILE_H
#define CLUEFILE_H

#include <fstream>
#include <nlohmann/json.hpp>
#include <QString>
using json = nlohmann::json;

// Wrapper class for a json object
class ClueFile {
    json j;
public:
    ClueFile();
    ClueFile(std::string path);
    std::string getCategory(int cat);
    std::string getClue(int cat, int val);
    std::vector<std::string> getAnswers(int cat, int val);
    bool isFileValid();
};

#endif // CLUEFILE_H
