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

CRGBColor::CRGBColor(const CRGBColor& obj) :
		r(obj.r), g(obj.g), b(obj.b) {
}

CRGBColor::CRGBColor(CRGBColor&& obj) :
		r(obj.r), g(obj.g), b(obj.b) {
	obj.r = 0;
	obj.g = 0;
	obj.b = 0;
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

CRGBColor& CRGBColor::operator=(const CRGBColor& obj) {
	if (this == &obj) {
		return *this;
	}
	r = obj.r;
	g = obj.g;
	b = obj.b;

	return *this;
}
