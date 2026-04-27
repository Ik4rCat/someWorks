#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
protected:
    string firstName;
    string lastName;
    int age;
    string group;
    double averageGrade;

public:
    Student(string fName = "", string lName = "", int a = 0, string gr = "", double avg = 0.0)
        : firstName(fName), lastName(lName), age(a), group(gr), averageGrade(avg) {}

    virtual void displayInfo() const {
        cout << "Student: " << lastName << " " << firstName << endl;
        cout << "Age: " << age << endl;
        cout << "Group: " << group << endl;
        cout << "Grade: " << averageGrade << endl;
    }

    virtual ~Student() {}
};

class Aspirant : public Student {
private:
    string thesisTopic;
    string advisor;

public:
    Aspirant(string fName = "", string lName = "", int a = 0, string gr = "", double avg = 0.0,
             string topic = "", string adv = "")
        : Student(fName, lName, a, gr, avg), thesisTopic(topic), advisor(adv) {}

    void displayInfo() const override {
        Student::displayInfo();
        cout << "Aspirant Info:" << endl;
        cout << "Thesis: " << thesisTopic << endl;
        cout << "Advisor: " << advisor << endl;
    }
};

class Passport {
protected:
    string surname;
    string name;
    string patronymic;
    string dateOfBirth;

public:
    Passport(string sur = "", string nam = "", string patr = "", string dob = "")
        : surname(sur), name(nam), patronymic(patr), dateOfBirth(dob) {}

    virtual void displayInfo() const {
        cout << "Passport:" << endl;
        cout << "Name: " << surname << " " << name << " " << patronymic << endl;
        cout << "DOB: " << dateOfBirth << endl;
    }
};

class ForeignPassport : public Passport {
private:
    string passportNumber;
    vector<string> visas;

public:
    ForeignPassport(string sur = "", string nam = "", string patr = "", string dob = "", string num = "")
        : Passport(sur, nam, patr, dob), passportNumber(num) {}

    void addVisa(string visa) {
        visas.push_back(visa);
    }

    void displayInfo() const override {
        Passport::displayInfo();
        cout << "Foreign Passport:" << endl;
        cout << "Number: " << passportNumber << endl;
        cout << "Visas: ";
        for (const auto& v : visas) {
            cout << v << " ";
        }
        cout << endl;
    }
};

class Transport {
protected:
    string name;
    double speed;
    double costPerKm;
    double maxLoad;
    int maxPassengers;

public:
    Transport(string n = "", double s = 0.0, double cpk = 0.0, double ml = 0.0, int mp = 0)
        : name(n), speed(s), costPerKm(cpk), maxLoad(ml), maxPassengers(mp) {}

    virtual double calculateTime(double distance) const = 0;
    virtual double calculateCost(double distance, double weight, int passengers) const = 0;
    virtual void displayInfo() const = 0;
    virtual ~Transport() {}
};

class Car : public Transport {
public:
    Car(string n = "", double s = 80.0, double cpk = 5.0, double ml = 500.0, int mp = 5)
        : Transport(n, s, cpk, ml, mp) {}

    double calculateTime(double distance) const override {
        return distance / speed;
    }

    double calculateCost(double distance, double weight, int passengers) const override {
        if (weight > maxLoad || passengers > maxPassengers) return -1;
        return distance * costPerKm * (1 + weight / maxLoad);
    }

    void displayInfo() const override {
        cout << "Car: " << name << endl;
    }
};

class Bicycle : public Transport {
public:
    Bicycle(string n = "", double s = 20.0, double cpk = 0.5, double ml = 20.0, int mp = 1)
        : Transport(n, s, cpk, ml, mp) {}

    double calculateTime(double distance) const override {
        return distance / speed;
    }

    double calculateCost(double distance, double weight, int passengers) const override {
        if (weight > maxLoad || passengers > maxPassengers) return -1;
        return distance * costPerKm;
    }

    void displayInfo() const override {
        cout << "Bicycle: " << name << endl;
    }
};

class Wagon : public Transport {
public:
    Wagon(string n = "", double s = 10.0, double cpk = 2.0, double ml = 1000.0, int mp = 4)
        : Transport(n, s, cpk, ml, mp) {}

    double calculateTime(double distance) const override {
        return distance / speed;
    }

    double calculateCost(double distance, double weight, int passengers) const override {
        if (weight > maxLoad || passengers > maxPassengers) return -1;
        return distance * costPerKm * 1.5;
    }

    void displayInfo() const override {
        cout << "Wagon: " << name << endl;
    }
};

void testTask1() {
    cout << "=== Task 1 ===" << endl;
    Student s("Ivan", "Ivanov", 20, "CS-1", 4.5);
    s.displayInfo();
    
    Aspirant a("Petr", "Petrov", 25, "CS-2", 5.0, "AI Research", "Dr. Smith");
    a.displayInfo();
    cout << endl;
}

void testTask2() {
    cout << "=== Task 2 ===" << endl;
    ForeignPassport fp("Shevchenko", "Taras", "Hryhorovych", "09.03.1814", "UA123456");
    fp.addVisa("Schengen");
    fp.addVisa("USA");
    fp.displayInfo();
    cout << endl;
}

void testTask3() {
    cout << "=== Task 3 ===" << endl;
    Transport* t1 = new Car("Toyota Camry", 90.0, 6.0, 450.0, 5);
    Transport* t2 = new Bicycle("Mountain Bike", 18.0, 0.3, 15.0, 1);
    Transport* t3 = new Wagon("Horse Wagon", 12.0, 2.5, 800.0, 4);

    double distance = 100.0;
    double cargo = 200.0;
    int passengers = 2;

    t1->displayInfo();
    cout << "Time: " << t1->calculateTime(distance) << " h, Cost: " << t1->calculateCost(distance, cargo, passengers) << endl;

    t2->displayInfo();
    cout << "Time: " << t2->calculateTime(distance) << " h, Cost: " << t2->calculateCost(distance, 10.0, 1) << endl;

    t3->displayInfo();
    cout << "Time: " << t3->calculateTime(distance) << " h, Cost: " << t3->calculateCost(distance, cargo, passengers) << endl;

    delete t1;
    delete t2;
    delete t3;
}

int main() {
    testTask1();
    testTask2();
    testTask3();
    return 0;
}