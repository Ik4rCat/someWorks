#include <iostream>

int* create_array(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i * i;
    }
    return arr;
}

int main() {
    int* data = create_array(10);
    for (int i = 0; i < 10; i++) {
        std::cout << data[i] << " ";
    }
    // забыли delete[]
    return 0;
}
