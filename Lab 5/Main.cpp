#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix3.h"
#include <iostream>
//Lab 5
//Daryl keogh

int main()
{
	Vector3 v1(1, 1, 2);
	Vector3 v2(2, 3, 4);
	float ans = v1 * v2;

	Quaternion q1(1, 1, 2, 3);
	Quaternion q2(2, 1, 3, 4);

	Quaternion q3 = q1 * q2;

	Matrix3 m1(1, 0, 0, 0, 1, 0, 0, 0, 1);
	Matrix3 m2(2, 0, 0, 0, 2, 0, 0, 0, 2);
	Matrix3 matrixAns = m1 * m2;

}