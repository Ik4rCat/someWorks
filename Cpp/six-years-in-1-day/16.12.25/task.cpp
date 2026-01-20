#include <iostream>
#include <string>
using namespace std;

class Task1
{
private:
    void printArray(int arr[], int size) {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

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
        int n;
        cout << "Enter array size N: ";
        cin >> n;

        if (n <= 0) {
            cout << "Array size must be positive!" << endl;
            return;
        }

        int* arr = new int[n];
        
        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        printArray(arr, n);

        int index;
        cout << "Enter index of element to delete (0-" << (n - 1) << "): ";
        cin >> index;

        deleteElement(arr, n, index);
        
        if (n > 0) {
            cout << "Updated array: ";
            printArray(arr, n);
        } else {
            cout << "Array is empty." << endl;
        }

        delete[] arr;
    }
};

class Task2
{
private:
    void printFrequency(int arr[], int n) {
        int* uniqueElements = new int[n];
        int* frequency = new int[n];
        int uniqueCount = 0;

        for (int i = 0; i < n; i++) {
            bool found = false;
            int foundIndex = -1;

            for (int j = 0; j < uniqueCount; j++) {
                if (uniqueElements[j] == arr[i]) {
                    found = true;
                    foundIndex = j;
                    break;
                }
            }

            if (found) {
                frequency[foundIndex]++;
            } else {
                uniqueElements[uniqueCount] = arr[i];
                frequency[uniqueCount] = 1;
                uniqueCount++;
            }
        }

        cout << "\nElement frequency:" << endl;
        for (int i = 0; i < uniqueCount; i++) {
            cout << "Element " << uniqueElements[i] << " appears " << frequency[i] << " time(s)" << endl;
        }

        delete[] uniqueElements;
        delete[] frequency;
    }

public:
    void Program() {
        int n;
        cout << "Enter array size: ";
        cin >> n;

        if (n <= 0) {
            cout << "Array size must be positive!" << endl;
            return;
        }

        int* arr = new int[n];
        
        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        printFrequency(arr, n);

        delete[] arr;
    }
};

class Task3
{
private:
    void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void rotateArray(int arr[], int size, int k) {
        if (size == 0) return;
        
        k = k % size;
        if (k < 0) {
            k += size;
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
        int n;
        cout << "Enter array size: ";
        cin >> n;

        if (n <= 0) {
            cout << "Array size must be positive!" << endl;
            return;
        }

        int* arr = new int[n];
        
        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Original array: ";
        printArray(arr, n);

        int k;
        cout << "Enter number of positions to rotate (K): ";
        cin >> k;

        rotateArray(arr, n, k);

        cout << "Rotated array: ";
        printArray(arr, n);

        delete[] arr;
    }
};

int main()
{
    Task1 task1;
    Task2 task2;
    Task3 task3;

    while (true) {
        int choice;

        cout << "\nChoose task:" << endl;
        cout << "1 - Task1 (Delete element by index)" << endl;
        cout << "2 - Task2 (Element frequency)" << endl;
        cout << "3 - Task3 (Rotate array by K positions)" << endl;
        cout << "0 - Exit" << endl;

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
            return 0;
        default:
            cout << "Invalid value, try again" << endl;
            break;
        }
    }
}

