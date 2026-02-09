#pragma once
#include <string>

using namespace std;

class Animal
{
    private:
        string name = "Garry";
        int age = 15;

    public: 
    void String(){
        cout << endl;
        cout << "My name is " << name << ", i'm " << age << " years old!" << endl;
    }
};
