#include <iostream>
#include "securityStudent.h"

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[3]) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDays(days);
	setDegree(degreeType);
};

degree SecurityStudent::getDegree()
{
	return degreeType;
};