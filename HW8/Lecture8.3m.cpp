#include <iostream>
void countNumbers(int n) {
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;
    int number;

    std::cout << "Enter " << n << " numbers: ";

    for (int i = 0; i < n; ++i) {
        std::cin >> number;

        if (number > 0) {
            positiveCount++;
        }
        else if (number < 0) {
            negativeCount++;
        }
        else {
            zeroCount++;
        }
    }

    std::cout << "Positive: " << positiveCount << ", negative: " << negativeCount << ", zeroes: " << zeroCount << std::endl;
}
int main() {
    int c;
    std::cout << "Enter the count of numbers: ";
    std::cin >> c;

    countNumbers(c);

    std::cout << std::endl;
}