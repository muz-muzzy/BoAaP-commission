#include <iostream>
#include <fstream>
#include <map>
#include <vector>

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

    std::map<int, int> frequencyMap;

    int num;
    while (inputFile >> num) {
        frequencyMap[num]++;
    }

    for (const auto& pair : frequencyMap) {
        outputFile << pair.first << " " << pair.second << "\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}