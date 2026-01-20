#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
using namespace std;

int main() {
    const int count = 15;       
    const int minVal = 10;
    const int maxVal = 50;

    string filename = "file.txt";

    ofstream of;
    of.open(filename);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minVal, maxVal);

    for (int i = 0; i < count; ++i) {
        int num = dist(gen);
        of << num << '\n';
    }
    of.close();


    ifstream iff;               
    iff.open(filename);      

    vector<int> nums;
    int num;
    while (iff >> num) {        
        nums.push_back(num);
    }
    iff.close();

    cout << "Generated and loaded numbers:\n";
    for (int num : nums) {
        cout << num << '\n';
    }
}