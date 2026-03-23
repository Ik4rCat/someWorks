#include <iostream>
#include "Group.h"

using namespace std;

Group::Group() {
    name = "Unknown";
}

Group::Group(string name) {
    this->name = name;
}

string Group::getName() const {
    return name;
}

void Group::addStudent(Student student) {
    students.push_back(student);
}

void Group::addSubject(Subject subject) {
    subjects.push_back(subject);
}

int Group::getNumberOfStudents() const {
    return students.size();
}

int Group::getNumberOfSubjects() const {
    return subjects.size();
}

Student Group::getStudent(int index) const {
    return students[index];
}

Subject Group::getSubject(int index) const {
    return subjects[index];
}

double Group::getSubjectAverage(int subjectIndex) const {
    if (students.size() == 0) return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < students.size(); i++) {
        sum += students[i].getGrade(subjectIndex);
    }
    return sum / students.size();
}

double Group::getGroupAverage() const {
    if (students.size() == 0 || subjects.size() == 0) return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < students.size(); i++) {
        sum += students[i].getAverageGrade();
    }
    return sum / students.size();
}

void Group::getMinMaxGradeForSubject(int subjectIndex, int& minGrade, int& maxGrade, string& minStudent, string& maxStudent) const {
    if (students.size() == 0) return;
    
    minGrade = students[0].getGrade(subjectIndex);
    maxGrade = students[0].getGrade(subjectIndex);
    minStudent = students[0].getName();
    maxStudent = students[0].getName();
    
    for (size_t i = 1; i < students.size(); i++) {
        int grade = students[i].getGrade(subjectIndex);
        if (grade < minGrade) {
            minGrade = grade;
            minStudent = students[i].getName();
        }
        if (grade > maxGrade) {
            maxGrade = grade;
            maxStudent = students[i].getName();
        }
    }
}

void Group::displayGradeTable() const {
    cout << "\n===== GRADE TABLE =====" << endl;
    
    cout << "Student\t\t";
    for (size_t j = 0; j < subjects.size(); j++) {
        cout << subjects[j].getName() << "\t";
    }
    cout << endl;
    
    for (size_t i = 0; i < students.size(); i++) {
        cout << students[i].getName() << "\t\t";
        for (size_t j = 0; j < subjects.size(); j++) {
            cout << students[i].getGrade(j) << "\t";
        }
        cout << endl;
    }
}

void Group::displayStudentAverages() const {
    cout << "\n===== STUDENT AVERAGES =====" << endl;
    for (size_t i = 0; i < students.size(); i++) {
        cout << students[i].getName() << ": " << students[i].getAverageGrade() << endl;
    }
}

void Group::displaySubjectAverages() const {
    cout << "\n===== SUBJECT AVERAGES =====" << endl;
    for (size_t j = 0; j < subjects.size(); j++) {
        cout << subjects[j].getName() << ": " << getSubjectAverage(j) << endl;
    }
}

void Group::displayGroupAverage() const {
    cout << "\n===== GROUP AVERAGE =====" << endl;
    cout << "Group average: " << getGroupAverage() << endl;
}

void Group::displayMinMaxGrades() const {
    cout << "\n===== MIN/MAX GRADES PER SUBJECT =====" << endl;
    for (size_t j = 0; j < subjects.size(); j++) {
        int minGrade, maxGrade;
        string minStudent, maxStudent;
        getMinMaxGradeForSubject(j, minGrade, maxGrade, minStudent, maxStudent);
        cout << subjects[j].getName() << ": Min=" << minGrade << " (" << minStudent << "), Max=" << maxGrade << " (" << maxStudent << ")" << endl;
    }
}
