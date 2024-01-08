#include <iostream>
#include <string>
#include <algorithm>

const int MARKS_SIZE = 4;

struct Student {
    std::string name;
    int marks[MARKS_SIZE];

    Student(const std::string& n, int m1, int m2, int m3, int m4) {
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        marks[3] = m4;
    }

    double averageMarks() const {
        int sum = 0;
        for (int i = 0; i < MARKS_SIZE; ++i) {
            sum += marks[i];
        }
        return static_cast<double>(sum) / MARKS_SIZE;
    }
};

bool compareStudents(const Student& s1, const Student& s2) {
    return s1.averageMarks() > s2.averageMarks();
}

Student* getTopStudent(Student* students, int count) {
    if (count <= 0) {
        return nullptr;
    }

    Student* topStudent = &students[0];
    double highestAverageMarks = students[0].averageMarks();

    for (int i = 1; i < count; ++i) {
        double currentAverageMarks = students[i].averageMarks();
        if (currentAverageMarks > highestAverageMarks) {
            highestAverageMarks = currentAverageMarks;
            topStudent = &students[i];
        }
    }

    return topStudent;
}

int countStudentsAboveAverage(Student* students, int count, double threshold) {
    int aboveThreshold = 0;
    for (int i = 0; i < count; ++i) {
        if (students[i].averageMarks() > threshold) {
            aboveThreshold++;
        }
    }
    return aboveThreshold;
}



int main() {
    const int numOfStudents = 100;
    Student students[numOfStudents] = {
            {"Alice", 80, 75, 90, 85},
            {"Bob", 70, 65, 60, 75},
            {"Charlie", 90, 85, 80, 95},
            {"David", 60, 55, 50, 45},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},
            {"Eva", 85, 90, 95, 80},


    };


    Student* topStudent = getTopStudent(students, numOfStudents);
    if (topStudent != nullptr) {
        std::cout << "Top student: " << topStudent->name << std::endl;
    }

    double threshold = 75.0;
    int countAboveThreshold = countStudentsAboveAverage(students, numOfStudents, threshold);
    std::cout << "Students with marks above " << threshold << ": " << countAboveThreshold << std::endl;

    return 0;
}

