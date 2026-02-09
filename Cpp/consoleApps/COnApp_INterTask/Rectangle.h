#pragma once
#include "Interface.h"

class Rectangle: Ishape
{
    double s, p;
    int count = 4;
    
    double GetArea(double a, double b)override{
        s = a * b;

        return s;
    }

    // double GetPerimetr(double a, double b, double c)override{
    //     p = 2 * (a+b);

    //     return p;
    // }

    int GetCount()override{
        return count;
    }

};