#pragma once
#include <iostream>
#include <string> // string functions
#include "degree.h"
#include "student.h"
using namespace std;

	Student::Student() {

	};

	Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[3], degree degreeType) {
		this->studentID = studentID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->emailAddress = emailAddress;
		this->age = age;
		this->days[0] = days[0];
		this->days[1] = days[1];
		this->days[2] = days[2];
		this->degreeType = degreeType;
	}

	Student::~Student()
	{

	}
	
	void Student::setStudentID(string studentID) {
		this->studentID = studentID;
	}

	string Student::getStudentID()
	{
		return studentID;
	}

	void Student::setFirstName(string firstName) {
		this->firstName = firstName;
	}

	string Student::getFirstName()
	{
		return firstName;
	}

	void Student::setLastName(string lastName)
	{
		this->lastName = lastName;
	}

	string Student::getLastName()
	{
		return lastName;
	}

	void Student::setEmailAddress(string emailAddress)
	{
		this->emailAddress = emailAddress;
	}

	string Student::getEmailAddress()
	{
		return emailAddress;
	}

	void Student::setAge(int age)
	{
		this->age = age;
	}

	int Student::getAge()
	{
		return age;
	}

	void Student::setDays(int days[3])
	{
		this->days[0] = days[0];
		this->days[1] = days[1];
		this->days[2] = days[2];
	}

	int* Student::getDays()
	{
		return days;
	}

	void Student::setDegree(degree degreeType)
	{
		this->degreeType = degreeType;
	}

	degree Student::getDegree()
	{
		return degreeType;
	}

	void Student::print() {
		cout << "Student ID: " << getStudentID()
			<< "\t First Name: " << getFirstName()
			<< "\t Last Name: " << getLastName()
			<< "\t Email Address: " << getEmailAddress()
			<< "\t Age: " << getAge()
			<< "\t Days in course: " << "{ " << getDays()[0] << ", " << getDays()[1] << ", " << getDays()[2] << " }"
			<< "\t Degree Program: " << getDegree()
			<< endl;
	};
