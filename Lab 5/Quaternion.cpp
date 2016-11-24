#include "Quaternion.h"
//Lab 5
//Daryl keogh
//Student ID: C00207452
//Description: Converting the 3 classes (Matrix3, Quaternion & Vector3) to C++ and testing their using by multiplying each type by the appropriate values.
//Time Spent: 2 Hours

//Constructors
Quaternion::Quaternion(double _w, double _x, double _y, double _z) :
	w(_w),
	x(_x),
	y(_y),
	z(_z)
{
}
Quaternion::Quaternion(double _w, Vector3 v) :
	w(_w),
	x(v.getX()),
	y(v.getY()),
	z(v.getZ())
{
}

//Operators
Quaternion operator+(const Quaternion &q1, const Quaternion &q2)
{
	return Quaternion(q1.w + q2.w, q1.x + q2.x, q1.y + q2.y, q1.z + q2.z);
}
Quaternion operator-(const Quaternion &q1)
{
	return Quaternion(-q1.w, -q1.x, -q1.y, -q1.z);
}
Quaternion operator-(const Quaternion &q1, const Quaternion &q2)
{
	return Quaternion(q1.w - q2.w, q1.x - q2.x, q1.y - q2.y, q1.z - q2.z);
}
Quaternion operator*(const Quaternion &q1, const Quaternion &q2)
{
	double nw = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	double nx = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	double ny = q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z;
	double nz = q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x;
	return Quaternion(nw, nx, ny, nz);
}
Quaternion operator*(const Quaternion &q1, const double &s)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}
Quaternion operator*(const Quaternion &q1, const float &s)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}
Quaternion operator*(const Quaternion &q1, const int &s)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}
Quaternion operator*(const double &s, const Quaternion &q1)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}
Quaternion operator*(const float &s, const Quaternion &q1)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}
Quaternion operator*(const int &s, const Quaternion &q1)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

//Functions
double Quaternion::Modulus()
{
	return std::sqrt(w*w + x*x + y*y + z*z);
}
Quaternion Quaternion::Normalise()
{
	double m = w * w + x * x + y * y + z * z;
	if (m > 0.001)
	{
		m = std::sqrt(m);
		return Quaternion(w / m, x / m, y / m, z / m);
	}
	else
		return Quaternion(1, 0, 0, 0);
}
Quaternion Quaternion::Conjugate()
{
	return Quaternion(w, -x, -y, -z);
}
Quaternion Quaternion::Multiply(Quaternion _q)
{
	double nw = _q.w *  w - _q.x *  x - _q.y *  y - _q.z *  z;
	double nx = _q.w *  x + _q.x *  w + _q.y *  z - _q.z *  y;
	double ny = _q.w *  y + _q.y *  w + _q.z *  x - _q.x *  z;
	double nz = _q.w *  z + _q.z *  w + _q.x *  y - _q.y *  x;
	return Quaternion(nw, nx, ny, nz);
}
Quaternion Quaternion::Copy()
{
	return Quaternion(w, x, y, z);
}
Vector3 Quaternion::Rotate(Vector3 pt, int _angle)
{
	Quaternion axis, rotate;
	axis = Normalise();
	double angleRad = acos(-1) / 180 * _angle;
	rotate = Quaternion(std::cos(angleRad / 2), std::sin(angleRad / 2) * axis.x, std::sin(angleRad / 2) * axis.y, std::sin(angleRad / 2) * axis.z);
	Quaternion conjugate = rotate.Conjugate();
	Quaternion qNode = Quaternion(0, pt.getX(), pt.getY(), pt.getZ());
	qNode = rotate * qNode * conjugate;
	return Vector3(qNode.x, qNode.y, qNode.z);
}
void Quaternion::FromAxisAngle(Vector3 axis, double angleRadians)
{
	double m = axis.Length();
	if (m > 0.0001)
	{
		double ca = std::cos(angleRadians / 2);
		double sa = std::sin(angleRadians / 2);
		x = axis.getX() / m * sa;
		y = axis.getY() / m * sa;
		z = axis.getZ() / m * sa;
		w = ca;
	}
	else
		w = 1; x = 0; y = 0; z = 0;
}

std::string Quaternion::toString()
{
	return "(" + std::to_string(w) + ", " + std::to_string(x) + "i, " + std::to_string(y) + "j, " + std::to_string(z) + "k)";
}