#pragma once
#include "Vector3.h"

class Quaternion
{
	//Operators
	friend Quaternion operator+(const Quaternion &q1, const Quaternion &q2);
	friend Quaternion operator-(const Quaternion &q);
	friend Quaternion operator-(const Quaternion &q1, const Quaternion &q2);
	friend Quaternion operator*(const Quaternion &q1, const Quaternion &q2);
	friend Quaternion operator*(const Quaternion &q1, const double &s);
	friend Quaternion operator*(const Quaternion &q1, const float &s);
	friend Quaternion operator*(const Quaternion &q1, const int &s);
	friend Quaternion operator*(const double &s, const Quaternion &q1);
	friend Quaternion operator*(const float &s, const Quaternion &q1);
	friend Quaternion operator*(const int &s, const Quaternion &q1);

public:
	//Constructors
	Quaternion(double _w = 0, double _x = 0, double _y = 0, double _z = 0);
	Quaternion(double _w, Vector3 v);

	//Functions
	std::string toString();
	double Modulus();
	Quaternion Normalise();
	Quaternion Conjugate();
	Quaternion Multiply(Quaternion _q);
	Quaternion Copy();
	Vector3 Rotate(Vector3 pt, int _angle);
	void FromAxisAngle(Vector3 axis, double angleRadian);

private:
	double x;
	double y;
	double z;
	double w;
};