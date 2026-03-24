#pragma once

#include <iostream>
#include <string>

using namespace std;

class PrintJob {
private:
    int id;
    string userName;
    int priority;
    int pages;
    double submitTime;
    double startTime;
    double endTime;
    bool completed;

public:
    PrintJob(int id, string userName, int priority, int pages, double submitTime);
    
    int getId() const;
    string getUserName() const;
    int getPriority() const;
    int getPages() const;
    double getSubmitTime() const;
    double getStartTime() const;
    double getEndTime() const;
    double getProcessingTime() const;
    bool isCompleted() const;
    
    void setStartTime(double time);
    void setEndTime(double time);
    void markCompleted();
    
    bool operator>(const PrintJob& other) const;
    bool operator<(const PrintJob& other) const;
};
