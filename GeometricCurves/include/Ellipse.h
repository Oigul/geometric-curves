#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
public:
	Ellipse(double Rx, double Ry, Point3D basePoint = Point3D(0, 0, 0));

	Point3D getPoint(double t) const override;
	Vector3D getDerivative(double t) const override;

	double getRadiusX() const { return m_dRx; }
	double getRadiusY() const { return m_dRy; }

private:
	double m_dRx;
	double m_dRy;

	Point3D m_BasePoint3D;


};

