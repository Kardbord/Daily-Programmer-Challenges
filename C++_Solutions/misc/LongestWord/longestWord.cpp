#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>

const std::string REGEX_PATTERN = "[^a-zA-Z_ ]";

struct WordLengthCompare {
    bool operator()(const std::string & a, const std::string & b) const {
        return (a.length() == b.length() || a.length() < b.length());
    }
};

std::vector<std::string> parseString(std::string const & s, std::string const & delimiter = " ") {
    // Remove punctuation
    std::regex e(REGEX_PATTERN);
    std::string stripped_s = std::regex_replace(s, e, "");

    // parse words via @delimiter
    std::vector<std::string> tokens;
    size_t start_pos = 0;
    size_t found_pos = 0;
    while ((found_pos = stripped_s.find(delimiter, start_pos)) != std::string::npos) {
        tokens.push_back(stripped_s.substr(start_pos, found_pos - start_pos));
        start_pos = found_pos + delimiter.length();
    }
    tokens.push_back(stripped_s.substr(start_pos, stripped_s.length() - start_pos));
    return tokens;
}

std::string longestWord(std::string sen) {
    auto words = parseString(sen);
    std::make_heap(words.begin(), words.end(), WordLengthCompare());
    return words.front();
}

void prompt() {
    std::cout << "Please provide some input: ";
}

// Asks for a string
// Strips input string of punctuation
// Outputs the longest word in the stripped string
int main() {
    prompt();

    std::string input;

    std::getline(std::cin, input);

    std::cout << longestWord(input) << std::endl;
    return EXIT_SUCCESS;

}

