#include <iostream>
#include <fstream>
#include <string>

bool prof(double num) {
    int res1;
    int res2;
    res1 = num;
    num *= 10;
    res2 = num;
    if (res2 % 10 == 0) {
        if (res1 == 2) {
            return true;
        }
        for (int i = 2; i < sqrt(res1); ++i) {
            if (res1 % i == 0) {
                return false;
            }
            return true;
        }
    }
    else {
        return false;
    }
}
void summ(std::string name1) {
    std::ofstream fileout("fileout.bin", std::ios::binary | std::ios::out);
    std::ifstream file(name1);
    double num;
    double sum = 0;
    double max;
    double result;
    bool p;
    if (file.is_open()) {
        file >> num;
        while (!file.eof()) {
            file >> num;
            max = num;
            p = prof(num);
            if (p == true) {
                sum += num;
            }
            if (num > max) {
                max = num;
            }
        }
    }
    result = max - num;
    fileout.write((char*)&result, sizeof(result));
    std::cout << sum - max << std::endl;
}


int main() {
    summ("f1.txt");
}
