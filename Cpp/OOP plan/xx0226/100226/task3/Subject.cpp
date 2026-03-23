#include <iostream>
#include "Subject.h"

Subject::Subject() {
    name = "Unknown";
}

Subject::Subject(string name) {
    this->name = name;
}

string Subject::getName() const {
    return name;
}

void Subject::setName(string name) {
    this->name = name;
}