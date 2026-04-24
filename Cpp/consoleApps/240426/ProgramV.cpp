#include <iostream>
#include <string>

int count_uppercase(const std::string& s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string str = "Hello World!";
    std::cout << count_uppercase(str) << std::endl;
    return 0;
}
