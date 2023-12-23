#include <iostream>
#include"Lecture8.3l.h"

void Fact(int count) {
    unsigned int sumi = 1;
    unsigned int i = 1;
    while (i <= count)
    {
        sumi = sumi * i;
        i++;
    }
    std::cout << sumi;
    std::cout << std::endl;
}

int main() {
      int count = 0;
    std::cout << "Enter factorial number: ";
    std::cin >> count;
    Fact(count);
    std::cout << std::endl;


    int n;
    std::cout << "Enter the count of natural numbers to print: ";
    std::cin >> n;

    std::string descending = getNaturalNumbersDescending(5);
    std::string ascending = getNaturalNumbersAscending(5);

    std::cout << "Descending: " << descending << std::endl;
    std::cout << "Ascending: " << ascending << std::endl;
    return 0;



}
