#include "Tasks.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    // Примеры вызова методов
   
    Tasks::generateBinaryFile("data1.bin", 20, 1, 100);
    std::cout << "Разность: " << Tasks::findDifference("data1.bin") << std::endl;

    Tasks::copyToMatrix("data1.bin", 4);

    Tasks::generateToyFile("toys.bin", 10);
    Tasks::findExpensiveToys("toys.bin", 100);
    Tasks::generateTextFile("data4.txt", 20, 1, 100);
    std::cout << "Количество вхождений максимального элемента: " << Tasks::countMaxOccurrences("data4.txt") << std::endl;

    std::cout << "Количество четных чисел: " << Tasks::countEvenNumbers("data4.txt") << std::endl;

    Tasks::filterLinesContaining("data6.txt", "output.txt", "форма");
    Tasks::viewBinaryFile("data1.bin");
    Tasks::viewToyFile("toys.bin");


    

    return 0;
}
