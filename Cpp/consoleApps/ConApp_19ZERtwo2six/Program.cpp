#include <iostream>

class Student
{
private:
    const char* name;

public:
	Student(const char* name) : name(name) {} 
    Student(Student& s); //copy
    Student(Student&& s1); //move
};

int main()
{
    
    Student Student("Tom");
    //...   
    

}