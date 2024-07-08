#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n, m, i, j;

    cout << "Введите количество строк: "; cin >> n;
    cout << "Введите количество столбцов: "; cin >> m;
    cout << endl;

    int** a = new int* [n];
    for (i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand() % 201;
        }
    }

    double* mass = new double[m];
    for (int j = 0; j < m; j++) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i][j];
        }
        mass[j] = sum / n;
    }

    double maxMass = mass[0];
    int maxI = 0;
    for (int j = 1; j < m; j++) {
        if (mass[j] > maxMass) {
            maxMass = mass[j];
            maxI = j;
        }
    }

    cout << "Матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "a[" << i << "][" << j << "]=" << setw(4) << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Одномерный массив средних арифметических по столбцам:" << endl;
    for (int j = 0; j < m; j++) {
        cout << mass[j] << "\t";
    }

    cout << endl;

    cout << "Столбец с максимальным средним арифметическим: " << maxI + 1 << endl;

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    delete[] mass;

    return 0;
}
