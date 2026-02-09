#pragma once
#include "Interface.h"

class Triangle : Ishape
{
    double s, p;
    int count = 3;

    double GetArea(double a, double b)override{
        s = a * b /2;

        return s;
    }

    // double GetPerimetr(int a, int b, int c)override{
    //     p = a * b * c;

    //     return p;
    // }

    int GetCount()override{
        return count;
    }

};