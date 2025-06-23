#include "cluefile.h"


ClueFile::ClueFile() {
    // Parses a JSON file from which we can pull category names and clues (and in the future, answers).
    std::ifstream file("categories.json");
    j = json::parse(file);
}

ClueFile::ClueFile(std::string path) {
    std::ifstream file(path);
    j = json::parse(file);
}

std::string ClueFile::getCategory(int cat) {
    // Returns a given category name
    return j["categories"][cat]["name"];
}

std::string ClueFile::getClue(int cat, int val) {
    // Returns clue text for a given clue
    return j["categories"][cat]["clues"][val]["clue"];
}

bool ClueFile::isFileValid() {
    std::string name;
    std::string clue;
    try {
        for (int i = 0; i < 6; ++i) {
            name = j["categories"][i]["name"];
            for (int k = 0; k<5; ++k) {
                clue = j["categories"][i]["clues"][k]["clue"];
            }
        }
    }
    catch (...) {
        return false;
    }
    return true;
}
