#pragma once
#include <iostream>
#include <string> // string functions
#include "degree.h"


using namespace std;

class Student {
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[3];
	degree degreeType;

	public: Student();

	public: Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[3], degree degreeType);

	~Student();

	void setStudentID(string studentID);

	string getStudentID();

	void setFirstName(string firstName);

	string getFirstName();

	void setLastName(string lastName);

	string getLastName();

	void setEmailAddress(string emailAddress);

	string getEmailAddress();

	void setAge(int age);

	int getAge();

	void setDays(int days[3]);

	int* getDays();
	
	void setDegree(degree degreeType);

	virtual degree getDegree();

	virtual void print();
};