#pragma once
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





// a. від найбільшого до найменшого за допомогою цикла
void printNaturalNumbersDescending(int count) {
    for (int i = count; i >= 1; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// b. від найменшого до найбільшого за допомогою цикла
void printNaturalNumbersAscending(int count) {
    for (int i = 1; i <= count; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

