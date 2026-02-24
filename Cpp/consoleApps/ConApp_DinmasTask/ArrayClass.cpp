#include <iostream>
#include <cassert>
#include <cstring>

class st {
    int const apple = 0;
    int const banana = 1;
    int const cherry = 2;

    int* data = new int[5];

    static bool eq(const char* a, const char* b) {
        while (*a && *b && *a == *b) ++a, ++b;
        return *a == *b;
    }

public:
    int freg(const char* fruit) {
        if (strcmp(fruit, "apple") == 0) {return apple;}
        else if (strcmp(fruit, "banana") == 0) {return banana;}
        else if (strcmp(fruit, "cherry") == 0) {return cherry;}
    }

    int& operator[](int index) {
        assert((index>= 0) && (index < 5) and "index");
        return data[index];
    }

    // int& operator[](int index) {
    //     assert((index>= 0) && (index < 5) and "index");
    //     return data[index];
    // }
    // int operator[](int index) const {
    //     return data[index];
    // }
};


int main(){
    st t;
    int i;

    for (i = 0; i < 5; i++) {
        t[i] = i;
    }

    for (i = 0; i < 5; i++) {
        std::cout << t[i] << std::endl;
    }

    std::cout << "program ended" << std::endl;
    return 0;
}