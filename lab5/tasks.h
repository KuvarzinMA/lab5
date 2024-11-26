#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <vector>

struct Toy {
    std::string name;
    double price;
    int minAge;
    int maxAge;
};

class Tasks {
public:
    // Задание 1
    static void generateBinaryFile(const std::string& fileName, int count, int minVal, int maxVal);
    static int findDifference(const std::string& fileName);

    // Задание 2
    static void copyToMatrix(const std::string& fileName, int n);

    // Задание 3
    static void generateToyFile(const std::string& fileName, int count);
    static void findExpensiveToys(const std::string& fileName, double k);

    // Задание 4
    static void generateTextFile(const std::string& fileName, int count, int minVal, int maxVal);
    static int countMaxOccurrences(const std::string& fileName);

    // Задание 5
    static int countEvenNumbers(const std::string& fileName);

    // Задание 6
    static void filterLinesContaining(const std::string& inputFile, const std::string& outputFile, const std::string& substring);


    //просмотр файлов
    static void viewBinaryFile(const std::string& fileName);  // Для числовых файлов
    static void viewToyFile(const std::string& fileName);     // Для файлов с игрушками
};

#endif // TASKS_H
