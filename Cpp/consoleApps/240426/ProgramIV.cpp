
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("data.txt");
    std::string line;
    while (!file.eof()) {
        std::getline(file, line);
        std::cout << line << std::endl;
    }
    return 0;
}
