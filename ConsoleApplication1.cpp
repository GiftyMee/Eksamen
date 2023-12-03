#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

// Функція для знаходження мінімального елемента масиву
double findMinElement(const vector<double>& array) {
    double minElement = array[0];
    for (size_t i = 1; i < array.size(); ++i) {
        if (array[i] < minElement) {
            minElement = array[i];
        }
    }
    return minElement;
}

// Функція для знаходження індексів першого і останнього додатнього елемента
void findFirstAndLastPositive(const vector<double>& array, size_t& first, size_t& last) {
    first = -1;
    last = -1;

    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] > 0) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
}

// Функція для перетворення масиву
void transformArray(vector<double>& array) {
    sort(array.begin(), array.end(), [](double a, double b) {
        return (a == 0 && b != 0);
        });
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Введення даних
    size_t size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    vector<double> array;
    cout << "Введіть елементи масиву: ";
    for (size_t i = 0; i < size; ++i) {
        double element;
        cin >> element;
        array.push_back(element);
    }

    // Обчислення мінімального елемента
    double minElement = findMinElement(array);

    // Обчислення суми елементів між першим і останнім додатнім
    size_t firstPositive, lastPositive;
    findFirstAndLastPositive(array, firstPositive, lastPositive);
    double sumBetweenPositives = 0;
    for (size_t i = firstPositive + 1; i < lastPositive; ++i) {
        sumBetweenPositives += array[i];
    }

    // Виведення результатів
    cout << "Мінімальний елемент: " << minElement << endl;
    cout << "Сума елементів між першим і останнім додатнім: " << sumBetweenPositives << endl;

    // Перетворення масиву
    transformArray(array);

    // Виведення перетвореного масиву
    cout << "Перетворений масив: ";
    for (size_t i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
