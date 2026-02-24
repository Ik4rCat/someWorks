#include <iostream>
#include <vector>

using namespace std;

//Animals classes
class Animal
{   
    public:
        virtual void info() = 0;
        virtual ~Animal(){}

};

class HomeAqua : public Animal
{
    public:
        void info(){
            cout << "HomeAqua? like a fish i think" << endl;
        }

};

class HomeLoveWarmth : public Animal
{
    public:
        void info(){
            cout << "Home love warmth? like a cat i think" << endl;
        }
};

class HomeLoveTheCold : public Animal
{
    public:
        void info(){
            cout << "Home love the cold? like a cat i think" << endl;
        }
};

class WildAqua : public Animal
{
    public:
        void info(){
            cout << "Wild aqua? like a shark i think" << endl;
        }
};

class WildLoveWarmth : public Animal
{
    public:
        void info(){
            cout << "Wild love warmth? like a bear i think" << endl;
        }
};

class WildLoveTheCold : public Animal
{
    public:
        void info(){
            cout << "Wild love cold? like a  i think" << endl;
        }
};



class AnimalFactory
{
    public:
        //virtual 
};


//Animal constructors OLD
// class Factory 
// {
//     public:
//         virtual Animal *createAnimal() = 0;
//         virtual ~Factory(){}
// };

// class AquaFactory : public Factory
// {
//     public:
//         Animal* createAnimal()
//         {
//             return new Aqua();
//         }
// };

// class LoveWarmthFactory : public Factory
// {
//     public:
//         Animal *createAnimal()
//         {
//             return new LoveWarmth();
//         }
// };

// class LoveTheColdFactory : public Factory
// {
//     public:
//         Animal *createAnimal()
//         {
//             return new LoveTheCold();
//         }
// };


int main()
{
    vector<Animal*> a;

    // AquaFactory f1;
    // LoveTheColdFactory f2;
    // LoveWarmthFactory f3;

    // a.push_back(f1.createAnimal());
    // a.push_back(f2.createAnimal());
    // a.push_back(f3.createAnimal());

    cout << "--- create animals ---" << endl;
    for (Animal* p : a) {
        p->info();
        delete p;
    }
    cout << "--- end ---" << endl;

    return 0;
}