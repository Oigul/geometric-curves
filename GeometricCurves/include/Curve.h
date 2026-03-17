#pragma once
#include "..\include\GeometryTypes.h"

class Curve
{
public:
	Curve() {}
	virtual ~Curve() = default;

	virtual Point3D getPoint(double t) const = 0;
	virtual Vector3D getDerivative(double t) const = 0;

protected:
	//Point3D m_BasePoint;
};

