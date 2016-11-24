#pragma once
#include "Vector3.h"
//Lab 5
//Daryl keogh
//Student ID: C00207452
//Description: Converting the 3 classes (Matrix3, Quaternion & Vector3) to C++ and testing their using by multiplying each type by the appropriate values.
//Time Spent: 2 Hours
class Matrix3
{
	//operators
	friend Vector3 operator*(const Matrix3 &M1, Vector3 &V1);
	friend Vector3 operator*(Vector3 &V1, const Matrix3 &M1);
	friend Matrix3 operator+(const Matrix3 &M1, const Matrix3 &M2);
	friend Matrix3 operator-(const Matrix3 &M1, const Matrix3 &M2);
	friend Matrix3 operator*(const double &x, const Matrix3 &M1);
	friend Matrix3 operator*(const Matrix3 &M1, const Matrix3 &M2);
	friend Matrix3 operator-(const Matrix3 &M1);

public:
	//Constructors
	Matrix3();
	Matrix3(Vector3 row1, Vector3 row2, Vector3 row3);
	Matrix3(double _A11, double _A12, double _A13,
		double _A21, double _A22, double _A23,
		double _A31, double _A32, double _A33);

	//Functions
	double Determinant(Matrix3 &M1);
	Vector3 Row(int i) const;
	Vector3 Column(int i) const;
	Matrix3 Inverse(Matrix3 &M1);
	Matrix3 Rotation(int &angle);
	Matrix3 Translate(int &dx, int &dy);
	Matrix3 Scale(int &dx, int &dy);
	Matrix3 RotationX(int &angle);
	Matrix3 RotationY(int &angle);
	Matrix3 RotationZ(int &angle);
	Matrix3 Scale3D(int &dx);
	Matrix3 Transpose(Matrix3 &M1);

private:
	// The class has nine variables, 3 rows and 3 columns
	double A11;
	double A12;
	double A13;
	double A21;
	double A22;
	double A23;
	double A31;
	double A32;
	double A33;
};