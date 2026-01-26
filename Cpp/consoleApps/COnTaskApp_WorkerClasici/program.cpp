#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Worker
{
    private:
        string name;
        
        int age;
        int wHours;

        double sallery;

    public:
        Worker(const string&name, int age, int wHours, double sallery) : name(name), 
        age(age), 
        wHours(wHours), 
        sallery(sallery) {}
        
        virtual ~Worker() = default;

        string GetName() {return name;}
        int GetAge() {return age;}

};

class WorkerPlan : Worker
{
    public:
        // int GetWorkingHours() {return wHours;}
        // double GetSalleryInfo() {return sallery;}
};

class WorkerHour : Worker
{
    public:
        // int GetWorkingHours() {return wHours;}
        // double GetSalleryInfo() {return sallery;}
};

class Administrator : Worker
{
    public:
        double GetSalleryInfo(double reven) {

            // return sallery;
        }
};

int main()
{
    double revenue = 100000;

    

}
