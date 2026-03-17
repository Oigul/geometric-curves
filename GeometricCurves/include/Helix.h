#pragma once
#include "Curve.h"

class Helix : public Curve
{
public:
	Helix(double R, int step, Point3D basePoint = Point3D(0, 0, 0));

	Point3D getPoint(double t) const override;
	Vector3D getDerivative(double t) const override;

	double getRadius() const { return m_dR; }
	double getStep() const { return m_step; }

private:
	double m_dR;
	int m_step;

	Point3D m_BasePoint3D;
	
	double m_k;
};

