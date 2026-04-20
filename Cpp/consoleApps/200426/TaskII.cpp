#include <iostream>
using namespace std;

int FindMax(int arr[], int size)
{
    if (size <= 0) {
        return 0;
    }

    int max = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int numbers[] = {-5, -1, -10};
    
    cout << FindMax(numbers, sizeof(numbers) / sizeof(numbers[0])) << endl;
    
    return 0;
}