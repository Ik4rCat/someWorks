#pragma once

#include <iostream>
#include <string>

using namespace std;

class Subject {
private:
    string name;

public:
    Subject();
    Subject(string name);
    string getName() const;
    void setName(string name);
};
