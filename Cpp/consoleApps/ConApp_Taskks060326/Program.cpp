#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T Max(T t1, T t2){
    return t1 > t2 ? t1 : t2;
}

template <>
const char* Max<const char*>(const char* t1, const char* t2)
{
    return (strcmp(t1, t2) > 0 ? t1 : t2);
}

template <class T>
void getValue(std::string promt, T& value){
    std::cout << promt;
    std::cin >> value;
    while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "[!] Error! Please try again: ";
        std::cout << endl;
        std::cout << promt;
        std::cin >> value;
    }
    std::string endLine;
    //getLine(std::cin, endLine);
    
}

//template <class T>
//inline void getValue<std::string>(std::string promt, std::string& value)
//{
//  std::cout << promt;
//  getline(std::cin, value);
//
//}

int main()
{
    return 0;
}