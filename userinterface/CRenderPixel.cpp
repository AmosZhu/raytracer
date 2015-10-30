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

CRenderPixel::CRenderPixel(const CRenderPixel& obj) :
		x(obj.x), y(obj.y), r(obj.r), g(obj.g), b(obj.b) {
}

CRenderPixel::CRenderPixel(CRenderPixel&& obj) :
		x(obj.x), y(obj.y), r(obj.r), g(obj.g), b(obj.b) {
}

CRenderPixel::~CRenderPixel() {
}

