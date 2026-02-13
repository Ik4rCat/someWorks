#include <iostream>

class Kopy{
    int a;
    Kopy(const Kopy& object){
        a = object.a;
    }
    Kopy(int s) :a(s){}
    Kopy(const Kopy& object){
        a = object.a;
    }
    int get() const{
        return a;
    }

    // explicit void dir (const Kopy& kop){
    //     std::cout << "ttt";
    // }
};

int main()
{
    // Kopy k(6);
    // const Kopy y(7);
    // std::cout << k.get() << "  " << y.get() << 
}