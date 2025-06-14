#include "cluefile.h"


ClueFile::ClueFile() {
    std::ifstream file("categories.json");
    j = json::parse(file);
}

std::string ClueFile::getCategory(int cat) {
    return j["categories"][cat]["name"];
}

std::string ClueFile::getClue(int cat, int val) {
    return j["categories"][cat]["clues"][val]["clue"];
}
