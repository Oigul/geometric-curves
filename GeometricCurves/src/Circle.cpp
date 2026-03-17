#include "..\include\Circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(double R, Point3D basePoint)
	: m_BasePoint3D(basePoint), m_dR(R) 
{
	if(m_dR <= 0)
		throw std::invalid_argument("Incorrect data");
}

Point3D Circle::getPoint(double t) const
{
	Point3D point3D(0, 0, 0);
	
	point3D.m_x = m_BasePoint3D.m_x +  m_dR * std::cos(t);
	point3D.m_y = m_BasePoint3D.m_y + m_dR * std::sin(t);
	//z = 0

	return point3D;
}

Vector3D Circle::getDerivative(double t) const
{
	Vector3D vector3D(0, 0, 0);
	vector3D.m_x = (-1) * m_dR * std::sin(t);
	vector3D.m_y = m_dR * std::cos(t);
	//z = 0

	return vector3D;
}

