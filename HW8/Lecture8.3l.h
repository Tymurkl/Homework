#pragma
#include <iostream>
#include <sstream>

std::string getNaturalNumbersDescending(int count) {
    std::stringstream result;

    for (int i = count; i >= 1; --i) {
        result << i << " ";
    }

    return result.str();
}

std::string getNaturalNumbersAscending(int count) {
    std::stringstream result;

    for (int i = 1; i <= count; ++i) {
        result << i << " ";
    }

    return result.str();
}
