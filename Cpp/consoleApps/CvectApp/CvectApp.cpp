#include <iostream>
#include <vector>
using namespace std;

/// <summary>
/// ENG: HI! Today i will work with vectors ^o^
/// RU: Привет! Сегодня я буду работать с векторами ^o^
/// </summary>

void Task() 
{
	
}

void Teory()
{
	// Ru: Немного векторов и варианты их создания | Eng: Some vectors and options for creating them
	vector<int> v1;
	vector<int> v2(6);
	vector<int> v3(5, 15);
	vector<int> v4{ 1, 2, 3, 4, 5 };
	vector<int> v5; (v3);

	// Ru: различные способы доступа к элементам вектора | Eng: different ways to access vector elements
	cout << v3[2] << endl; // Ru: достает по индексу | Eng: reaches the index
	cout << v3.at(1) << endl; // Ru: .at для обработки ошибок | Eng: .at for error handling
	cout << v3.front() << endl; // Ru: достает первый элемент | Eng: gets the first element
	cout << v3.back() << endl; // Ru: достает последний элемент | Eng: gets the last element

	// Ru: методы для получения информации о векторе | Eng: methods to get information about the vector
	cout << v1.empty() << endl; // Ru: проверяет пустой ли вектор | Eng: checks if vector is empty
	cout << v1.size() << endl; // Ru: выводит длину | Eng: outputs the length
	cout << v1.max_size() << endl; // Ru: выводит максимальный размер | Eng: outputs maximum size
	cout << v1.capacity() << endl; // Ru: выводит сколько может занимать места | Eng: outputs capacity

	// Ru: управление памятью вектора | Eng: vector memory management
	v5.reserve(100); // Ru: резервирует память для 100 элементов | Eng: reserves memory for 100 elements
	cout << v5.capacity() << endl;
	v5.shrink_to_fit(); // Ru: уменьшает capacity до size | Eng: reduces capacity to match size
	cout << v5.capacity() << endl;

}

int main()
{
	Task();
}