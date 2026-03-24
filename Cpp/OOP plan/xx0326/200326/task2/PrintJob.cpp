#include <iostream>
#include "PrintJob.h"

using namespace std;

PrintJob::PrintJob(int id, string userName, int priority, int pages, double submitTime) {
    this->id = id;
    this->userName = userName;
    this->priority = priority;
    this->pages = pages;
    this->submitTime = submitTime;
    this->startTime = 0;
    this->endTime = 0;
    this->completed = false;
}

int PrintJob::getId() const {
    return id;
}

string PrintJob::getUserName() const {
    return userName;
}

int PrintJob::getPriority() const {
    return priority;
}

int PrintJob::getPages() const {
    return pages;
}

double PrintJob::getSubmitTime() const {
    return submitTime;
}

double PrintJob::getStartTime() const {
    return startTime;
}

double PrintJob::getEndTime() const {
    return endTime;
}

double PrintJob::getProcessingTime() const {
    return endTime - startTime;
}

bool PrintJob::isCompleted() const {
    return completed;
}

void PrintJob::setStartTime(double time) {
    this->startTime = time;
}

void PrintJob::setEndTime(double time) {
    this->endTime = time;
}

void PrintJob::markCompleted() {
    this->completed = true;
}

bool PrintJob::operator>(const PrintJob& other) const {
    return priority > other.priority;
}

bool PrintJob::operator<(const PrintJob& other) const {
    return priority < other.priority;
}
