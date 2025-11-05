#include <iostream>
#include <string>
#include <ctime>
#include <locale>

using namespace std;

int main()
{
	/// HI, Here i testing random in cpp on my cpp college lessons ＼（〇_ｏ）／
	/// I'm interested in how it works in Unreal engine (。_。)
	setlocale(LC_ALL, "ru");

	int x, y, i;

	cout << "Start num" << endl;
	cin >> x;
	cout << "End num" << endl;
	cin >> y;

	srand(time(0));
	i = rand() % (y - x + 1) + x;
	
	cout << "your random num = " << i << "\n" << endl;

	switch (rand() % (10 - 1+1)+1) {
	case 0:
		cout << "Возрат каретки в начало строки " << "\r" << endl;
		break;
	case 1:
		cout << "Новая строка " << "\n" << endl;
		break;
	case 2:
		cout << "Горизонтальная табуляция " << "\t" << endl;
		break;
	case 3:
		cout << "Вертикальная табуляция " << "\v" << endl;
		break;
	case 4:
		cout << "двойные кавычки " << "\1" << endl;
		break;
	case 5:
		cout << "Апостров " << "\'" << endl;
		break;
	case 6:
		cout << "обратный слеш " << "\\" << endl;
		break;
	case 7:
		cout << "Нулевой символ " << "\0" << endl;
		break;
	case 8:
		cout << "Знак вопроса " << "\?" << endl;
		break;
	case 9:
		cout << "Сигнал бипера (спикера) компьютера " << "\a" << endl;
		break;
	}

	cout << "\nSome random nums \n" << endl;
	cout << "random num first = " << rand() % 100 + 1 << endl;
	cout << "random num second = " << rand()  << endl;
	cout << "random num third = " << rand()  << endl;

	return 0;
}
