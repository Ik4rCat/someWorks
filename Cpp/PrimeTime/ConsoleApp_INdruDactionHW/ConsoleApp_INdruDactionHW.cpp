#include <iostream>

#include "Student.h"

using namespace std;

int main()
{
	Student student("John", "Doe", "New York", "USA", "NYU", 20, 20010101, 1234567890);
	
	cout << "Name: " << student.getName() << endl;
	cout << "City: " << student.getCity() << endl;
	cout << "Country: " << student.getContry() << endl;
	cout << "School: " << student.getSchool() << endl;
	cout << "Age: " << student.getAge() << endl;
	cout << "Birthday: " << student.getbirthday() << endl;
	cout << "Phone Number: " << student.getPhoneNumber() << endl;

}