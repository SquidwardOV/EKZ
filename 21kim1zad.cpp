#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Функция для проверки, является ли число кратным 3
bool isMultipleOfThree(int num) {
    return num % 3 == 0;
}

// Функция для нахождения минимального элемента в векторе
int findMinElement(const std::vector<int>& numbers) {
    return *std::min_element(numbers.begin(), numbers.end());
}

int main() {
    std::ifstream inputFile("f1.txt");
    std::ofstream outputFile("f2.txt");

    int n;
    inputFile >> n;

    std::vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int num;
        inputFile >> num;
        numbers.push_back(num);
    }

    int minElement = findMinElement(numbers);

    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        if (numbers[i] % 3 == 0 && numbers[i] <= minElement) {
            result.push_back(numbers[i]);
        }
    }

    outputFile << result.size() << std::endl;
    for (int i = 0; i < result.size(); i++) {
        outputFile << result[i] << " ";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
