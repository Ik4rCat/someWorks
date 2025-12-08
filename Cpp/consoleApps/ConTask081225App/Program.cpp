#include <iostream>
#include <string>
#include <vector>
using namespace std;

    // struct Object
    // {
    //     int a;
    //     string name;
    //     void getInfo(){

    //     }
    // };

    // Object obj;
    // obj = {26,"Alex"};
    // obj.name = "John"

class ObjectsData
{
    struct Address
    {
        string city = "none";
        string streetName = "none";
        string houseOrOffice = "none";

        int zipCode= 0;
    };

    struct Employer
    {
        string firstName = "none";
        string lastName = "none";
        string department = "none";

        int age = 0;
        int salary = 0;

        Address address;

        void GetInfo(){
            cout << endl;
            cout << "First Name: " << firstName << endl;
            cout << "last Name: " << lastName << endl;
            cout << "age: " << age << endl;
            cout << "Home address: " << endl;
            cout << "  " << address.city << endl;
            cout << "  " << address.streetName << " "<< address.houseOrOffice <<  endl;
            cout << "  " << address.zipCode << endl;
            cout << "<======> " << endl;
            cout << "department: " << department << endl;
            cout << "salary: " << salary << endl;
            cout << endl;
        }

    }_Employer;

    public:  Employer GetStuct(){
        return _Employer;
    }


};

class PF
{
    ObjectsData objData;

    //Employers part >>
    void AddEmployer(){
        
    }

    void DelEmployer(){

    }

    void UpdateEmployer(){
            
    }

    void OutputEmployers(){
        auto employer = objData.GetStuct();
        employer = {"Josh", "Miller", "IT support", 21, 150000};
        employer.address = {"Saint-Petersburg", "kalatushka", "H", 199228};

        employer.GetInfo();
    }

    //Address part >>
    void AddAddress(){

    }

    void DelAddress(){

    }

    void UpdateAddress(){

    }

    void OutputAddress(){

    }


    public:
        void Program(){
            while (true)
            {
                int choice;
                cout << endl;
                cout << "<==Menu==>" << endl;
                cout << "  - 1. View Employers" << endl;
                cout << "  - 2. Add Employers" << endl;
                cout << "  - 3. Delete Employers" << endl;
                cout << "  - 4. Search" << endl;

                cin >> choice;

                // if (choice == 1) OutputEmployers();
                switch (choice)
                {
                case 1: OutputEmployers();  break;
                case 0: return; break;
                
                default: cout << "error value" << endl; break;
                }
            }
        }
};



int main()
{
    PF pf;
    ObjectsData data;
    srand(time(0));

    pf.Program();
}