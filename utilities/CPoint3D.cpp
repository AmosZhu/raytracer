/*
 * CPoint3D.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CPoint3D.h"

CPoint3D::CPoint3D() :
		x(0), y(0), z(0) {
}

CPoint3D::CPoint3D(double _c) :
		x(_c), y(_c), z(_c) {
}

CPoint3D::CPoint3D(double _x, double _y, double _z) :
		x(_x), y(_y), z(_z) {
}

CPoint3D::CPoint3D(const CPoint3D& _rhs) :
		x(_rhs.x), y(_rhs.y), z(_rhs.z) {
}

CPoint3D::~CPoint3D() {
}

CPoint3D CPoint3D::operator*(const double _s) {
	return CPoint3D(x * _s, y * _s, z * _s);
}

CPoint3D CPoint3D::operator/(const double _s) {
	return CPoint3D(x / _s, y / _s, z / _s);
}

CPoint3D& CPoint3D::operator=(const CPoint3D& _rhs) {
	if (this == &_rhs) {
		return *this;
	}

	this->x = _rhs.x;
	this->y = _rhs.y;
	this->z = _rhs.z;

	return *this;
}

CVector3D CPoint3D::operator-(const CPoint3D& _rhs) const {
	return CVector3D(x - _rhs.x, y - _rhs.y, z - _rhs.z);
}

