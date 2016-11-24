#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Vector3
{
	friend Vector3 operator+(const Vector3 &v1,const Vector3 &v2);
	friend Vector3 operator-(const Vector3 &v1, const Vector3 &V2);
	friend Vector3 operator-(const Vector3 &v);
	friend double operator*(const Vector3 &v1, const Vector3 &V2);
	friend Vector3 operator*(const double &k, const Vector3 &v1);
	friend Vector3 operator*(const float &k, const Vector3 &v1);
	friend Vector3 operator*(const int &k, const Vector3 &v1);
	friend Vector3 operator^(const Vector3 &v1, const Vector3 &V2);

public:
	//Constructors
	Vector3(double x1 = 0, double y1 = 0, double z1 = 0);
	Vector3(Vector3 &V);

	//Functions
	double Length();
	double LengthSquared();
	void Normalise();

	//Setters & Getters
	double& getX();
	void setX(double &val);
	double& getY();
	void setY(double &val);
	double& getZ();
	void setZ(double &val);

	std::string toString();

private:
	double x;
	double y;
	double z;
};