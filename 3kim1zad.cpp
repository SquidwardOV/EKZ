#include <iostream>
#include <fstream>
#include <vector>

void removeDuplicates(std::vector<int>& arr) {
    std::vector<int> uniqueArr;
    for (int i = 0; i < arr.size(); ++i) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueArr.size(); ++j) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueArr.push_back(arr[i]);
        }
    }
    arr = uniqueArr;
}

int main() {
    // Открываем файл для чтения
    std::ifstream inputFile("f1.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл f1.txt" << std::endl;
        return 1;
    }

    int N;
    inputFile >> N; // Считываем размер массива

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> arr[i]; // Считываем элементы массива
    }

    inputFile.close();

    // Удаляем дубликаты из массива
    removeDuplicates(arr);

    // Открываем файл для записи
    std::ofstream outputFile("f2.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Не удалось открыть файл f2.txt" << std::endl;
        return 1;
    }

    // Записываем результат в новый файл
    outputFile << arr.size() << std::endl;
    for (int i = 0; i < arr.size(); ++i) {
        outputFile << arr[i] << " ";
    }

    outputFile.close();

    std::cout << "Результат успешно записан в файл f2.txt" << std::endl;

    return 0;
}
