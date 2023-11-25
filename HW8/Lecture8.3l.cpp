#include <iostream>
#include"Lecture8.3l.h"
int main() {
      int count = 0;
    std::cout << "Enter factorial number: ";
    std::cin >> count;
    Fact(count);
    std::cout << std::endl;


    int n;
    std::cout << "Enter the count of natural numbers to print: ";
    std::cin >> n;

    std::cout << "Descending (Loop): ";
    printNaturalNumbersDescending(n);

    std::cout << "Ascending (Loop): ";
    printNaturalNumbersAscending(n);

    return 0;



}