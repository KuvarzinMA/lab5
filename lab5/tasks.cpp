#include "Tasks.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

using namespace std;

// Вспомогательный метод для генерации случайных чисел
int randomInt(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Задание 1
void Tasks::generateBinaryFile(const string& fileName, int count, int minVal, int maxVal) {
    ofstream file(fileName, ios::binary);
    for (int i = 0; i < count; ++i) {
        int num = randomInt(minVal, maxVal);
        file.write(reinterpret_cast<char*>(&num), sizeof(num));
    }
    file.close();
}

int Tasks::findDifference(const string& fileName) {
    ifstream file(fileName, ios::binary);
    int maxVal = INT_MIN, minVal = INT_MAX, num;
    while (file.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        maxVal = max(maxVal, num);
        minVal = min(minVal, num);
    }
    file.close();
    return maxVal - minVal;
}

// Задание 2
void Tasks::copyToMatrix(const string& fileName, int n) {
    ifstream file(fileName, ios::binary);
    vector<int> data;
    int num;
    while (file.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        data.push_back(num);
    }
    file.close();

    // Формируем квадратную матрицу
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int maxVal = INT_MIN;
    size_t index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (index < data.size()) {
                matrix[i][j] = data[index++];
                maxVal = max(maxVal, matrix[i][j]);
            }
        }
    }

    // Заменяем максимальные значения на 0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == maxVal) {
                matrix[i][j] = 0;
            }
        }
    }

    // Вывод матрицы
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Задание 3
void Tasks::generateToyFile(const string& fileName, int count) {
    ofstream file(fileName, ios::binary);
    for (int i = 0; i < count; ++i) {
        Toy toy = { "Toy" + to_string(i + 1), randomInt(100, 1000), randomInt(1, 3), randomInt(4, 12) };
        size_t nameLength = toy.name.size();
        file.write(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        file.write(toy.name.data(), nameLength);
        file.write(reinterpret_cast<char*>(&toy.price), sizeof(toy.price));
        file.write(reinterpret_cast<char*>(&toy.minAge), sizeof(toy.minAge));
        file.write(reinterpret_cast<char*>(&toy.maxAge), sizeof(toy.maxAge));
    }
    file.close();
}

void Tasks::findExpensiveToys(const string& fileName, double k) {
    ifstream file(fileName, ios::binary);
    vector<Toy> toys;
    size_t nameLength;
    double maxPrice = 0;

    while (file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength))) {
        string name(nameLength, '\0');
        file.read(&name[0], nameLength);
        double price;
        int minAge, maxAge;
        file.read(reinterpret_cast<char*>(&price), sizeof(price));
        file.read(reinterpret_cast<char*>(&minAge), sizeof(minAge));
        file.read(reinterpret_cast<char*>(&maxAge), sizeof(maxAge));
        toys.push_back({ name, price, minAge, maxAge });
        maxPrice = max(maxPrice, price);
    }
    file.close();

    for (const auto& t : toys) {
        if (maxPrice - t.price <= k) {
            cout << t.name << endl;
        }
    }
}


// Задание 4
void Tasks::generateTextFile(const string& fileName, int count, int minVal, int maxVal) {
    ofstream file(fileName);
    for (int i = 0; i < count; ++i) {
        file << randomInt(minVal, maxVal) << endl;
    }
    file.close();
}

int Tasks::countMaxOccurrences(const string& fileName) {
    ifstream file(fileName);
    int maxVal = INT_MIN, count = 0, num;
    vector<int> numbers;

    while (file >> num) {
        numbers.push_back(num);
        maxVal = max(maxVal, num);
    }
    file.close();

    for (int val : numbers) {
        if (val == maxVal) {
            ++count;
        }
    }
    return count;
}

// Задание 5
int Tasks::countEvenNumbers(const string& fileName) {
    ifstream file(fileName);
    int num, count = 0;

    while (file >> num) {
        if (num % 2 == 0) {
            ++count;
        }
    }
    file.close();
    return count;
}

// Задание 6
void Tasks::filterLinesContaining(const string& inputFile, const string& outputFile, const string& substring) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    string line;

    while (getline(inFile, line)) {
        if (line.find(substring) != string::npos) {
            outFile << line << endl;
        }
    }
    inFile.close();
    outFile.close();
}
// просмотр файлов
void Tasks::viewBinaryFile(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл " << fileName << " для просмотра." << std::endl;
        return;
    }

    std::cout << "Содержимое бинарного файла \"" << fileName << "\":" << std::endl;
    int value;
    while (file.read(reinterpret_cast<char*>(&value), sizeof(value))) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    file.close();
}

// Метод для просмотра файлов с игрушками
void Tasks::viewToyFile(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл \"" << fileName << "\" для просмотра." << std::endl;
        return;
    }

    std::cout << "Содержимое файла игрушек \"" << fileName << "\":" << std::endl;

    size_t nameLength;  // Длина имени
    while (file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength))) {
        // Считываем имя игрушки
        std::string name(nameLength, '\0');
        file.read(&name[0], nameLength);

        // Считываем остальные поля структуры
        double price;
        int minAge, maxAge;
        file.read(reinterpret_cast<char*>(&price), sizeof(price));
        file.read(reinterpret_cast<char*>(&minAge), sizeof(minAge));
        file.read(reinterpret_cast<char*>(&maxAge), sizeof(maxAge));

        // Вывод данных на экран
        std::cout << "Название: " << name
            << ", Цена: " << price
            << ", Возраст: " << minAge << "-" << maxAge
            << std::endl;
    }

    file.close();
}
