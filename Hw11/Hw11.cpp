#include <iostream>
#include <algorithm>
using namespace std;

const int ROWS = 4;
const int COLS = 4;

bool find(int arr_2d[ROWS][COLS], int toFind) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr_2d[i][j] == toFind) {
                return true;
            }
        }
    }
    return false;
}

enum class SortingDirection {
    ascending,
    descending
};

bool isSorted(const int* arr2, int size, SortingDirection direction) {
    if (direction == SortingDirection::ascending) {
        for (int i = 0; i < size - 1; i++) {
            if (arr2[i] > arr2[i + 1])
                return false;
        }
    } else if (direction == SortingDirection::descending) {
        for (int i = 0; i < size - 1; i++) {
            if (arr2[i] < arr2[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "Task 1" << endl;
    int myArray[ROWS][COLS] = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    int searchElement;
    cout << "Enter the element you want to search for: ";
    cin >> searchElement;

    bool found = find(myArray, searchElement);

    if (found) {
        cout << "Element found in the 2D array." << endl;
    } else {
        cout << "Element not found in the 2D array." << endl;
    }

    cout << endl;
    cout << "Task 2" << endl;
    const int size = 5;
    int myArray1[size] = {1, 2, 3, 4, 5};
    int myArray2[size] = {5, 4, 3, 2, 1};

    if (isSorted(myArray1, size, SortingDirection::ascending)) {
        std::cout << "Array 1 is sorted in ascending order." << std::endl;
    } else {
        std::cout << "Array 1 is not sorted in ascending order." << std::endl;
    }

    if (isSorted(myArray2, size, SortingDirection::descending)) {
        std::cout << "Array 2 is sorted in descending order." << std::endl;
    } else {
        std::cout << "Array 2 is not sorted in descending order." << std::endl;
    }


    for (int i = ROWS - 1; i >= 0; i--) {
        for (int j = 0; j < COLS; j++) {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;


    int tempArray[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            tempArray[i][j] = myArray[ROWS - i - 1][j];
        }
    }

    // Копирование строк из временного массива обратно в исходный массив
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            myArray[i][j] = tempArray[i][j];
        }
    }

    // Вывод перевернутого массива
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



