#pragma once
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "roster.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
using namespace std;

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Ganesh,Miriyala,gkmiriyala@gmail.com,33,12,13,14,SOFTWARE" };

Roster::Roster() {
	count = 0;
};

Roster::~Roster() {
	cout << "Releasing memory";
};

//Extracting numeric value from string
int parseNumber(string numString) {
	int numb;
	istringstream(numString) >> numb;
	return numb;
};

//Extracting Number of Days as an array of integers from an array of strings
int *parseDays(string numString[3]) {
	int numb[3];
	numb[0] = parseNumber(numString[0]);
	numb[1] = parseNumber(numString[1]);
	numb[2] = parseNumber(numString[2]);
	return numb;
};

//Extracting degree type from string
degree parseDegreeType(string word) {
	if (word == "SOFTWARE") {
		return SOFTWARE;
	}
	else if (word == "SECURITY") {
		return SECURITY;
	}
	else if (word == "NETWORK") {
		return NETWORK;
	}
};

//Main program
void main() {
	Roster classRoster;
	classRoster.classRosterArray = new Student[5];
	for (int i = 0; i < 5; i++) {
		int j = 0;
		int stringStart = 0;
		int noOfChar = 0;
		int noOfWords = 0;
		string stringArray[9];
		while (j < studentData[i].length()) {
			if (noOfWords == 0 || noOfWords == 8) {
				if (studentData[i].at(j) == ',') {
					stringArray[noOfWords] = studentData[i].substr(stringStart, noOfChar);
					noOfChar = 0;
					noOfWords++;
					stringStart = j;
				}
				else if (j == studentData[i].length() - 1) {
					stringArray[noOfWords] = studentData[i].substr(stringStart + 1, noOfChar);
					noOfChar = 0;
					noOfWords++;
					stringStart = j;
				}
				noOfChar++;
				j++;
			}
			else {
				if (studentData[i].at(j) == ',') {
					stringArray[noOfWords] = studentData[i].substr(stringStart+1, noOfChar-1);
					noOfChar = 0;
					noOfWords++;
					stringStart = j;
				}
				else if (j == studentData[i].length() - 1) {
					stringArray[noOfWords] = studentData[i].substr(stringStart, noOfChar);
					noOfChar = 0;
					noOfWords++;
					stringStart = j;
				}
				noOfChar++;
				j++;
			}
		}
		int numb[3];
		numb[0] = parseNumber(stringArray[5]);
		numb[1] = parseNumber(stringArray[6]);
		numb[2] = parseNumber(stringArray[7]);
		classRoster.add(stringArray[0], stringArray[1], stringArray[2], stringArray[3], parseNumber(stringArray[4]), numb, parseDegreeType(stringArray[8]));
	}
	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (int i = 0; i < classRoster.getCount(); i++) {
		classRoster.printDaysInCourse(classRoster.classRosterArray[i].getStudentID());
	}
	cout << "\n\n";
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "\n\n";
	classRoster.remove("A3");
	cout << "\n\n";
	classRoster.printAll();
	cout << "\n\n";
	classRoster.remove("A3");
	cout << "\n\n";
	classRoster.~Roster();
};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int days[3], degree degreeType) {
	
	if (degreeType == NETWORK) {
		NetworkStudent student = NetworkStudent(studentID, firstName, lastName, emailAddress, age, days);
		if (count > 5) {
			cout << "Database is full";
		}
		else {
			classRosterArray[count] = student;
			count++;
		}

	}
	else if (degreeType == SOFTWARE) {
		SoftwareStudent student = SoftwareStudent(studentID, firstName, lastName, emailAddress, age, days);
		if (count > 5) {
			count = 0;
		}
		else {
			classRosterArray[count] = student;
			count++;
		}
	}
	else if (degreeType == SECURITY) {
		SecurityStudent student = SecurityStudent(studentID, firstName, lastName, emailAddress, age, days);
		if (count > 5) {
			count = 0;
		}
		else {
			classRosterArray[count] = student;
			count++;
		}
	}
};

//Remove entry from Student Table
void Roster::remove(string studentID) {
	Student *tempArray = new Student[4];
	for (int i = 0; i < getCount(); i++)
	{
		if (classRosterArray[i].getStudentID() == studentID) {
			int tempArraySize = getCount();
			for (int j = i + 1; j < tempArraySize; j++) {
				tempArray[i] = classRosterArray[j];
				i++;
			}
			classRosterArray = new Student[4];
			count--;
			for (int i = 0; i < getCount(); i++)
			{
				classRosterArray[i] = tempArray[i];
			}
			return;
		}
		else {
			tempArray[i] = classRosterArray[i];
		}
	}

	cout << "Student with specified student ID not found";
};

//print all student data
void Roster::printAll() {
	for (int i = 0; i < getCount(); i++)
	{
		classRosterArray[i].print();
	}
	cout << "\n\n";
};

//print average days in all courses
void Roster::printDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i].getStudentID() == studentID) {
			int dayOne = classRosterArray[i].getDays()[0];
			int dayTwo = classRosterArray[i].getDays()[1];
			int dayThree = classRosterArray[i].getDays()[2];
			int averageDays = (dayOne + dayTwo + dayThree) / 3;
			cout << "student Id: " << studentID << "\tDays in course: " << averageDays;
		}
	}
	cout << "\n";
};


//check whether email is valid
//A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
bool Roster::checkEmailInvalid(string email) {
	//need to implement this
	char characters[5] = { ' ' };
	if (!isalpha(email.at(0))) {
		return false;
	}
	for (int i = 1; i < email.length()-1; i++) {
		if (email.at(i) == ' ') {
			return false;
		}
		else if (email.at(i) == '@') {
			characters[0] = email.at(i - 1);
			characters[1] = email.at(i);
		}
		else if (email.at(i) == '.') {
			characters[2] = email.at(i - 1);
			characters[3] = email.at(i);
			characters[4] = email.at(i+1);
		}
	}
	if (!isalnum(characters[0]) || characters[1] != '@' || !isalnum(characters[2]) || characters[3] != '.' || !isalnum(characters[4])) {
		return false;
	}
	return true;
};

//Loop through entire classRoster, validate emails and print out only Invalid emails with statement saying that it is invalid
void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++)
	{
		if (!checkEmailInvalid(classRosterArray[i].getEmailAddress())) {
			cout << classRosterArray[i].getEmailAddress() << " is Invalid " << "\n";
		}
	}
	cout << "\n\n";
};

//Prints out student information for a degree program specified by an enumerated type
void Roster::printByDegreeProgram(degree degreeProgram) {
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i].getDegree() == degreeProgram)
		classRosterArray[i].print();
	}
};

//return the Class Roster Array
Student Roster::getClassRosterArray() {
	return *classRosterArray;
};

//get the count of the number of entries in the class roster
int Roster::getCount() {
	return count;
};