/*
 * CRenderPixel.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CRenderPixel.h"

CRenderPixel::CRenderPixel(int _x, int _y, int _r, int _g, int _b) :
		x(_x), y(_y), r(_r), g(_g), b(_b) {
}

CRenderPixel::CRenderPixel(const CRenderPixel& rhs) :
		x(rhs.x), y(rhs.y), r(rhs.r), g(rhs.g), b(rhs.b) {
}

CRenderPixel::CRenderPixel(CRenderPixel&& rhs) :
		x(rhs.x), y(rhs.y), r(rhs.r), g(rhs.g), b(rhs.b) {
}

CRenderPixel::~CRenderPixel() {
}

