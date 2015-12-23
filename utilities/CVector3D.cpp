/*
 * CVector3D.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CVector3D.h"
#include <math.h>

CVector3D::CVector3D() {
}

CVector3D::CVector3D(double _c) :
		x(_c), y(_c), z(_c) {
}

CVector3D::CVector3D(double _x, double _y, double _z) :
		x(_x), y(_y), z(_z) {
}

CVector3D::~CVector3D() {
}

void CVector3D::Normalize() {
	double length = sqrt(x * x + y * y + z * z);
	x /= length;
	y /= length;
	z /= length;
}

CVector3D CVector3D::operator*(const double _s) const {
	return CVector3D(_s * x, _s * y, _s * z);
}

double CVector3D::operator*(const CVector3D& _rhs) const {
	return (x * _rhs.x + y * _rhs.y + z * _rhs.z);
}

CVector3D CVector3D::operator^(const CVector3D& _rhs) const {
	return CVector3D(y * _rhs.z - z * _rhs.y, z * _rhs.x - x * _rhs.z,
			x * _rhs.y - y * _rhs.x);
}

CVector3D CVector3D::operator+(const CVector3D& _rhs) const {
	return CVector3D(x + _rhs.x, y + _rhs.y, z + _rhs.z);
}

CVector3D CVector3D::operator-(const CVector3D& _rhs) const {
	return CVector3D(x -_rhs.x, y - _rhs.y, z -_rhs.z);
}

CVector3D operator*(const double _lhs, const CVector3D& _rhs) {
	return CVector3D(_lhs * _rhs.x, _lhs * _rhs.y, _lhs * _rhs.z);
}
