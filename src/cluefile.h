#ifndef CLUEFILE_H
#define CLUEFILE_H

#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Wrapper class for a json object
class ClueFile {
    json j;
public:
    ClueFile();
    std::string getCategory(int cat);
    std::string getClue(int cat, int val);
};

#endif // CLUEFILE_H
