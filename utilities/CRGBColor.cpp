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

CRGBColor::CRGBColor(const CRGBColor& rhs) :
		r(rhs.r), g(rhs.g), b(rhs.b) {
}

CRGBColor::CRGBColor(CRGBColor&& rhs) :
		r(rhs.r), g(rhs.g), b(rhs.b) {
	rhs.r = 0;
	rhs.g = 0;
	rhs.b = 0;
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

CRGBColor& CRGBColor::operator=(const CRGBColor& rhs) {
	if (this == &rhs) {
		return *this;
	}
	r = rhs.r;
	g = rhs.g;
	b = rhs.b;

	return *this;
}
