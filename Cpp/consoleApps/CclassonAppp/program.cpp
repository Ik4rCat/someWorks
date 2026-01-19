#include <iostream>
using namespace std;

// class Daun{
// private:
//     int age;
//     int matr = 0;
// public:
//     Daun() {}
//     Daun(int a){
//         age = a;
//         matr = 0;
//     }
//     int get_a(){
//         return age;
//     }     
//     void set_a(int a){
//         age = a;
//     }
//     int get_m(){
//         return matr;
//     }     
//     void set_m(int m){
//         matr = m;
//     }
// Daun(int a, int m) : age(a), matr(m){}
// ~Daun(){
//     age = 0;
//     matr = 0;
// }
// };

class Point{
private:
    int x;
    int y;
public:
    Point(int xX = 0, int yY = 0) : x(xX), y(yY) {}

    Point(int xX){
        x = xX;
        y = 0;
    }
    int get_x(){
        return x;
    }     
    void set_x(int xX){
        x = xX;
    }
    int get_y(){
        return y;
    }     
    void set_y(int yY){
        y = yY;
    }

double distanceTo(Point other){
    int dx = x - other.x;
    int dy = y - other.y;
    double ans = dx * dx + dy * dy;
    return ans;
}

string toString(){  
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}

};

class OtherP{
private:
    int xp;
    int yp;
public:
    OtherP(int xX = 0, int yY = 0) : xp(xX), yp(yY) {}

    OtherP(int xX){
        xp = xX;
        yp = 0;
    }
    int get_x(){
        return xp;
    }     
    void set_x(int xX){
        xp = xX;
    }
    int get_y(){
        return yp;
    }     
    void set_y(int yY){
        yp = yY;
    }
};

int main()
{
    Point p ;
    OtherP oP ;
    
    // Daun d;
    // d.set_a(23);
    // cout<< d.get_a();
    // Daun a(12,23), b(1);
    // cout<<"\033[38;2;0;255;255mAge: "<<a.get_a()<<"\t"<<a.get_m()<<"\n";
    // cout<<"\033[38;2;0;255;255mB: "<<b.get_a()<<"\t"<<b.get_m()<<"\n";

    cout<< "Enter num x: ";


}