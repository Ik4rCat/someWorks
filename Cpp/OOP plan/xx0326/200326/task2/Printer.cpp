#include <iostream>
#include "Printer.h"

using namespace std;

Printer::Printer(string name, double pagesPerMinute) {
    this->name = name;
    this->isPrinting = false;
    this->currentJob = nullptr;
    this->currentTime = 0;
    this->pagesPerMinute = pagesPerMinute;
    this->totalJobs = 0;
    this->totalPrintingTime = 0;
    this->totalPages = 0;
}

Printer::~Printer() {
    for (PrintJob* job : allJobs) {
        delete job;
    }
}

void Printer::submitJob(PrintJob* job) {
    allJobs.push_back(job);
}

void Printer::processNextJob() {
    if (currentJob != nullptr) {
        delete currentJob;
        currentJob = nullptr;
    }
}

void Printer::simulate(double simulationTime, vector<PrintJob*>& jobQueue) {
    int jobIndex = 0;
    
    while (currentTime < simulationTime) {
        if (!isPrinting && jobIndex < jobQueue.size()) {
            currentJob = jobQueue[jobIndex];
            currentJob->setStartTime(currentTime);
            isPrinting = true;
            totalJobs++;
            totalPages += currentJob->getPages();
            jobIndex++;
        }
        
        if (isPrinting && currentJob != nullptr) {
            double jobTime = currentJob->getPages() / pagesPerMinute;
            currentTime += jobTime;
            currentJob->setEndTime(currentTime);
            currentJob->markCompleted();
            
            PrintJob* completed = new PrintJob(
                currentJob->getId(),
                currentJob->getUserName(),
                currentJob->getPriority(),
                currentJob->getPages(),
                currentJob->getSubmitTime()
            );
            completed->setStartTime(currentJob->getStartTime());
            completed->setEndTime(currentJob->getEndTime());
            completed->markCompleted();
            
            completedJobs.push(completed);
            totalPrintingTime += jobTime;
            
            delete currentJob;
            currentJob = nullptr;
            isPrinting = false;
        } else {
            currentTime += 0.5;
        }
    }
}

void Printer::addCompletedJob(PrintJob* job) {
    completedJobs.push(job);
}

queue<PrintJob*> Printer::getCompletedJobs() const {
    return completedJobs;
}

void Printer::displayStatistics() const {
    cout << "\n===== PRINTER STATISTICS: " << name << " =====" << endl;
    cout << "Total jobs processed: " << totalJobs << endl;
    cout << "Total pages printed: " << totalPages << endl;
    cout << "Total printing time: " << totalPrintingTime << " minutes" << endl;
    if (totalJobs > 0) {
        cout << "Average job time: " << (totalPrintingTime / totalJobs) << " minutes" << endl;
    }
    cout << "Pages per minute: " << pagesPerMinute << endl;
}

void Printer::displayCompletedJobs() const {
    cout << "\n===== COMPLETED PRINT JOBS =====" << endl;
    if (completedJobs.empty()) {
        cout << "No completed jobs" << endl;
        return;
    }
    
    queue<PrintJob*> temp = completedJobs;
    int count = 1;
    while (!temp.empty()) {
        PrintJob* job = temp.front();
        cout << count << ". Job #" << job->getId()
             << " | User: " << job->getUserName()
             << " | Priority: " << job->getPriority()
             << " | Pages: " << job->getPages()
             << " | Time: " << job->getProcessingTime() << " min" << endl;
        temp.pop();
        count++;
    }
}

double Printer::getCurrentTime() const {
    return currentTime;
}

bool Printer::isBusy() const {
    return isPrinting;
}
