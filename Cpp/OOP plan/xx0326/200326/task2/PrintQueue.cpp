#include <iostream>
#include "PrintQueue.h"

using namespace std;

void PrintQueue::addJob(PrintJob* job) {
    jobs.push_back(job);
    sortByPriority();
}

PrintJob* PrintQueue::getNextJob() {
    if (jobs.empty()) {
        return nullptr;
    }
    
    PrintJob* job = jobs[0];
    jobs.erase(jobs.begin());
    return job;
}

bool PrintQueue::isEmpty() const {
    return jobs.empty();
}

int PrintQueue::getSize() const {
    return jobs.size();
}

void PrintQueue::sortByPriority() {
    for (size_t i = 0; i < jobs.size() - 1; i++) {
        for (size_t j = 0; j < jobs.size() - i - 1; j++) {
            if (jobs[j]->getPriority() < jobs[j + 1]->getPriority()) {
                PrintJob* temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

void PrintQueue::displayQueue() const {
    cout << "Current print queue (by priority):" << endl;
    if (jobs.empty()) {
        cout << "  Queue is empty" << endl;
        return;
    }
    
    for (size_t i = 0; i < jobs.size(); i++) {
        cout << "  " << (i + 1) << ". Job #" << jobs[i]->getId() 
             << " | User: " << jobs[i]->getUserName()
             << " | Priority: " << jobs[i]->getPriority()
             << " | Pages: " << jobs[i]->getPages() << endl;
    }
}
