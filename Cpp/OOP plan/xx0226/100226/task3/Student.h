#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Subject.h"

using namespace std;

class Student {
private:
    string name;
    vector<int> grades;

public:
    Student();
    Student(string name, int numSubjects);
    string getName() const;
    vector<int> getGrades() const;
    int getGrade(int index) const;
    void setGrade(int index, int grade);
    double getAverageGrade() const;
    void setName(string name);
};
