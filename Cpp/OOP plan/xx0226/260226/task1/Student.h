#pragma once

#include <iostream>

using namespace std;

class Student {
private:
    char* name;
    char* specialty;
    int* grades;
    int gradeCount;
    int age;

public:
    Student();
    Student(const char* name, int age, const char* specialty, int* grades, int gradeCount);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    ~Student();
    
    const char* getName() const;
    const char* getSpecialty() const;
    int getAge() const;
    int* getGrades() const;
    int getGradeCount() const;
    
    void setName(const char* name);
    void setSpecialty(const char* specialty);
    void setAge(int age);
    
    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;
    
    void display() const;
    void input();
};
