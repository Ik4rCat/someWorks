#include <iostream>
#include "Group.h"
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string studentsFile, subjectsFile, gradesFile;
    
    cout << "Enter students file name: ";
    cin >> studentsFile;
    cout << "Enter subjects file name: ";
    cin >> subjectsFile;
    cout << "Enter grades file name: ";
    cin >> gradesFile;
    
    ifstream studentsIn(studentsFile.c_str());
    ifstream subjectsIn(subjectsFile.c_str());
    ifstream gradesIn(gradesFile.c_str());
    
    if (!studentsIn.is_open() || !subjectsIn.is_open() || !gradesIn.is_open()) {
        cout << "Error opening files" << endl;
        return 1;
    }
    
    Group group("StudentGroup");
    
    vector<string> studentNames;
    string line;
    while (getline(studentsIn, line)) {
        if (line.length() > 0) {
            studentNames.push_back(line);
        }
    }
    studentsIn.close();
    
    vector<string> subjectNames;
    while (getline(subjectsIn, line)) {
        if (line.length() > 0) {
            subjectNames.push_back(line);
            group.addSubject(Subject(line));
        }
    }
    subjectsIn.close();
    
    for (size_t i = 0; i < studentNames.size(); i++) {
        Student student(studentNames[i], subjectNames.size());
        group.addStudent(student);
    }
    
    int studentIndex = 0;
    while (getline(gradesIn, line)) {
        if (line.length() == 0 || studentIndex >= group.getNumberOfStudents()) continue;
        
        stringstream ss(line);
        int grade;
        int subjectIndex = 0;
        while (ss >> grade && subjectIndex < group.getNumberOfSubjects()) {
            group.getStudent(studentIndex).setGrade(subjectIndex, grade);
            subjectIndex++;
        }
        studentIndex++;
    }
    gradesIn.close();
    
    group.displayGradeTable();
    group.displayStudentAverages();
    group.displaySubjectAverages();
    group.displayGroupAverage();
    group.displayMinMaxGrades();
    
    return 0;
}
