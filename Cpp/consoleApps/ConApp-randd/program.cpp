#include <iostream>
#include <random>
using namespace std;

int RGenerator(int min, int max, int val){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);

    val = dist(gen);
}

int GenD(int dayN, int mounth){
    int minDataVal= 1 , maxDataVal= 31;

    //if(mounth == )

    RGenerator(minDataVal, maxDataVal, dayN);

}

int GenM(int mounthN){
    int minDataVal= 1 , maxDataVal= 12;

    RGenerator(minDataVal, maxDataVal, mounthN);
}

int GenY(int yearN){
    int minDataVal= 1 , maxDataVal= 3000;

    RGenerator(minDataVal, maxDataVal, yearN);
}

int main()
{
    int day, mounth, year;

    cout<<"Starting generation"<<endl;

    GenY(year);
    GenM(mounth);
    GenD(day, mounth);

    cout<<"your data: "<< day << "/" << mounth << "/" << year <<endl;

}