#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

struct Point {
    int x;
    int y;
};

void printQuadrant(int x, int y) {
    if (x > 0 && y > 0) {
        std::cout << "Точка (" << x << ", " << y << ") расположена в первом координатном углу." << std::endl;
    }
    else if (x < 0 && y > 0) {
        std::cout << "Точка (" << x << ", " << y << ") расположена во втором координатном углу." << std::endl;
    }
    else if (x < 0 && y < 0) {
        std::cout << "Точка (" << x << ", " << y << ") расположена в третьем координатном углу." << std::endl;
    }
    else if (x > 0 && y < 0) {
        std::cout << "Точка (" << x << ", " << y << ") расположена в четвертом координатном углу." << std::endl;
    }
    else {
        std::cout << "Точка (" << x << ", " << y << ") расположена на координатной оси или в начале координат." << std::endl;
    }
}

std::vector<Point> readPointsFromFile(std::string filename) {
    std::vector<Point> points;
    std::ifstream file(filename);

    if (file.is_open()) {
        int N;
        file >> N;

        for (int i = 0; i < N; i++) {
            Point point;
            file >> point.x >> point.y;
            points.push_back(point);
        }

        file.close();
    }
    else {
        std::cout << "Не удалось открыть файл " << filename << std::endl;
    }

    return points;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<Point> points = readPointsFromFile("f1.txt");

    for (const Point& point : points) {
        printQuadrant(point.x, point.y);
    }

    return 0;
}
