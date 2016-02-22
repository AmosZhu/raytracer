/*
 * CRGBColor.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CRGBColor.h"

CRGBColor::CRGBColor() :
		r(0), g(0), b(0) {
}

CRGBColor::CRGBColor(const CRGBColor& _rhs) :
		r(_rhs.r), g(_rhs.g), b(_rhs.b) {
}

CRGBColor::CRGBColor(CRGBColor&& _rhs) :
		r(_rhs.r), g(_rhs.g), b(_rhs.b) {
	_rhs.r = 0;
	_rhs.g = 0;
	_rhs.b = 0;
}

CRGBColor::CRGBColor(int _c) :
		r(_c), g(_c), b(_c) {
}

CRGBColor::CRGBColor(int _r, int _g, int _b) :
		r(_r), g(_g), b(_b) {
}

CRGBColor::~CRGBColor() {
	r = 0;
	g = 0;
	b = 0;
}

CRGBColor& CRGBColor::operator=(const CRGBColor& _rhs) {
	if (this == &_rhs) {
		return *this;
	}
	r = _rhs.r;
	g = _rhs.g;
	b = _rhs.b;

	return *this;
}

CRGBColor& CRGBColor::operator+=(const CRGBColor& _rhs) {
	r += _rhs.r;
	g += _rhs.g;
	b += _rhs.b;
	return *this;
}

CRGBColor& CRGBColor::operator/=(const int& _s) {
	r /= _s;
	g /= _s;
	b /= _s;
	return *this;
}

CRGBColor& CRGBColor::operator/=(const CRGBColor& _rhs) {
	r /= _rhs.r;
	g /= _rhs.g;
	b /= _rhs.b;
	return *this;
}
