#include <iostream>
#include <vector>
#include <cmath>
#include <locale>

double findMax(const std::vector<double>& arr) {
    double maxElement = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

double sumBeforeLastPositive(const std::vector<double>& arr) {
    double sum = 0.0;
    bool foundPositive = false;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > 0) {
            sum = 0.0;
            foundPositive = true;
        }
        else {
            if (foundPositive) {
                sum += arr[i];
            }
        }
    }
    return sum;
}

void compressArray(std::vector<double>& arr, double a, double b) {
    size_t writeIndex = 0;
    for (size_t readIndex = 0; readIndex < arr.size(); ++readIndex) {
        if (std::abs(arr[readIndex]) < a || std::abs(arr[readIndex]) > b) {
            arr[writeIndex++] = arr[readIndex];
        }
    }

    while (writeIndex < arr.size()) {
        arr[writeIndex++] = 0.0;
    }
}

int main() {
    setlocale(LC_ALL, ""); // Встановлення локалізації

    std::vector<double> array = { 3.5, -2.0, 4.7, -1.2, 5.1, -6.8, 7.3, -8.6, 9.0 };

    double maxElement = findMax(array);
    std::cout << "Максимальний елемент у масиві: " << maxElement << std::endl;

    double sumBeforeLastPos = sumBeforeLastPositive(array);
    std::cout << "Сума елементів до останнього додатного: " << sumBeforeLastPos << std::endl;

    double a = -5.0;
    double b = 5.0;
    compressArray(array, a, b);

    std::cout << "Стиснутий масив з елементами, модуль яких не знаходиться в інтервалі [" << a << ", " << b << "]: ";
    for (const auto& elem : array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
