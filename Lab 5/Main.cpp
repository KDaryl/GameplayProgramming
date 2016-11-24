#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix3.h"
#include <iostream>
//Lab 5
//Daryl keogh
//Student ID: C00207452
//Description: Converting the 3 classes (Matrix3, Quaternion & Vector3) to C++ and testing their using by multiplying each type by the appropriate values.
//Time Spent: 2 Hours

int main()
{
	//Multiplying two vectors by each other and recording the output.
	Vector3 v1(1, 1, 2);
	Vector3 v2(2, 3, 4);
	float ans = v1 * v2;

	//Multiplying two Quaternions by each other and recording the output.
	Quaternion q1(1, 1, 2, 3);
	Quaternion q2(2, 1, 3, 4);

	Quaternion q3 = q1 * q2;

	//Multiplying two matrices by each other and recording the output.
	Matrix3 m1(1, 0, 0, 0, 1, 0, 0, 0, 1);
	Matrix3 m2(2, 0, 0, 0, 2, 0, 0, 0, 2);
	Matrix3 matrixAns = m1 * m2;

	std::cout << "V1 by V2 = " << ans << std::endl;
	std::cout << "Q1 by Q2 = " << q3.toString() << std::endl;

	system("PAUSE");
}