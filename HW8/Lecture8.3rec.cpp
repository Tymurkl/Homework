#include <iostream>
#include"Lecture8.3rec.h"


int main() {


    int i = 0;
    std::cout << "Enter factorial number again: ";
    std::cin >> i;
    std::cout << Fact2(i);
    std::cout << std::endl;

    int n;

    std::cout << "Descending (Recursion): ";
    printNaturalNumbersDescendingRecursively(n);
    std::cout << std::endl;

    std::cout << "Ascending (Recursion): ";
    printNaturalNumbersAscendingRecursively(n);

    return 0;



}