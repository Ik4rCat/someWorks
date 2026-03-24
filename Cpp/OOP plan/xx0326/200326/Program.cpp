#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "task1/BusStop.h"
#include "task2/Printer.h"
#include "task2/PrintJob.h"

using namespace std;

void testBusStopSimulation() {
    cout << "\n========== MARSHRUTKA STOP SIMULATION ==========" << endl;
    
    double avgPassengerInterval, avgMarshrutkaInterval;
    bool isFinalStop;
    int maxPeople;
    
    cout << "\nEnter average time between passengers (minutes): ";
    cin >> avgPassengerInterval;
    cout << "Enter average time between marshrutkas (minutes): ";
    cin >> avgMarshrutkaInterval;
    cout << "Is this a final stop? (1-yes, 0-no): ";
    cin >> isFinalStop;
    cout << "Maximum people at stop: ";
    cin >> maxPeople;
    
    BusStop stop("Main Stop", isFinalStop, avgPassengerInterval, avgMarshrutkaInterval);
    stop.setMaxPassengers(maxPeople);
    
    double simulationTime = 480;
    stop.simulate(simulationTime);
    stop.displayStatistics();
    
    int requiredInterval = stop.calculateRequiredInterval(maxPeople);
    cout << "\nRecommended marshrutka interval: " << requiredInterval << " minutes" << endl;
}

void testPrinterSimulation() {
    cout << "\n========== PRINTER QUEUE SIMULATION ==========" << endl;
    
    Printer printer("Office Printer", 5);
    vector<PrintJob> jobs;
    vector<PrintJob*> jobPointers;
    
    int numJobs;
    cout << "\nEnter number of print jobs: ";
    cin >> numJobs;
    
    srand(time(nullptr));
    
    for (int i = 1; i <= numJobs; i++) {
        string user = "User" + to_string(rand() % 5 + 1);
        int priority = rand() % 5 + 1;
        int pages = rand() % 20 + 1;
        double submitTime = i * 2;
        
        PrintJob* job = new PrintJob(i, user, priority, pages, submitTime);
        jobPointers.push_back(job);
        
        cout << "Job #" << i << " | User: " << user 
             << " | Priority: " << priority 
             << " | Pages: " << pages << endl;
    }
    
    cout << "\nSimulating print queue..." << endl;
    printer.simulate(200, jobPointers);
    
    printer.displayStatistics();
    printer.displayCompletedJobs();
    
    for (PrintJob* job : jobPointers) {
        delete job;
    }
}

int main() {
    int choice;
    
    cout << "===== SIMULATION PROGRAMS =====" << endl;
    
    while (true) {
        cout << "\n1. Marshrutka Stop Simulation" << endl;
        cout << "2. Printer Queue Simulation" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1:
                testBusStopSimulation();
                break;
            case 2:
                testPrinterSimulation();
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    
    cout << "Goodbye!" << endl;
    return 0;
}
