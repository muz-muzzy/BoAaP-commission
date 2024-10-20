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

    std::vector<int> numbers;

    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    for (const auto& num : numbers) {
        outputFile << num << " ";
    }

    std::reverse(numbers.begin(), numbers.end());
    
    for (const auto& num : numbers) {
        outputFile << num << " ";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}