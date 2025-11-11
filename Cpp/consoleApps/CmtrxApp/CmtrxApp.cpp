#include <iostream>
#include <string>
using namespace std;

/// HI! Today on lesson I will working with matrix (＃°Д°)

int main()
{
	int i, q;
	const int y=5, x=5; 
	int matrix[y][x];

	//int mat[4][3]{
	//	{1, 2, 3},
	//	{4, 5, 6},
	//	{7, 8, 9},
	//	{10, 11, 12}
	//};

	cout << "matrix type: int\n" << "matrix size:\n count of lines: " << y << "\n count of elements in line: " << x << endl;

	// input
	for (i = 0; i < y; i++) {
		for (q = 0; q < x; q++) {
			cout << "Enter number: " << endl;
			cin >> matrix[i][q];
		}
	}

	// output
	for (i = 0; i < y; i++) {
		for (q = 0; q < x; q++) {
			cout << matrix[i][q] << "\t";
		}
		cout << "\n";
	}

}
