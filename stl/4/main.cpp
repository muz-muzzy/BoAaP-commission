#include <iostream>
#include <fstream>
#include <set>
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

    std::set<int> uniqueNumbers;

    int number;
    while (inputFile >> number) {
        uniqueNumbers.insert(number);
    }

    outputFile << uniqueNumbers.size();

    inputFile.close();
    outputFile.close();

    return 0;
}