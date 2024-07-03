#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>

using namespace std;
const int min_ar = -100, max_ar = 100, try_count = 3, r_pass = 2923;

bool isPassword() {
    cout << "Введите пароль: ";
    int count = 0, pass;
    do {
        cout << "Введите пароль (осталось попыток " << try_count - count << "): "; cin >> pass; count++;
    } while (pass != r_pass && count < try_count);
    if (pass != r_pass && count == try_count) {
        cout << "Неверный пароль, попытки кончились." << endl;
        system("pause");
        return false;
    }
    cout << "Верно! Старт..." << endl;
    return true;
}

// Функция заполнения массива с клавиатуры
int* getArray(const int N) {
    int* mas = new int[N];
    cout << "Вводите массив А: " << endl;
    if (mas == NULL) {
        return NULL;
    }
    for (int i = 0; i < N; i++) {
        if (mas == NULL) {
            return NULL;
        }
        cout << "item[" << i << "]=";
        cin >> mas[i];
    }
    return mas;
}

// Функция рандомного заполнения массива
int* getRandomArray(const int N) {
    int* mas = new int[N];
    srand(time(NULL));
    if (mas == NULL) {
        return NULL;
    }
    for (int i = 0; i < N; i++) {
        mas[i] = rand() % (abs(max_ar - min_ar) + 1) + min_ar;
    }
    return mas;
}

// Функция вывода массива
void printArray(int* mas, int n) {
    for (int i = 0; i < n; i++) {
        cout << "item[" << i << "]=" << mas[i] << endl;
    }
}

// Функция для вычисления среднего арифметического элементов массива
double calculateAverage(int arr[], int size) {
    double sum = arr[0];
    for (int i = 1; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

// Функция для удаления элементов массива, меньших среднего
int filterArray(int A[], int size, double average, double B[]) {
    int idxB = 0;
    for (int i = 0; i < size; ++i) {
        if (A[i] >= average) {
            B[idxB] = A[i];
            idxB++;
        }
    }
    return idxB;
}

// Функция для сортировки массива методом выбора
void selectionSort(double arr[], int size) {
    int min_idx;
    for (int i = 0; i < size - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            double temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    // Проверка пароля
    if (isPassword()) {
        int size;
        int* A = NULL;
        int* mas = NULL;

        // Указание размера массива А
        cout << "Размер массива А" << endl;
        while (!(cin >> size) || size <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод! Введите положительное целое число: ";
        }

        // Выбор способа заполнения массива А и ввод
        cout << "Выберите способ создания массива (1 - рандом; 2 - с клавиатуры): ";
        int inputMethod;
        cin >> inputMethod;
        if (inputMethod == 1) {
            A = getRandomArray(size);
        } else {
            A = getArray(size);
        }
        if (A == NULL) {
            cout << "Ошибка создания массива" << endl;
            system("pause");
            return 1;
        }
        cout << "Массив А: " << endl;
        printArray(A, size);

        // Среднее арифметическое массива А
        cout << "............................................................." << endl;
        cout << "............................................................." << endl;
        double average = calculateAverage(A, size); // Подсчёт Ср. Ариметического массива А
        double* B = new double[size]; // Выделение памяти для массива В

        int idxB = filterArray(A, size, average, B); // Удаление элементов, меньших среднего
        selectionSort(B, idxB); // Сортировка массива В

        // Вывод результатов
        cout << "Среднее арифметическое элементов массива А: СА = " << average << std::endl;
        cout << "Массив В после удаления элементов и сортировки: ";
        for (int i = 0; i < idxB; ++i) {
            cout << "B[" << i << "]=" << B[i] << endl;
        }

        delete[] B; // Освобождение памяти массива В
    }
    return 0;
}
