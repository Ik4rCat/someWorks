#include <iostream>
#include <string>
using namespace std;

int main()
{
	/// HI, Here i test random ＼（〇_ｏ）／
	
	srand(9);
	cout << "random num first = " << rand() % (30 - 11 + 1) + 11 << endl;
	cout << "random num second = " << rand()  << endl;
	cout << "random num third = " << rand()  << endl;

	return 0;
}
