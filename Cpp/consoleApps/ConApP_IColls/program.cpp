#include <iostream>
#include <string>


using namespace std;

//man, strekoza, frog


class CR{
    public:
        virtual void eat() =0;
        virtual void drink() =0;
        virtual void sleep() =0;

        virtual ~CR() {}; 

};

class frog : public CR {

};

class Strecoza: public CR{

};

class person: public CR {

};



int main()
{


}
