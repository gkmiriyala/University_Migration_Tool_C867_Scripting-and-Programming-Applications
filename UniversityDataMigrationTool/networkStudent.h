#include <iostream>
#include "student.h"


class NetworkStudent : public Student 
{
public: degree degreeType = NETWORK;
public: 
	NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[3]);
	degree getDegree();
};
