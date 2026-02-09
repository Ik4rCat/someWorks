#include <iostream>
#include "Figure.h"

int Count::countOfFuncs = 6; 

double Count::AreaOf​​ATriangle(double a, double b){

    double s = 1/2 * a * b;

    countOfFuncs++;
    return s;
}
        
double Count::AreaOf​​ARightTriangle(double a, double b){

    double s = a * b / 2;

    countOfFuncs++;
    return s;
}

double Count::AreaOf​​ARhombus(double a, double h){

    double s = a * h;

    countOfFuncs++;
    return s;
}

double Count::AreaOfASquare(double a){
            
    double s = a * 2;

    countOfFuncs++;
    return s;
}

double Count::AreaOfARectangle(double a, double b){

    double s = a * b;

    countOfFuncs++;
    return s;
}