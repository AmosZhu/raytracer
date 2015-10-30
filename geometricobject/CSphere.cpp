/*
 * CSphere.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CSphere.h"

CSphere::CSphere() {
}

CSphere::~CSphere() {
}

CSphere* CSphere::Clone() const {
	CSphere* sphere = new CSphere();
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

bool CSphere::Hit(const CRay& ray) {
	return false;
}
