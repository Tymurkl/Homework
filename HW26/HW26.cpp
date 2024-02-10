#include <iostream>
#include <cmath>

enum class VectorRelativeState {
    Identical,
    CoDirected,
    OppositeDirected,
    AcuteAngle,
    ObtuseAngle,
    RightAngle
};

class Vector2d {
private:
    float x, y;

public:
    Vector2d() : x(0.0f), y(0.0f) {}
    Vector2d(float x, float y) : x(x), y(y) {}

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

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);

    float operator()() const {
        return std::sqrt(x * x + y * y);
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector) {
        os << "{" << vector.x << "; " << vector.y << "}";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector2d& vector) {
        is >> vector.x >> vector.y;
        return is;
    }

    static int activeInstances;

    static int getActiveInstances() {
        return activeInstances;
    }

    ~Vector2d() {
        activeInstances--;
    }

    Vector2d(float x0, float y0, float x1, float y1)
            : x(x1 - x0), y(y1 - y0) {}

    float dotProduct(const Vector2d& other) const {
        return x * other.x + y * other.y;
    }

    Vector2d negate() const {
        return Vector2d(-x, -y);
    }

    VectorRelativeState getRelativeState(const Vector2d& other) const {
        float dotProd = dotProduct(other);
        float mag1 = (*this)();
        float mag2 = other();

        if (dotProd == 0.0f) {
            return VectorRelativeState::RightAngle;
        } else if (dotProd == mag1 * mag2) {
            return VectorRelativeState::CoDirected;
        } else if (dotProd == -mag1 * mag2) {
            return VectorRelativeState::OppositeDirected;
        } else if (dotProd > 0) {
            return VectorRelativeState::AcuteAngle;
        } else {
            return VectorRelativeState::ObtuseAngle;
        }
    }

    void scale(float factorX, float factorY) {
        x *= factorX;
        y *= factorY;
    }
};

int Vector2d::activeInstances = 0;

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.getX() + rightVector.getX(), leftVector.getY() + rightVector.getY());
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.getX() - rightVector.getX(), leftVector.getY() - rightVector.getY());
}

class Vector3d : public Vector2d {
public:
    Vector3d(float x, float y, float z) : Vector2d(x, y), z(z) {}

    Vector3d crossProduct(const Vector3d& other) const {
        float resultX = getY() * other.z - z * other.getY();
        float resultY = z * other.getX() - getX() * other.z;
        float resultZ = getX() * other.getY() - getY() * other.getX();

        return Vector3d(resultX, resultY, resultZ);
    }

    float getZ() const {
        return z;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3d& vector) {
        os << "{" << vector.getX() << "; " << vector.getY() << "; " << vector.getZ() << "}";
        return os;
    }

private:
    float z;
};

int main() {
    Vector2d v1(1.2, 5.6);
    Vector2d v2(2.5, 3.0);

    std::cout << "Vector 1: {" << v1.getX() << "; " << v1.getY() << "}" << std::endl;
    std::cout << "Vector 2: {" << v2.getX() << "; " << v2.getY() << "}" << std::endl;

    Vector2d v3 = v1 + v2;
    std::cout << "Vector 3 (v1 + v2): {" << v3.getX() << "; " << v3.getY() << "}" << std::endl;

    std::cout << "Magnitude of v3: " << v3() << std::endl;

    Vector3d v4(1.0, 2.0, 3.0);
    Vector3d v5(4.0, 5.0, 6.0);

    std::cout << "Vector 4: {" << v4.getX() << "; " << v4.getY() << "; " << v4.getZ() << "}" << std::endl;
    std::cout << "Vector 5: {" << v5.getX() << "; " << v5.getY() << "; " << v5.getZ() << "}" << std::endl;

    Vector3d v6 = v4.crossProduct(v5);
    std::cout << "Vector 6 (v4 x v5): {" << v6.getX() << "; " << v6.getY() << "; " << v6.getZ() << "}" << std::endl;

    return 0;
}
