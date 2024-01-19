#include <cstdlib>
#include <iostream>

class DynamicIntArray
{
public:
    DynamicIntArray();

    DynamicIntArray(std::size_t size);

    DynamicIntArray(const DynamicIntArray& other);

    ~DynamicIntArray();

    DynamicIntArray& operator=(const DynamicIntArray& other);

    // Overloaded subscript operator
    int& operator[](std::size_t index);

    void setSize(std::size_t newSize);

    std::size_t getSize() const;

    void clear();

    void push_back(int element);

private:
    int* arr;
    std::size_t size;

    // Private function to copy content from one array to another
    void copyArray(const int* source, int* destination, std::size_t count);
};


DynamicIntArray::DynamicIntArray() : arr(nullptr), size(0) {}

DynamicIntArray::DynamicIntArray(std::size_t size) : arr(new int[size]), size(size) {}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : arr(nullptr), size(0) {
    copyArray(other.arr, arr, other.size);
    size = other.size;
}

DynamicIntArray::~DynamicIntArray() {
    delete[] arr;
}


DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {
    if (this != &other) {
        delete[] arr;
        arr = new int[other.size];
        copyArray(other.arr, arr, other.size);
        size = other.size;
    }
    return *this;
}

// Overloaded subscript operator implementation
int& DynamicIntArray::operator[](std::size_t index) {
    return arr[index];
}

void DynamicIntArray::setSize(std::size_t newSize) {
    int* newArr = new int[newSize];
    copyArray(arr, newArr, std::min(size, newSize));
    delete[] arr;
    arr = newArr;
    size = newSize;
}

std::size_t DynamicIntArray::getSize() const {
    return size;
}

void DynamicIntArray::clear() {
    delete[] arr;
    arr = nullptr;
    size = 0;
}

void DynamicIntArray::push_back(int element) {
    setSize(size + 1);
    arr[size - 1] = element;
}

// Private function to copy content from one array to another implementation
void DynamicIntArray::copyArray(const int* source, int* destination, std::size_t count) {
    for (std::size_t i = 0; i < count; ++i) {
        destination[i] = source[i];
    }
}

int main()
{
    DynamicIntArray myArray(5); // Creating an array with size 5

    for (std::size_t i = 0; i < myArray.getSize(); ++i) {
        myArray[i] = i * 10; // Initializing elements with multiples of 10
    }

    myArray.push_back(50);

    // Output the elements using the subscript operator
    for (std::size_t i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray[i] << " ";
    }

    return 0;
}