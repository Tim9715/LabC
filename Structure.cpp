#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isPassword() {
    const string r_pass = "Class"; const int try_count = 3; int count = 0; string pass;
    do {
        cout << "Введите пароль (осталось попыток " << try_count - count << ") - ";
        cin >> pass;
        count++;
    } while ((pass != r_pass) && count < try_count);
    if (pass != r_pass && count == try_count) {
        cout << "Пароль неверный, попытки кончились." << endl;
        return false;
    }
    cout << "Верный пароль" << endl; cout << "Старт..." << endl;
    return true;
}

const double TARIF = 100.0; const double OVERWEIGHT_FEE = 10.0; const double NORM_WEIGHT = 20.0;

struct Ticket {
    string passengerName; int age; double baggageWeight; double ticketPrice;
};

double calculateTicketPrice(int age, double baggageWeight) {
    double price = TARIF;
    if (age < 2) {
        price *= 0.5; // Бесплатно для детей до 2 лет
    } else if (age >= 2 && age <= 12) {
        price *= 0.7; // Скидка 30% для детей от 2 до 12 лет
    }
    if (baggageWeight > NORM_WEIGHT) {
        price += (baggageWeight - NORM_WEIGHT) * OVERWEIGHT_FEE; // Доплата за перегрузку багажа
    }
    return price;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    if (isPassword()) {
        ifstream inputFile("C:\\Users\\lplay\\OneDrive\\Рабочий стол\\input.txt");
        if (!inputFile.is_open()) {
            cout << "Не удалось открыть файл для чтения." << endl;
            return 1;
        }
        int numTickets; inputFile >> numTickets; inputFile.ignore();
        vector<Ticket> tickets(numTickets); double totalBaggageWeight = 0.0;
        for (int i = 0; i < numTickets; ++i) {
            getline(inputFile, tickets[i].passengerName);
            inputFile >> tickets[i].age;
            inputFile >> tickets[i].baggageWeight;
            inputFile.ignore();
            tickets[i].ticketPrice = calculateTicketPrice(tickets[i].age, tickets[i].baggageWeight);
            totalBaggageWeight += tickets[i].baggageWeight;
        }
        inputFile.close();
        
        ofstream outputFile("C:\\Users\\lplay\\OneDrive\\Рабочий стол\\output.txt");
        if (outputFile.is_open()) {
            outputFile << "Информация о билетах:\n";
            for (int i = 0; i < numTickets; ++i) {
                outputFile << "Пассажир: " << tickets[i].passengerName << ", Возраст: " << tickets[i].age
                           << ", Вес багажа: " << tickets[i].baggageWeight << " кг, Стоимость билета: "
                           << tickets[i].ticketPrice << " рублей" << endl;
            }
            outputFile << "Итоговый вес багажа на рейсе: " << totalBaggageWeight << " кг" << endl;
            outputFile.close();
            cout << "Данные успешно записаны в файл 'output.txt'." << endl;
        } else {
            cout << "Не удалось открыть файл для записи." << endl;
        }
    }
    return 0;
}
