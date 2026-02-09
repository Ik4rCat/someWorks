#pragma once
#include "Interface.h"
#include "math.h"

class Circle : Ishape
{
    double s, p, d, r;
    int count = 0;

    double GetArea(double a, double b)override{
        s = M_PI * (r * 2);

        return s;
    }

    // double GetPerimetr()override{
    //     d = 2*r;
    //     p = d * M_PI;

    //     return p;
    // }

    int GetCount()override{
        return count;
    }

};