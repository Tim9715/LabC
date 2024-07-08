#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char r_pass[50] = "Class"; const int try_count = 3;

bool isPassword() {
    int count = 0; char pass[50];
    do {
        cout << "Введите пароль (осталось попыток " << try_count - count << ") -> "; cin >> pass;
        if (cin.getline(pass, sizeof(pass))) {
            if (!strcmp(pass, r_pass)) {
                cout << "Пароль неверный" << endl;
                return false;
            }
            count++;
        }
    } while (strcmp(pass, r_pass) && count < try_count);

    if (!strcmp(pass, r_pass)) {
        cout << "Верный пароль" << endl; cout << "Старт..." << endl;
        return true;
    }
    return false;
}

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

std::vector<std::string> splitWords(const std::string& input) {
    std::vector<std::string> words;
    std::string word;
    for (size_t i = 0; i < input.length(); ++i) {
        if (isalpha(input[i])) {
            word += input[i];
        } else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

void processWords(const std::vector<std::string>& words, const std::string& subword) {
    int count = 0; bool foundConsonantWord = false;
    for (size_t i = 0; i < words.size(); ++i) {
        if (std::isupper(words[i][0]) && words[i].substr(words[i].length() - 2) == subword) {
            cout << "Слово с подстрокой в конце: " << words[i] << endl;
            count++;
        }
        bool hasConsonants = false;
        for (char c : words[i]) {
            if (isalpha(c) && !isVowel(c)) {
                hasConsonants = true;
                foundConsonantWord = true;
                break;
            }
        }
    }
    if (foundConsonantWord) {
        cout << "Порядковый номер слова с согласными латинскими буквами: " << count << endl;
    }
    if (foundConsonantWord) {
        cout << "Количество слов с согласными латинскими буквами: " << count << endl;
    } else {
        cout << "Слов с согласными латинскими буквами не найдено." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    if (isPassword()) {
        std::string input;
        cout << "Введите строку: ";
        std::getline(std::cin, input);

        std::string subword;
        cout << "Введите двубуквенную подстроку: ";
        std::cin >> subword;

        std::vector<std::string> words = splitWords(input);
        processWords(words, subword);
    }
    return 0;
}
