#include <iostream>
#include <cmath>

class Vector2d {
private:
    float x;
    float y;
    static int activeInstances; // Counter for active instances

public:
    // Constructors
    Vector2d() : x(0.0f), y(0.0f) {
        activeInstances++;
    }

    Vector2d(float xVal, float yVal) : x(xVal), y(yVal) {
        activeInstances++;
    }

    // Destructor
    ~Vector2d() {
        activeInstances--;
    }


    Vector2d& operator=(const Vector2d& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }


    Vector2d operator+(const Vector2d& secondVector) const {
        return Vector2d(x + secondVector.x, y + secondVector.y);
    }


    Vector2d operator-(const Vector2d& secondVector) const {
        return Vector2d(x - secondVector.x, y - secondVector.y);
    }

    // Friend functions for addition and subtraction
    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);


    float operator()() const {
        return std::sqrt(x * x + y * y);
    }


    float& operator[](int i) {
        if (i == 0) {
            return x;
        } else if (i == 1) {
            return y;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }


    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector) {
        os << "{" << vector.x << "; " << vector.y << "}";
        return os;
    }


    friend std::istream& operator>>(std::istream& is, Vector2d& vector) {
        is >> vector.x >> vector.y;
        return is;
    }


    static int getActiveInstances() {
        return activeInstances;
    }
};


int Vector2d::activeInstances = 0;


Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

int main() {
    Vector2d testVec1{1.2, 5.6};
    Vector2d testVec2{3.4, 7.8};

    std::cout << "Vector 1: " << testVec1 << std::endl;
    std::cout << "Vector 2: " << testVec2 << std::endl;

    Vector2d resultAdd = testVec1 + testVec2;
    Vector2d resultSub = testVec1 - testVec2;

    std::cout << "Result of addition: " << resultAdd << std::endl;
    std::cout << "Result of subtraction: " << resultSub << std::endl;

    std::cout << "Length of Vector 1: " << testVec1() << std::endl;

    std::cout << "Enter a vector in the format x y: ";
    Vector2d userInput;
    std::cin >> userInput;

    std::cout << "You entered: " << userInput << std::endl;

    std::cout << "Number of active instances: " << Vector2d::getActiveInstances() << std::endl;

    return 0;
}
