#include <iostream>
using namespace std;

bool lS2D(const int arr[][3], int rows, int cols, int target) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}
enum class SortingDirection{
    ascending,
    descending
};
bool isSorted(const int* arr2, int size, SortingDirection direction) {
    if (direction == SortingDirection::ascending) {
        for (int i = 0; i < size - 1; i++) {
            if (arr2[i] > arr2[i + 1])
                return false;
            }

        }
        else if (direction == SortingDirection::descending) {
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
    const int rows = 3;
    const int cols = 3;
    int myArray[rows][cols] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    int searchElement;
    std::cout << "Enter the element you want to search for: ";
    std::cin >> searchElement;

    bool found = lS2D(myArray, rows, cols, searchElement);

    if (found) {
        std::cout << "Element found in the 2D array." << std::endl;
    } else {
        std::cout << "Element not found in the 2D array." << std::endl;
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
    const int ROWS = 4;
    const int COLS = 4;
    const int myarray[ROWS][COLS] = {{1,  2,  3,  4},
                                     {5,  6,  7,  8},
                                     {9,  10, 11, 12},
                                     {13, 14, 15, 16}};

    for (int i = 0; i < ROWS; i++) {
        for (int j = COLS - 1; j >= 0; j--) {
            cout << myarray[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    for (int i = ROWS - 1; i >= 0; i--) {
        for (int j = 0; j < COLS; j++) {
            cout << myarray[i][j] << " ";

        }
        cout << endl;
    }
}


