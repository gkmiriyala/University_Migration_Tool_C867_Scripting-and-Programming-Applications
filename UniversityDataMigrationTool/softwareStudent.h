#pragma once
#include <iostream>
#include "student.h"

class SoftwareStudent : public Student
{
	degree degreeType = SOFTWARE;
public:
	SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[3]);

	virtual degree getDegree();
};