#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
	/// HI, Here i testing random in cpp on my cpp college lessons ＼（〇_ｏ）／
	/// I'm interested in how it works in Unreal engine (。_。)
	int x, y, i;

	cout << "Start num" << endl;
	cin >> x;
	cout << "End num" << endl;
	cin >> y;

	srand(time(0));
	i = rand() % (y - x + 1) + x;
	
	cout << "your random num = " << i << "\n" << endl;

	switch (i) {
	case(0):
		cout << "bruh... how" << endl;
		break;
	case(1):
		cout << "noob" << endl;
		break;
	case(2):
		cout << "GOD" << endl;
		break;
	case(3):
		cout << "lol" << endl;
		break;
	case(4):
		cout << "nice" << endl;
		break;
	case(5):
		cout << "good" << endl;
		break;
	}

	cout << "Some random nums \n" << endl;
	cout << "random num first = " << rand() % 100 + 1 << endl;
	cout << "random num second = " << rand()  << endl;
	cout << "random num third = " << rand()  << endl;

	return 0;
}
