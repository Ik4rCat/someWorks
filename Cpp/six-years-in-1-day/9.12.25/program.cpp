#include <iostream>
#include <string>
using namespace std;

class Task1
{
private:
    void deleteElement(int arr[], int& size, int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

public:
    void Program() {
        int n, index;
        
        cout << "Enter array size: ";
        cin >> n;
        
        if (n <= 0) {
            cout << "Invalid size!" << endl;
            return;
        }
        
        int* arr = new int[n];
        
        cout << "Enter " << n << " numbers: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << "Enter index of element to delete (0-" << n-1 << "): ";
        cin >> index;
        
        deleteElement(arr, n, index);
        
        cout << "New array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        delete[] arr;
    }
};

class Task2
{
public:
    void Program() {
        int n;
        
        cout << "Enter array size: ";
        cin >> n;
        
        if (n <= 0) {
            cout << "Invalid size!" << endl;
            return;
        }
        
        int* arr = new int[n];
        
        cout << "Enter " << n << " numbers: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        bool* counted = new bool[n];
        for (int i = 0; i < n; i++) {
            counted[i] = false;
        }
        
        cout << "Element frequency:" << endl;
        for (int i = 0; i < n; i++) {
            if (!counted[i]) {
                int count = 1;
                
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] == arr[j]) {
                        count++;
                        counted[j] = true;
                    }
                }
                
                cout << arr[i] << ": " << count << " time(s)" << endl;
            }
        }
        
        delete[] arr;
        delete[] counted;
    }
};

class Task3
{
private:
    void rotateArray(int arr[], int size, int k) {
        if (size == 0) return;
        
        k = k % size;
        if (k < 0) {
            k = size + k;
        }
        
        int* temp = new int[k];
        
        for (int i = 0; i < k; i++) {
            temp[i] = arr[size - k + i];
        }
        
        for (int i = size - 1; i >= k; i--) {
            arr[i] = arr[i - k];
        }
        
        for (int i = 0; i < k; i++) {
            arr[i] = temp[i];
        }
        
        delete[] temp;
    }

public:
    void Program() {
        int n, k;
        
        cout << "Enter array size: ";
        cin >> n;
        
        if (n <= 0) {
            cout << "Invalid size!" << endl;
            return;
        }
        
        int* arr = new int[n];
        
        cout << "Enter " << n << " numbers: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << "Enter K (number of positions to rotate): ";
        cin >> k;
        
        rotateArray(arr, n, k);
        
        cout << "Rotated array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        delete[] arr;
    }
};

int main() {
    Task1 task1;
    Task2 task2;
    Task3 task3;

    while (true) {
        int choice;
        
        cout << "Choose task:" << endl;
        cout << "1 - Task1 (Delete element by index)" << endl;
        cout << "2 - Task2 (Element frequency in array)" << endl;
        cout << "3 - Task3 (Rotate array)" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            task1.Program();
            break;
        case 2:
            task2.Program();
            break;
        case 3:
            task3.Program();
            break;
        case 0:
            cout << "Program finished." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
        
        cout << endl;
    }
}
