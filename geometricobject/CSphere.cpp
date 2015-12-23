/*
 * CSphere.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CSphere.h"
#include <math.h>
#include "common.h"

CSphere::CSphere() {
}

CSphere::CSphere(CPoint3D _center, double _radius) {
	m_center = _center;
	m_radius = _radius;
}

CSphere::~CSphere() {
}

CSphere* CSphere::Clone() const {
	CSphere* sphere = new CSphere(*this);
	return sphere;
}

void CSphere::SetCenter(CPoint3D center) {
	m_center = center;
}

void CSphere::SetCenter(double _x, double _y, double _z) {
	m_center.x = _x;
	m_center.y = _y;
	m_center.z = _z;
}

void CSphere::SetRadius(double radius) {
	m_radius = radius;
}

bool CSphere::Hit(const CRay& _ray, double& _tmin,CShadeRec& _sr) {
	CVector3D A = _ray.o - m_center;
	double a = _ray.d * _ray.d;
	double b = 2.0 * _ray.d * A;
	double c = A * A - m_radius * m_radius;

	double disc = b * b - 4 * a * c;

	if (disc <= 0) {
		return false;
	} else {
		double temp = sqrt(disc);
		double numerator = -b - temp;

		if (numerator > KEPSILON) {
			_tmin = numerator / (2 * a);
			return true;
		}

		numerator = -b + temp;
		if (numerator > KEPSILON) {
			_tmin = numerator / (2 * a);
			return true;
		}
	}

	return false;
}
