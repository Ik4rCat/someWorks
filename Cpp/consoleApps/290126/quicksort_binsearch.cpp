// Предварительные задачи к экзамену (290126)
// Задание 2: Быстрая сортировка элементов, найденных бинарным поиском из файла.
// Количество данных >= 1000, найденные элементы > 200.

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// ============================================================
// Генерация файла с 1000+ случайными числами [1..500]
// ============================================================
void generateFile(const std::string& filename, int count) {
    std::ofstream f(filename);
    for (int i = 0; i < count; i++) {
        f << (rand() % 500 + 1);
        if (i < count - 1) f << " ";
    }
    std::cout << "Файл '" << filename << "' создан (" << count << " чисел)\n";
}

// ============================================================
// Бинарный поиск: возвращает все индексы элементов > threshold
// в отсортированном массиве (через lower_bound)
// ============================================================
std::vector<int> binarySearchGreaterThan(const std::vector<int>& sorted, int threshold) {
    std::vector<int> result;
    // Найдём первый элемент > threshold
    auto it = std::upper_bound(sorted.begin(), sorted.end(), threshold);
    while (it != sorted.end()) {
        result.push_back(*it);
        ++it;
    }
    return result;
}

// ============================================================
// Быстрая сортировка (своя реализация)
// ============================================================
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            std::swap(arr[++i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ============================================================
// Главная программа
// ============================================================
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const std::string filename = "numbers.txt";
    const int COUNT = 1200;
    const int THRESHOLD = 200;

    // 1. Генерируем файл
    generateFile(filename, COUNT);

    // 2. Читаем числа из файла
    std::vector<int> data;
    std::ifstream f(filename);
    int n;
    while (f >> n) data.push_back(n);
    std::cout << "Прочитано из файла: " << data.size() << " чисел\n";

    // 3. Сортируем весь массив (нужно для бинарного поиска)
    std::vector<int> sortedData = data;
    std::sort(sortedData.begin(), sortedData.end());

    // 4. Бинарный поиск: найти все элементы > 200
    std::vector<int> found = binarySearchGreaterThan(sortedData, THRESHOLD);
    std::cout << "Найдено элементов > " << THRESHOLD << ": " << found.size() << "\n";

    // 5. Быстрая сортировка найденных элементов
    quickSort(found, 0, (int)found.size() - 1);

    // 6. Вывод первых 20 и последних 20
    std::cout << "\nПервые 20 после сортировки: ";
    for (int i = 0; i < std::min(20, (int)found.size()); i++)
        std::cout << found[i] << " ";

    std::cout << "\nПоследние 20 после сортировки: ";
    int sz = found.size();
    for (int i = std::max(0, sz - 20); i < sz; i++)
        std::cout << found[i] << " ";

    std::cout << "\n\nМин: " << found.front() << "  Макс: " << found.back() << "\n";
    std::cout << "Все элементы > " << THRESHOLD << ": " << (found.front() > THRESHOLD ? "Да" : "Нет") << "\n";

    return 0;
}
