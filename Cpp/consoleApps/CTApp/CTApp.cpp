#include <iostream>
#include <string>
#include <locale>
using namespace std;

/// HI, i need to make my taskes (。_。) 

void taskI()
{
	int userInp, result, max = 0;

	cout << "Enter num: " << endl;
	cin >> userInp;

	// Ru: цикл для обработки каждой цифры числа | Eng: loop to process each digit of the number
	while (userInp > 0) {
		result = userInp % 10;  // Ru: получение последней цифры числа | Eng: getting the last digit of the number
		if (userInp > max) max = userInp;  // Ru: поиск максимального значения | Eng: finding the maximum value
		userInp = userInp / 10;  // Ru: удаление последней цифры числа | Eng: removing the last digit from the number
	}
	cout << "result: " << max << endl;
}

void taskII()
{
	//dont do yet
}

void taskIII()
{
	//dont do yet
}

void Menu()
{
	int choice;

	// Ru: бесконечный цикл для работы меню | Eng: infinite loop for menu operation
	while (true) {
		
		cout << "\nSelect task: \n 1 - Task I \n 1 - Task II \n 1 - Task III" << endl;
		cout << "" << endl;

		cin >> choice;

		// Ru: закомментированные варианты выбора задач | Eng: commented task selection options
		// cout << "2 - Task II" << endl;
		// cout << "3 - Task III" << endl;
		// cout << "4 - Task IV" << endl;
		// cout << "5 - Task V" << endl;
		// cout << "6 - Task VI" << endl;
		// cout << "7 - Task VII" << endl;
		// cout << "8 - Task VIII" << endl;
		// cout << "9 - Task IX" << endl;
		// cout << "10 - Task X" << endl;
		
		// Ru: выбор задачи через switch | Eng: task selection using switch
		switch (choice)
		{
		case 1:
			taskI();
			break;  // Ru: важно добавить break для предотвращения проваливания | Eng: important to add break to prevent fall-through
			//case 2:
			//	taskII();
			//case 3:
			//	taskIII();
		}
	}
}

//---------------------------------------

int main()
{
	setlocale(LC_ALL, "ru");  // Ru: установка русской локали | Eng: setting Russian locale
	Menu();  // Ru: запуск главного меню программы | Eng: starting the program's main menu
}
