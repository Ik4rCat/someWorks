#include <iostream>
#include <initializer_list>
#include <vector>

using namespace std;

template<typename T>
class Array {
private:
    vector<T> data;

public:
    Array(size_t size) : data(size, T{}) { cout << "Constructor with size: " << size << "\n"; }
    
    Array(initializer_list<T> init) : data(init) { cout << "Constructor with initializer_list\n"; }
    
    template<typename... Args>
    bool ge(Args... args) const {
        T sumArgs = (args + ...);
        T sumThis = T{};
        for (const auto& elem : data) {
            sumThis = sumThis + elem;
        }
        
        cout << "Array sum: " << sumThis << ", arguments sum: " << sumArgs << "\n";
        return sumThis >= sumArgs;
    }


};

//foreach in c++
//for(auto& element : list)
//{
//    data[i] = element;
//    i++;
//}




int main() {
    cout << "Hello, World!" << endl;
    return 0;
}


//Коннструктор
//Коннструктор С INITIALIZER_LIST
//фуркция сравнения 1 (...) ge(1,2,3,4,5)
//функция сравнения 2 (f&...) ge(g& r1, f& r2)
