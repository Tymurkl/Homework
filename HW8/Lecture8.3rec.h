#pragma once

}
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



// c. від найбільшого до найменшого за допомогою рекурсії
void printNaturalNumbersDescendingRecursively(int count) {
    if (count == 0) {
        return;
    }
    std::cout << count << " ";
    printNaturalNumbersDescendingRecursively(count - 1);
}

// d. від найменшого до найбільшого за допомогою рекурсії
void printNaturalNumbersAscendingRecursively(int count, int current = 1) {
    if (current > count) {
        return;
    }
    std::cout << current << " ";
    printNaturalNumbersAscendingRecursively(count, current + 1);
}

