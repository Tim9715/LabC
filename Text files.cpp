#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool isPassword() {
    const char r_pass[10] = "Class"; const int try_count = 3; int count = 0; char pass[10];
    do {
        std::cout << "Введите пароль (осталось попыток " << try_count - count << ") - "; std::cin >> pass;
        count++;
    } while (strcmp(pass, r_pass)) and count < try_count);
    if (strcmp(pass, r_pass) and count == try_count) {
        std::cout << "Пароль неверный, попытки кончились." << endl;
        return false;
    }
    std::cout << "Верный пароль" << endl; std::cout << "Старт..." << endl;
    return true;
}

bool Q(const std::string& word) {
    int vowels = 0; int digits = 0;
    for (char c : word) {
        if (std::isalpha(c) && (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')) {
            vowels++;
        } else if (std::isdigit(c)) {
            digits++;
        }
    }
    return vowels > digits;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    if (isPassword()) {
        std::ifstream inputFile("C:\\Users\\lplay\\OneDrive\\Рабочий стол\\input.txt");
        std::ofstream outputFile("C:\\Users\\lplay\\OneDrive\\Рабочий стол\\output.txt");
        std::string word;
        while (inputFile >> word) {
            if (Q(word)) {
                outputFile << word << std::endl;
            }
        }
        inputFile.close();
        outputFile.close();
    }
    return 0;
}
