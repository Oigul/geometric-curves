#include "..\include\Ellipse.h"
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(double Rx, double Ry, Point3D basePoint)
	: m_dRx(Rx), m_dRy(Ry), m_BasePoint3D(basePoint) 
{
	if (m_dRx <= 0 || m_dRy <= 0)
		throw std::invalid_argument("Incorrect data");
}

Point3D Ellipse::getPoint(double t) const
{
	Point3D point3D(0, 0, 0);

	point3D.m_x = m_BasePoint3D.m_x + m_dRx * std::cos(t);
	point3D.m_y = m_BasePoint3D.m_y + m_dRy * std::sin(t);
	//z = 0;

	return point3D;
}

Vector3D Ellipse::getDerivative(double t) const
{
	Vector3D vector3D(0, 0, 0);
	vector3D.m_x = (-1) * m_dRx * std::sin(t);
	vector3D.m_y = m_dRy * std::cos(t);
	//z = 0;

	return vector3D;
}
