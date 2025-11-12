#include <iostream>
#include <string>
using namespace std;

/// HI! Today on lesson I will working with matrix (＃°Д°)

int main()
{
	int i, q, sum=0, summ=0;
	const int y=5, x=5, z=5;  // Ru: константы для размеров матрицы и массива | Eng: constants for matrix and array sizes
	int matrix[y][x];  // Ru: объявление двумерного массива (матрицы) | Eng: declaration of 2D array (matrix)
	int arr[z];  // Ru: объявление одномерного массива | Eng: declaration of 1D array

	// Ru: пример инициализированной матрицы (закомментировано) | Eng: example of initialized matrix (commented)
	//int mat[4][3]{
	//	{1, 2, 3},
	//	{4, 5, 6},
	//	{7, 8, 9},
	//	{10, 11, 12}
	//};

	// Ru: вывод информации о матрице | Eng: output matrix information
	cout << "matrix type:" 
		<< typeid(matrix).name() <<
		"\n" << "matrix size : \n count of lines : " << y 
		<< "\n count of elements in line : " << x << endl;

	// Ru: ввод данных в матрицу пользователем | Eng: user input for matrix data
	for (i = 0; i < y; i++) {
		for (q = 0; q < x; q++) {
			cout << "Enter number: " << endl;
			cin >> matrix[i][q];
			cout << "\n";
		}
	}

	// Ru: вычисление суммы четных чисел в матрице | Eng: calculating sum of even numbers in matrix
	for (i = 0; i < y; i++) {
		for (q = 0; q < x; q++) {
			if (matrix[i][q] % 2 == 0) {  // Ru: проверка на четность | Eng: check for even number
				sum += matrix[i][q];  // Ru: добавление четного числа к сумме | Eng: add even number to sum
			}
		}
	}

	// Ru: вывод матрицы в виде таблицы | Eng: output matrix as table
	for (i = 0; i < y; i++) {
		for (q = 0; q < x; q++) {
			cout << matrix[i][q] << "\t";  // Ru: табуляция для выравнивания | Eng: tabulation for alignment
		}
		cout << "\n";  // Ru: перевод строки после каждой строки матрицы | Eng: new line after each matrix row
	}
	cout << "Sum = " << sum << endl;  // Ru: вывод суммы четных чисел | Eng: output sum of even numbers

	// Ru: работа с одномерным массивом | Eng: working with 1D array
	for (i = 0; i < z; i++) {
		cout << "\nEnter num: " << endl;
		cin >> arr[i];  // Ru: ввод элементов массива | Eng: input array elements
	}
	
	// Ru: вывод элементов массива через запятую | Eng: output array elements separated by commas
	for (i = 0; i < z; i++) {
		cout << arr[i] << ",";
	}
	
	// Ru: вычисление суммы всех элементов массива | Eng: calculating sum of all array elements
	for (i = 0; i < z; i++) {
		summ += arr[i];
	}
	cout << "\n";
	cout << summ;  // Ru: вывод суммы элементов массива | Eng: output sum of array elements
	
	return 0;  // Ru: завершение программы | Eng: program termination
}
