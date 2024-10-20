#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "cannot open input.txt" << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "cannot open output.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> words;

    std::string word;
    while (inputFile >> word) {
        words.push_back(word);
    }

    auto firstWord = *std::min_element(words.begin(), words.end(),
        [](const std::string& a, const std::string& b) {
            return a < b;
        });
    
    auto lastWord = *std::max_element(words.begin(), words.end(),
        [](const std::string& a, const std::string& b) {
            return a < b;
        });

    size_t firstIndex = std::find(words.begin(), words.end(), firstWord) - words.begin();
    size_t lastIndex = std::find(words.begin(), words.end(), lastWord) - words.begin();

    std::swap(words[firstIndex], words[lastIndex]);

    for (const auto& w : words) {
        outputFile << w << " ";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}