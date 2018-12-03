#include <iostream>
#include "networkStudent.h"

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[3]) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDays(days);
	setDegree(degreeType);
};

degree NetworkStudent::getDegree()
{
	return degreeType;
};