#include <iostream>
#include "Student.h"

Student::Student() {
    name = "Unknown";
}

Student::Student(string name, int numSubjects) {
    this->name = name;
    for (int i = 0; i < numSubjects; i++) {
        grades.push_back(0);
    }
}

string Student::getName() const {
    return name;
}

vector<int> Student::getGrades() const {
    return grades;
}

int Student::getGrade(int index) const {
    return grades[index];
}

void Student::setGrade(int index, int grade) {
    grades[index] = grade;
}

double Student::getAverageGrade() const {
    if (grades.size() == 0) return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < grades.size(); i++) {
        sum += grades[i];
    }
    return sum / grades.size();
}

void Student::setName(string name) {
    this->name = name;
}
