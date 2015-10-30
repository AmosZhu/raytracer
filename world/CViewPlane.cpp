/*
 * CViewPlane.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CViewPlane.h"

CViewPlane::CViewPlane() {
}

CViewPlane::~CViewPlane() {
}

void CViewPlane::SetHorizontalResolution(int h) {
	hres = h;
}

void CViewPlane::SetVerticalResolution(int v) {
	vres = v;
}

void CViewPlane::SetPixelSize(double s) {
	size = s;
}

