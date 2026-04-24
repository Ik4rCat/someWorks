#include <iostream>
#include <cstring>

char* copy_string(const char* src) {
    char* dest = new char[strlen(src)];
    strcpy(dest, src);
    return dest;
}

int main() {
    const char* original = "Hello";
    char* copy = copy_string(original);
    std::cout << copy << std::endl;
    delete copy;
    return 0;
}
