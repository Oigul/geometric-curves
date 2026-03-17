#pragma once
#include "Curve.h"

class Circle : public Curve
{
public:
	Circle(double R, Point3D basePoint = Point3D(0, 0, 0));

	Point3D getPoint(double t) const override;
	Vector3D getDerivative(double t) const override;

	double getRadius() const { return m_dR; }

private:
	double m_dR;

	Point3D m_BasePoint3D;
};

