#include <iostream>
#include <vector>
#include <algorithm>

bool compareByLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

class LengthComparator {
public:
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};
unsigned int countDivisibleBy(const std::vector<int>& vec, int number) {
    return std::count_if(vec.begin(), vec.end(),
                         [number](int x) { return x % number == 0; });
}

int main() {
    std::vector<std::string> stringContainer = {"apple", "banana", "orange", "kiwi", "grape"};

    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);

    std::cout << "Sorted by length (using function): ";
    for (const std::string& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());

    std::cout << "Sorted by length (using functor): ";
    for (const std::string& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    // Сортування рядків за кількістю букв, використовуючи лямбду
    std::sort(stringContainer.begin(), stringContainer.end(),
              [](const std::string& a, const std::string& b) {
                  return a.length() < b.length();
              });

    std::cout << "Sorted by length (using lambda): ";
    for (const std::string& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<int> intVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int divisor = 3;
    unsigned int count = countDivisibleBy(intVector, divisor);

    std::cout << "Number of elements divisible by " << divisor << ": " << count << std::endl;

    return 0;
}

