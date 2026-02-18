#pragma once
#include <string>

class Student {
private:
	std::string fName, lName;
	std::string city, contry;
	std::string school;

	int age;
	int birthday;
	int phoneNumber;

public:
	Student(std::string fName, std::string lName,
		std::string city, std::string contry,
		std::string school,
		int age, int birthday, int phoneNumber);

	//get & set
	std::string getName() const;
	void setName(std::string fName, std::string lName);

	std::string getCity() const;
	void setCity(std::string city);

	std::string getContry() const;
	void setContry(std::string contry);

	std::string getSchool() const;
	void setSchool(std::string school);

	int getAge() const;
	void setAge(int age);

	int getbirthday() const;
	void setbirthday(int birthday);

	int getPhoneNumber() const;
	void setPhoneNumber(int phoneNumber);
};