#pragma once

const double PI = 3.14159265358979323846;

class Point3D
{

public:
	Point3D(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

	double m_x = 0;
	double m_y = 0;
	double m_z = 0;
};

class Vector3D
{

public:
	Vector3D(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

	double m_x = 0;
	double m_y = 0;
	double m_z = 0;
};

