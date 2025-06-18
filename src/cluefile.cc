#include "cluefile.h"


ClueFile::ClueFile() {
    // Parses a JSON file from which we can pull category names and clues (and in the future, answers).
    std::ifstream file("categories.json");
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
