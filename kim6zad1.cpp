#include <iostream>
#include <fstream>
#include <vector>

void rearrangeArray(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cout << "Failed to open input file." << std::endl;
        return;
    }

    std::vector<int> positiveNumbers;
    std::vector<int> negativeNumbers;

    int n;
    inputFile >> n;

    int num;
    for (int i = 0; i < n; i++) {
        inputFile >> num;
        if (num >= 0) {
            positiveNumbers.push_back(num);
        }
        else {
            negativeNumbers.push_back(num);
        }
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cout << "Failed to open output file." << std::endl;
        return;
    }

    for (const int& num : positiveNumbers) {
        outputFile << num << " ";
    }

    for (const int& num : negativeNumbers) {
        outputFile << num << " ";
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFileName = "f1.txt";
    std::string outputFileName = "f2.txt";

    rearrangeArray(inputFileName, outputFileName);

    std::cout << "Array rearranged successfully." << std::endl;

    return 0;
}

