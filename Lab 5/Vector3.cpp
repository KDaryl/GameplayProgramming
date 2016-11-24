#include "Vector3.h"
//Lab 5
//Daryl keogh
//Student ID: C00207452
//Description: Converting the 3 classes (Matrix3, Quaternion & Vector3) to C++ and testing their using by multiplying each type by the appropriate values.
//Time Spent: 2 Hours

//Constructors
Vector3::Vector3(double x1, double y1, double z1) :
	x(x1),
	y(y1),
	z(z1)
{
}

Vector3::Vector3(Vector3 &V) :
	x(V.x),
	y(V.y),
	z(V.z)
{
}

//Functions
double Vector3::Length()
{
	return sqrt(x * x + y * y + z * z);
}

double Vector3::LengthSquared()
{
	return x * x + y * y + z * z;
}

void Vector3::Normalise()
{
	if (Length() > 0.0)
	{  // Check for divide by zero
		double magnit = Length();
		x /= magnit;
		y /= magnit;
		z /= magnit;
	}
}

//Operators
Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
{
	return (v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vector3 operator-(const Vector3 &v1, const Vector3 &v2)
{
	return (v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
//Returns the negation of the vector
Vector3 operator-(const Vector3 &v)
{
	return (-v.x, -v.y, -v.z);
}
double operator*(const Vector3 &v1, const Vector3 &v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
Vector3 operator*(const double &k, const Vector3 &v1)
{
	return (v1.x * (float)k, v1.y * (float)k, v1.z * (float)k);
}
Vector3 operator *(const float &k, const Vector3 &v1)
{
	return (v1.x * k, v1.y * k, v1.z * k);
}
Vector3 operator *(const int &k, const Vector3 &v1)
{
	return (v1.x * k, v1.y * k, v1.z * k);
}

Vector3 operator ^(const Vector3 &v1, const Vector3 &V2)
{
	return (v1.y * V2.z - v1.z * V2.y, v1.z * V2.x - v1.x * V2.z, v1.x * V2.y - v1.y * V2.x);
}

std::string Vector3::toString()
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

//Getters
double& Vector3::getX()
{
	return x;
}
double& Vector3::getY()
{
	return y;
}
double& Vector3::getZ()
{
	return z;
}

//Setters
void Vector3::setX(double &val)
{
	x = val;
}
void Vector3::setY(double &val)
{
	y = val;
}
void Vector3::setZ(double &val)
{
	z = val;
}