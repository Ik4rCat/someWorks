#include <iostream>
#include "Student.h"

Student::Student(std::string fName, std::string lName, 
	std::string city, std::string contry, 
	std::string school, 
	int age, int birthday, int phoneNumber) : fName(fName), lName(lName), city(city), contry(contry), school(school), age(age), birthday(birthday), phoneNumber(phoneNumber) {}

//get & set
std::string Student::getName() const { return fName + " " + lName; }
void Student::setName(std::string fName, std::string lName) { this->fName = fName; this->lName = lName; }

std::string Student::getCity() const { return city; }
void Student::setCity(std::string city) { this->city = city; }

std::string Student::getContry() const { return contry; }
void Student::setContry(std::string contry) { this->contry = contry; }

std::string Student::getSchool() const { return school; }
void Student::setSchool(std::string school) { this->school = school; }

int Student::getAge() const { return age; }
void Student::setAge(int age) { this->age = age; }

int Student::getbirthday() const { return birthday; }
void Student::setbirthday(int birthday) { this->birthday = birthday; }

int Student::getPhoneNumber() const { return phoneNumber; }
void Student::setPhoneNumber(int phoneNumber) { this->phoneNumber = phoneNumber; }
