#include "..\include\Helix.h"
#include <cmath>
#include <stdexcept>

Helix::Helix(double R, int step, Point3D basePoint)
	: m_dR(R), m_step(step), m_BasePoint3D(basePoint) 
{
	if (m_dR <= 0 || m_step <= 0)
		throw std::invalid_argument("Incorrect data");

	m_k = m_step / (2 * PI);
}

Point3D Helix::getPoint(double t) const
{
	Point3D point3D(0, 0, 0);

	point3D.m_x = m_BasePoint3D.m_x + m_dR * std::cos(t);
	point3D.m_y = m_BasePoint3D.m_y + m_dR * std::sin(t);
	point3D.m_z = m_BasePoint3D.m_z + m_k * t;

	return point3D;
}

Vector3D Helix::getDerivative(double t) const
{
	Vector3D vector3D(0, 0, 0);
	vector3D.m_x = (-1) * m_dR * std::sin(t);
	vector3D.m_y = m_dR * std::cos(t);
	vector3D.m_z = m_k;

	return vector3D;
}
