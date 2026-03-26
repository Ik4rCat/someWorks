#pragma once

#include <string>
#include <vector>
#include "Stantion.h"

using namespace std;

class Train
{
private: 
    string toStantion;  

    //here data train, but in normal app u need to make another .h & .cpp files for data saving, or sql 
    vector<Train> data;

public:
   // Train(int tN, int oT, string tS): tn(trainNUm), oT(outTime), tS(toStantion) {}

   // ~Train() { delete }

    Train GetTrainStorage(int index){
        return data[index];
    }

    void SetTrainStorage(int index,int  newTrainNum ){
        
    }

};