
#include <iostream>

bool is_prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << is_prime(1) << std::endl;
    std::cout << is_prime(2) << std::endl;
    std::cout << is_prime(9) << std::endl;
    return 0;
}
