#include <iostream>
using namespace std;
void swap (int &a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void swap2 (int* a, int* b){
    int temp = *a;
    *a=*b;
    *b= temp;
}

bool calculateSum(const double* arr, int arrSize, double& sum){
    if (arrSize <= 0) {
        return false;
    }

    sum = 0.0;
    for (int i = 0; i < arrSize; ++i) {
        sum += arr[i];
    }

    return true;
}

bool find(const int* arr, int size, int elem) {
    const int* endPtr = arr + size;

    for (const int* ptr = arr; ptr < endPtr; ++ptr) {
        if (*ptr == elem) {
            return true;
        }
    }

    return false;
}

int main(){
    cout<<"Task 1"<<endl;
    int a;
    int b;
    cout<<"enter a: ";
    cin>>a;
    cout<<"enter b: ";
    cin>>b;
    int* prA= &a;
    int* prB= &b;
    cout << "Before swap using pointers: " << *prA << " " << *prB << endl;
    swap2(prA, prB);
    cout << "After swap using pointers: " << *prA << " " << *prB <<endl;

    int x , y;
    cout<<"enter x: ";
    cin>>x;
    cout<<"enter y: ";
    cin>>y;
    cout << "Before swap using references: " << x << " " << y <<endl;
    swap(x, y);
    cout << "After swap using references: " << x << " " << y << endl;


    cout<<"Task2"<<endl;
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Invalid array size." << std::endl;
        return 1;
    }

    double* myArray = new double[size];

    std::cout << "Enter " << size << " elements for the array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> myArray[i];
    }

    double result = 0.0;
    bool success = calculateSum(myArray, size, result);

    if (success) {
        std::cout << "Sum of elements: " << result << std::endl;
    } else {
        std::cout << "Array size is invalid." << std::endl;
    }

    delete[] myArray;

    cout<<"Task2"<<endl;
    const int size1 = 5;
    int num = 0;
    int myArray2[size1] = {5, 7, 1, 3, 9 };
    cout << "Which number in array you want to find?" << endl;
    cout << "Enter this number: ";
    cin >> num;
    bool found = find(myArray2, size1, num);
    if (found) {
        std::cout << "Element found in the array." << std::endl;
    }
    else {
        std::cout << "Element not found in the array." << std::endl;
    }
}
