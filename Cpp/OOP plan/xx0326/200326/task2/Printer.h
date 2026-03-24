#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include "PrintJob.h"

using namespace std;

class Printer {
private:
    string name;
    bool isPrinting;
    PrintJob* currentJob;
    double currentTime;
    double pagesPerMinute;
    
    queue<PrintJob*> completedJobs;
    vector<PrintJob*> allJobs;
    
    int totalJobs;
    double totalPrintingTime;
    int totalPages;

public:
    Printer(string name, double pagesPerMinute = 10);
    ~Printer();
    
    void submitJob(PrintJob* job);
    void processNextJob();
    void simulate(double simulationTime, vector<PrintJob*>& jobQueue);
    
    void addCompletedJob(PrintJob* job);
    queue<PrintJob*> getCompletedJobs() const;
    
    void displayStatistics() const;
    void displayCompletedJobs() const;
    
    double getCurrentTime() const;
    bool isBusy() const;
};
