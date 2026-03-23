#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Subject.h"

using namespace std;

class Group {
private:
    string name;
    vector<Student> students;
    vector<Subject> subjects;

public:
    Group();
    Group(string name);
    string getName() const;
    void addStudent(Student student);
    void addSubject(Subject subject);
    int getNumberOfStudents() const;
    int getNumberOfSubjects() const;
    Student getStudent(int index) const;
    Subject getSubject(int index) const;
    double getSubjectAverage(int subjectIndex) const;
    double getGroupAverage() const;
    void getMinMaxGradeForSubject(int subjectIndex, int& minGrade, int& maxGrade, string& minStudent, string& maxStudent) const;
    void displayGradeTable() const;
    void displayStudentAverages() const;
    void displaySubjectAverages() const;
    void displayGroupAverage() const;
    void displayMinMaxGrades() const;
};
