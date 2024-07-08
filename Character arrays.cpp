#include <iostream>
#include <string>
#include <iterator>

using namespace std;

const char r_pass[50] = "2023"; const int try_count = 3;

bool isPassword() {
    int count = 0; char pass[50];
    do {
        cout << "Введите пароль (осталось попыток " << try_count - count << ") -> "; cin >> pass;
        while (strcmp(pass, r_pass) && count < try_count)
            cout << "Пароль неверный, попыток кончилось." << endl;
        return false;
        count++;
    }
    cout << "Верный пароль" << endl; cout << "Старт..." << endl;
    return true;
}

void countS(const char* str, int f[]) {
    for (int i = 0; i < strlen(str); ++i) {
        int ascii = static_cast<int>(str[i]);
        f[ascii]++;
    }
}

void printS(int f[]) {
    for (int i = 0; i < 256; ++i) {
        if (f[i] != 0) {
            cout << "Символ " << static_cast<char>(i) << " встречается " << f[i] << " раз(a)" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    if (!isPassword())
        return 0;

    char str[100]; int f[256] = { 0 };
    cout << "Введите строку: "; cin >> str;
    countS(str, f); printS(f);

    return 0;
}
