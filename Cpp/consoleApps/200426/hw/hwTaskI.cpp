#include <iostream>
#include <cstring>

using namespace std;

char* CopyString(const char* src){
    char* dest = new char[strlen(src)];
    strcpy(dest, src);
    return dest;
}

int main(){
    const char* original = "Hello";
    char* copy = CopyString(original);
    cout << copy << endl;
    delete copy;
    return 0;
}