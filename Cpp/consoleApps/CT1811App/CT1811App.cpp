#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

void TaskI() 
{
	int i;

	int nums[15]{};
	
	vector<int> v;

	for (i = 0; i < size(nums); i++) {
		nums[i] = rand();
	}

	while (next_permutation(v.begin(), v.end()))
	{
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, ""));
		cout << endl;
	}


}

void TaskII() 
{
	int num[10]{ 1,2,3,4,5,6,7,8,9,0 };

	char lletter[26]{ 'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m' };
	char bletter[26]{ 'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M' };
	char symb[7]{ '!','@','#','$','%','&','*' };




}

void TaskIII() {

}

void TaskIV() {

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