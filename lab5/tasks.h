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
    // ������� 1
    static void generateBinaryFile(const std::string& fileName, int count, int minVal, int maxVal);
    static int findDifference(const std::string& fileName);

    // ������� 2
    static void copyToMatrix(const std::string& fileName, int n);

    // ������� 3
    static void generateToyFile(const std::string& fileName, int count);
    static void findExpensiveToys(const std::string& fileName, double k);

    // ������� 4
    static void generateTextFile(const std::string& fileName, int count, int minVal, int maxVal);
    static int countMaxOccurrences(const std::string& fileName);

    // ������� 5
    static int countEvenNumbers(const std::string& fileName);

    // ������� 6
    static void filterLinesContaining(const std::string& inputFile, const std::string& outputFile, const std::string& substring);


    //�������� ������
    static void viewBinaryFile(const std::string& fileName);  // ��� �������� ������
    static void viewToyFile(const std::string& fileName);     // ��� ������ � ���������
};

#endif // TASKS_H
