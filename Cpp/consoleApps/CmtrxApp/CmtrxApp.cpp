#include <iostream>
#include <string>
using namespace std;

/// HI! Today on lesson I will working with matrix (＃°Д°)

int main()
{
	int i, q, sum=0, summ=0;
	const int y=5, x=5, z=5; 
	int matrix[y][x];
	int arr[z];

	//int mat[4][3]{
	//	{1, 2, 3},
	//	{4, 5, 6},
	//	{7, 8, 9},
	//	{10, 11, 12}
	//};

	cout << "matrix type:" 
		<< typeid(matrix).name() <<
		"\n" << "matrix size : \n count of lines : " << y 
		<< "\n count of elements in line : " << x << endl;

	// input
	for (i = 0; i < y; i++) {
		for (q = 0; q < x; q++) {
			cout << "Enter number: " << endl;
			cin >> matrix[i][q];
			cout << "\n";
		}
	}

	// sum friendly % 2 nums
	for (i = 0; i < y; i++) {
		for (q = 0; q < x; q++) {
			if (matrix[i][q] % 2 == 0) {
				sum += matrix[i][q];
			}
		}
	}

	// output
	for (i = 0; i < y; i++) {
		for (q = 0; q < x; q++) {
			cout << matrix[i][q] << "\t";
		}
		cout << "\n";
	}
	cout << "Sum = " << sum << endl;

	for (i = 0; i < z; i++) {
		cout << "\nEnter num: " << endl;
		cin >> arr[i];
	}
	for (i = 0; i < z; i++) {
		cout << arr[i] << ",";
	}
	for (i = 0; i < z; i++) {
		summ += arr[i];
	}
	cout << "\n";
	cout << summ;
}
