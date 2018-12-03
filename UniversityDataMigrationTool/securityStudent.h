#pragma once
#include <iostream>
#include "student.h"

class SecurityStudent : public Student
{
	degree degreeType = SECURITY;
public:
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[3]);

	degree getDegree();
};