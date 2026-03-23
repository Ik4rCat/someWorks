#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student() {
    name = new char[1];
    name[0] = '\0';
    specialty = new char[1];
    specialty[0] = '\0';
    grades = nullptr;
    gradeCount = 0;
    age = 0;
}

Student::Student(const char* name, int age, const char* specialty, int* grades, int gradeCount) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->age = age;
    this->specialty = new char[strlen(specialty) + 1];
    strcpy(this->specialty, specialty);
    this->gradeCount = gradeCount;
    this->grades = new int[gradeCount];
    for (int i = 0; i < gradeCount; i++) {
        this->grades[i] = grades[i];
    }
}

Student::Student(const Student& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->age = other.age;
    this->specialty = new char[strlen(other.specialty) + 1];
    strcpy(this->specialty, other.specialty);
    this->gradeCount = other.gradeCount;
    this->grades = new int[gradeCount];
    for (int i = 0; i < gradeCount; i++) {
        this->grades[i] = other.grades[i];
    }
}

Student::Student(Student&& other) noexcept {
    name = other.name;
    age = other.age;
    specialty = other.specialty;
    grades = other.grades;
    gradeCount = other.gradeCount;
    
    other.name = nullptr;
    other.specialty = nullptr;
    other.grades = nullptr;
    other.gradeCount = 0;
    other.age = 0;
}

Student::~Student() {
    delete[] name;
    delete[] specialty;
    delete[] grades;
}

const char* Student::getName() const {
    return name;
}

const char* Student::getSpecialty() const {
    return specialty;
}

int Student::getAge() const {
    return age;
}

int* Student::getGrades() const {
    return grades;
}

int Student::getGradeCount() const {
    return gradeCount;
}

void Student::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Student::setSpecialty(const char* specialty) {
    delete[] this->specialty;
    this->specialty = new char[strlen(specialty) + 1];
    strcpy(this->specialty, specialty);
}

void Student::setAge(int age) {
    this->age = age;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] name;
        delete[] specialty;
        delete[] grades;
        
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
        specialty = new char[strlen(other.specialty) + 1];
        strcpy(specialty, other.specialty);
        gradeCount = other.gradeCount;
        grades = new int[gradeCount];
        for (int i = 0; i < gradeCount; i++) {
            grades[i] = other.grades[i];
        }
    }
    return *this;
}

Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        delete[] name;
        delete[] specialty;
        delete[] grades;
        
        name = other.name;
        age = other.age;
        specialty = other.specialty;
        grades = other.grades;
        gradeCount = other.gradeCount;
        
        other.name = nullptr;
        other.specialty = nullptr;
        other.grades = nullptr;
        other.gradeCount = 0;
        other.age = 0;
    }
    return *this;
}

void Student::display() const {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Specialty: " << specialty << endl;
    cout << "Grades: ";
    for (int i = 0; i < gradeCount; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}

void Student::input() {
    char temp[100];
    
    cout << "Enter name: ";
    cin.getline(temp, 100);
    setName(temp);
    
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    
    cout << "Enter specialty: ";
    cin.getline(temp, 100);
    setSpecialty(temp);
    
    cout << "Enter number of grades: ";
    cin >> gradeCount;
    cin.ignore();
    
    delete[] grades;
    grades = new int[gradeCount];
    
    cout << "Enter grades: ";
    for (int i = 0; i < gradeCount; i++) {
        cin >> grades[i];
    }
    cin.ignore();
}
