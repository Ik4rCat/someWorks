#pragma once

class Ishape
{
    public:
        virtual double GetArea(double a, double b) = 0;
        virtual double GetPerimeter(double a, double b, double c) = 0;
        virtual int GetCount() = 0 ; 
};