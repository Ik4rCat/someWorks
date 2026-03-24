#pragma once

#include <iostream>
#include <vector>
#include "PrintJob.h"

using namespace std;

class PrintQueue {
private:
    vector<PrintJob*> jobs;

public:
    void addJob(PrintJob* job);
    PrintJob* getNextJob();
    bool isEmpty() const;
    int getSize() const;
    void displayQueue() const;
    void sortByPriority();
};
