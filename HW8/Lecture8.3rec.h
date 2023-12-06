#pragma once
#include <iostream>
int Fact2(int b) {
    if (b == 0)
    {
        return 0;
    }
    if (b == 1)
    {
        return 1;
    }
    return b * Fact2(b - 1);

}

void printNaturalNumbersDescendingRecursively(int count) {
    if (count == 0) {
        return;
    }
    std::cout << count << " ";
    printNaturalNumbersDescendingRecursively(count - 1);
}

void printNaturalNumbersAscendingRecursively(int count) {
    if (count > 0) {
        printNaturalNumbersAscendingRecursively(count - 1);
        std::cout << (count) << " ";
    }
}