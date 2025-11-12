#include <iostream>
#include <vector>
using namespace std;

/// <summary>
/// ENG: HI! Today i will work with vectors ^o^
/// RU: Привет! Сегодня я буду работать с векторами ^o^
/// </summary>

void Task()
{
    
    vector<int> v0;
    vector<int> v1{ 
        1, 2, 3, 
        4, 5, 6};

    cout << v0.empty() << endl;
    cout << v0.size() << endl;
    cout << v0.capacity() << endl;
    cout << "--------------" << endl;
    cout << v1.empty() << endl;
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;

    v0.push_back(5);
    v0.push_back(6);
    v1.push_back(5);

    v0.pop_back();
    v1.pop_back();

    v0.insert(v0.begin() + 1, 99);
    v1.insert(v1.begin() + 1, 99);

    v0.erase(v0.begin() + 1);
    v1.erase(v1.begin() + 1);

    v0.clear();
    v0.emplace_back(245);
    v1.emplace_back(245);
    v0.resize(20, 55);
    v1.resize(20, 55);

    cout << v0.empty() << endl;
    cout << v0.size() << endl;
    cout << v0.capacity() << endl;
    cout << "--------------" << endl;
    cout << v1.empty() << endl;
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;

    v0.swap(v1);

    cout << v0.empty() << endl;
    cout << v0.size() << endl;
    cout << v0.capacity() << endl;
    cout << "--------------" << endl;
    cout << v1.empty() << endl;
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;

}

void Teory()
{
    // Ru: Немного векторов и варианты их создания | Eng: Some vectors and options for creating them
    vector<int> v1;  // Ru: пустой вектор | Eng: empty vector
    vector<int> v2(6);  // Ru: вектор из 6 элементов (значения по умолчанию) | Eng: vector with 6 elements (default values)
    vector<int> v3(5, 15);  // Ru: вектор из 5 элементов, все равны 15 | Eng: vector with 5 elements, all equal to 15
    vector<int> v4{ 1, 2, 3, 4, 5 };  // Ru: вектор с инициализацией списком | Eng: vector with list initialization
    vector<int> v5; (v3);  // Ru: ВНИМАНИЕ: v5 создается пустым, (v3) не копирует | Eng: ATTENTION: v5 created empty, (v3) doesn't copy

    /* Ru: закомментированные операции доступа к элементам | Eng: commented element access operations
     cout << v4[3] << endl;
     cout << v4.at(5) << endl;
     cout << v4.front() << endl;
     cout << v4.back() << endl << "__________";*/

     // Ru: проверка свойств векторов | Eng: checking vector properties
    cout << v1.empty() << endl;  // Ru: проверка пуст ли вектор | Eng: check if vector is empty
    cout << v2.size() << endl;  // Ru: текущий размер вектора | Eng: current vector size
    cout << v5.capacity() << endl;  // Ru: выделенная память для вектора | Eng: allocated memory for vector

    /* Ru: закомментированные операции с памятью | Eng: commented memory operations
     cout << v3.max_size() << endl;
     v5.reserve(100);
     cout << v5.capacity() << endl;
     v5.shrink_to_fit();
     cout << v5.capacity() << endl;*/

    cout << "_________________" << endl;

    // Ru: операции модификации векторов | Eng: vector modification operations
    v1.push_back(3);  // Ru: добавление элемента в конец | Eng: add element to the end
    v1.pop_back();  // Ru: удаление последнего элемента | Eng: remove last element
    v3.insert(v3.begin() + 1, 99);  // Ru: вставка элемента 99 на позицию 1 | Eng: insert element 99 at position 1
    v3.insert(v3.begin() + 3, 3, 100);  // Ru: вставка трех элементов 100 начиная с позиции 3 | Eng: insert three 100 elements starting from position 3
    v3.erase(v3.begin() + 1);  // Ru: удаление элемента на позиции 1 | Eng: remove element at position 1
    v5.erase(v5.begin() + 2, v5.end());  // Ru: удаление элементов с позиции 2 до конца | Eng: remove elements from position 2 to end
    v2.clear();  // Ru: очистка всего вектора | Eng: clear entire vector
    v2.emplace_back(245);  // Ru: создание элемента на месте в конце | Eng: construct element in-place at the end
    v2.emplace(v2.begin(), 99);  // Ru: создание элемента на месте в начале | Eng: construct element in-place at the beginning
    v3.resize(20, 55);  // Ru: изменение размера до 20, новые элементы = 55 | Eng: resize to 20, new elements = 55
    v3.resize(5);  // Ru: уменьшение размера до 5 | Eng: reduce size to 5

    v3.swap(v2);  // Ru: обмен содержимым двух векторов | Eng: swap contents of two vectors
}

int main()
{
    Task(); 
    return 0;  // Ru: завершение программы | Eng: program termination
}