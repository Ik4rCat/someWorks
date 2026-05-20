#include "library.h"
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

std::string reverseString(const std::string& s) {
    std::string result = s;
    std::reverse(result.begin(), result.end());
    return result;
}

int sumArray(const std::vector<int>& arr) {
    return std::accumulate(arr.begin(), arr.end(), 0);
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

double average(const std::vector<int>& arr) {
    if (arr.empty())
        throw std::invalid_argument("massiv empty");
    return static_cast<double>(std::accumulate(arr.begin(), arr.end(), 0)) / arr.size();
}
