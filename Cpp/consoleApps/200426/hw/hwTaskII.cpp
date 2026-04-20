#include <iostream>
using namespace std;

int SumArray(int arr[]){
    int sum = 0;
    for (int i = 0; i < 10; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int numbers[] = {1,2,3,4,5};
    cout << SumArray(numbers) << endl;
    return 0;
}