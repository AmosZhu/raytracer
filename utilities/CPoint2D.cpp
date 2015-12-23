/*
 * CPoint2D.cpp
 *
 *  Created on: Nov 3, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CPOINT2D_CPP_
#define CPOINT2D_CPP_

#include "CPoint2D.h"

CPoint2D::CPoint2D() :
		x(0), y(0) {
}

CPoint2D::CPoint2D(double _c) :
		x(_c), y(_c) {
}

CPoint2D::CPoint2D(double _x, double _y) :
		x(_x), y(_y) {
}

CPoint2D::CPoint2D(const CPoint2D& _rhs) :
		x(_rhs.x), y(_rhs.y) {
}

CPoint2D::~CPoint2D() {
}

CPoint2D CPoint2D::operator*(const double _s) {
	return CPoint2D(x * _s, y * _s);
}

CPoint2D CPoint2D::operator/(const double _s) {
	return CPoint2D(x / _s, y / _s);
}

CPoint2D& CPoint2D::operator=(const CPoint2D& _rhs) {
	if (this == &_rhs) {
		return *this;
	}
	x = _rhs.x;
	y = _rhs.y;

	return *this;
}

#endif /* CPOINT2D_CPP_ */
