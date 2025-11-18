#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

void TaskI() 
{
	int nums[15]{};
	vector<int> v;

	for (int i = 0; i < size(nums); i++) {
		nums[i] = rand();
	}

	copy(begin(nums), end(nums), back_inserter(v));

	sort(v.begin(), v.end());

	do {
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));

}

void TaskII() 
{
	int i;

	int num[10]{ 1,2,3,4,5,6,7,8,9,0 };
	int setSizes[] = { 10, 26, 26, 7 };

	char lletter[26]{ 'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m' };
	char bletter[26]{ 'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M' };
	char symb[7]{ '!','@','#','$','%','&','*' };
	char pass[9]{};

	char* charSets[] = {
	reinterpret_cast<char*>(num),
	lletter,
	bletter,
	symb
	};

	for (int i = 0; i < size(pass) - 1; i++) { 
		int setIndex = rand() % 4;

		int charIndex = rand() % setSizes[setIndex];

		if (setIndex == 0) {
			pass[i] = '0' + num[charIndex];
		}
		else {
			pass[i] = charSets[setIndex][charIndex];
		}
	}

	pass[8] = '\0';

	cout << "pass: " << pass << endl;

}

void TaskIII()  
{


	int number = 0;
	int temp = number;
	int divisor = 2;
	vector<int> factors;

	cout << "Enter natur num: ";
	cin >> number;

	if (number <= 1) {
		cout << "need num bigger 1 !" << endl;
		return;
	}

	cout << "\nprocess on mini nums:" << endl;
	cout << number;

	while (temp > 1) {
		if (temp % divisor == 0) {
			factors.push_back(divisor);
			temp /= divisor;
			cout << " | " << divisor << endl;
			if (temp > 1) {
				cout << temp;
			}
		}
		else {
			divisor++;
			if (divisor > 2 && divisor % 2 == 0) divisor++;
		}
	}

	cout << " | 1" << endl << endl;
	cout << number << " = ";

	for (size_t i = 0; i < factors.size(); ++i) {
		cout << factors[i];
		if (i < factors.size() - 1) {
			cout << " * ";
		}
	}
	cout << endl;

}

void TaskIV() 
{
	cout << "in working (dont realized yet :( )" << endl;
}

int main()
{
	int userChoice = 0;

	srand(time(0));

	while (true)
	{

		cout << "\nChoice task: " << endl;
		cout << " 1 - task I" << endl;
		cout << " 2 - task II" << endl;
		cout << " 3 - task III" << endl;
		cout << " 4 - task IV" << endl;
		//cout << " 5 - task V" << endl;
		//cout << " 6 - task VI" << endl;
		//cout << " 7 - task VII" << endl;
		//cout << " 8 - task VIII" << endl;
		//cout << " 9 - task IX" << endl;
		//cout << " 10- task X" << endl;
		cout << " 0- exit" << endl;

		cin >> userChoice;

		switch (userChoice) {
		case 1:  TaskI(); break;
		case 2:  TaskII(); break;
		case 3:  TaskIII(); break;
		case 4:  TaskIV(); break;
		//case 5:  TaskV(); break;
		//case 6:  TaskVI(); break;
		//case 7:  TaskVII(); break;
		//case 8:  TaskVIII(); break;
		//case 9:  TaskIX(); break;
		//case 10: TaskX(); break;
		case 0: break;
		default:
			cout << "No such task. Please try again." << endl;
			break;
		}
	}
}