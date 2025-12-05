#include <iostream>
#include <string>
#include <random>
using namespace std;

int main() {
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    uniform_real_distribution<> dist(25.5, 103.4942);

    for (int i = 0; i < 10; i++) {
        cout << "Random Integer: " << distrib(gen) << endl;
        cout << "Random Float: " << dist(gen) << endl;
    }



}
