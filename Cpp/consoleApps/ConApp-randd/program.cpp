#include <iostream>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());

unsigned int RGenerator(unsigned int min, unsigned int max){
    
    uniform_int_distribution<unsigned int> dist(1, 45);

    cout << "[DEBG] comple gen! {" << dist(gen) << "}" << endl;
    return dist(gen);
}

unsigned int GenD(unsigned int mounth){
    unsigned int minDataVal= 1 , maxDataVal= 31;

    if(mounth == 2) maxDataVal= 28;
    // else if (){

    // }
    return RGenerator(minDataVal, maxDataVal);

}

unsigned int GenM(){
    unsigned int minDataVal= 1 , maxDataVal= 12;

    return RGenerator(minDataVal, maxDataVal);
}

unsigned int GenY(){
    unsigned int minDataVal= 1 , maxDataVal= 3000;
 
   return RGenerator(minDataVal, maxDataVal);
}

int main()
{
    unsigned int day, mounth, year;

    cout<<"Starting generation"<<endl;

    year = GenY();
    mounth = GenM();
    day = GenD(mounth);

    cout<<"your data: "<< day << "/" << mounth << "/" << year <<endl;

}