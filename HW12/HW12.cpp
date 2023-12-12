#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;

enum class SortingDirection {
    ByRows,
    ByColumns
};

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[left + (right - left) / 2];
        int i = left;
        int j = right;

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        quicksort(arr, left, j);
        quicksort(arr, i, right);
    }
}

void sort(int arr[ROWS][COLUMNS], SortingDirection sortingDirection) {
    if (sortingDirection == SortingDirection::ByRows) {
        for (int i = 0; i < ROWS; i++) {
            quicksort(arr[i], 0, COLUMNS - 1);
        }
    } else {
        for (int i = 0; i < COLUMNS; ++i) {
            int column[ROWS];
            for (int j = 0; j < ROWS; ++j) {
                column[j] = arr[j][i];
            }
            quicksort(column, 0, ROWS - 1);
            for (int j = 0; j < ROWS; ++j) {
                arr[j][i] = column[j];
            }
        }
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    const int size = 5;
    int myArr[size] = {4, 16, 45, 26, 3};
    bubbleSort(myArr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << myArr[i] << " ";
    }
    cout << endl;

    int arr[ROWS][COLUMNS] = {
            {9, 7, 1},
            {10, 8, 2},
            {4, 3,5 }
    };

    sort(arr, SortingDirection::ByRows);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    sort(arr, SortingDirection::ByColumns);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}