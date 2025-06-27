#include "cluefile.h"

ClueFile::ClueFile(std::string path) {
    // Parses a JSON file from a given path.
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

std::vector<std::string> ClueFile::getAnswers(int cat, int val) {
    return j["categories"][cat]["clues"][val]["answers"];
}

bool ClueFile::isFileValid() {
    // Checks validity of JSON file; ie it has 6 categories of 5 clues each in the proper format
    std::string name;
    std::string clue;
    std::vector<std::string> answers;
    try {
        for (int i = 0; i < 6; ++i) {
            name = j["categories"][i]["name"];
            for (int k = 0; k<5; ++k) {
                clue = j["categories"][i]["clues"][k]["clue"];
                answers = j["categories"][i]["clues"][k]["answers"];
            }
        }
    }
    catch (...) {
        return false;
    }
    return true;
}
