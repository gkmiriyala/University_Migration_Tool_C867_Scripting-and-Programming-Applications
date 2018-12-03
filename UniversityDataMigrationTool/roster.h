#pragma once
#include <iostream>
#include <stdio.h>
#include "student.h"

class Roster {
	int count;
public: Student *classRosterArray;

public: Roster();

public: ~Roster();

public: 
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int days[3], degree degreeType);

public: 
	void remove(string studentID);

public:
	Student getClassRosterArray();

public: int getCount();

public: void printAll();

public: void printDaysInCourse(string studentID);

public: void printAverageDaysInCourse(Roster classRoster);

public: bool checkEmailInvalid(string email);

public: void printInvalidEmails();

public: void printByDegreeProgram(degree degreeProgram);
};

