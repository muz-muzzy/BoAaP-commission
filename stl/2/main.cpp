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

    std::sort(words.begin(), words.end());
    std::reverse(words.begin(), words.end());
    for (const auto& w : words) {
        outputFile << w << " ";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}