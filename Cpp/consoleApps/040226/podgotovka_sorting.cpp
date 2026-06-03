// Подготовка (040226)
// Сортировка массива двумя способами с замером трудоёмкости.
// Заполнение — rand(). Каждый алгоритм — отдельная функция.
// Сравнение: количество сравнений.

#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 1000;

// ============================================================
// Генерация случайного массива
// ============================================================
void fillRandom(int* arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

void copyArray(const int* src, int* dst, int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

// ============================================================
// Сортировка пузырьком
// Возвращает количество сравнений
// ============================================================
long long bubbleSort(int* arr, int n) {
    long long comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return comparisons;
}

// ============================================================
// Сортировка вставками
// Возвращает количество сравнений
// ============================================================
long long insertionSort(int* arr, int n) {
    long long comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

// ============================================================
// Проверка, что массив отсортирован
// ============================================================
bool isSorted(const int* arr, int n) {
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int original[SIZE];
    int arr1[SIZE], arr2[SIZE];

    fillRandom(original, SIZE);
    copyArray(original, arr1, SIZE);
    copyArray(original, arr2, SIZE);

    std::cout << "Размер массива: " << SIZE << std::endl;

    // Пузырьковая
    clock_t t1 = clock();
    long long cmp1 = bubbleSort(arr1, SIZE);
    clock_t t2 = clock();
    double time1 = double(t2 - t1) / CLOCKS_PER_SEC * 1000;

    // Вставками
    clock_t t3 = clock();
    long long cmp2 = insertionSort(arr2, SIZE);
    clock_t t4 = clock();
    double time2 = double(t4 - t3) / CLOCKS_PER_SEC * 1000;

    std::cout << "\n--- Сортировка пузырьком ---" << std::endl;
    std::cout << "Сравнений:    " << cmp1 << std::endl;
    std::cout << "Время (мс):   " << time1 << std::endl;
    std::cout << "Отсортирован: " << (isSorted(arr1, SIZE) ? "Да" : "Нет") << std::endl;

    std::cout << "\n--- Сортировка вставками ---" << std::endl;
    std::cout << "Сравнений:    " << cmp2 << std::endl;
    std::cout << "Время (мс):   " << time2 << std::endl;
    std::cout << "Отсортирован: " << (isSorted(arr2, SIZE) ? "Да" : "Нет") << std::endl;

    std::cout << "\n--- Вывод ---" << std::endl;
    if (cmp1 < cmp2)
        std::cout << "Пузырьковая эффективнее по сравнениям." << std::endl;
    else if (cmp2 < cmp1)
        std::cout << "Вставками эффективнее по сравнениям." << std::endl;
    else
        std::cout << "Алгоритмы равны по числу сравнений." << std::endl;

    return 0;
}
