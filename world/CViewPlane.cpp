/*
 * CViewPlane.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CViewPlane.h"

CViewPlane::CViewPlane() {
	hres = 0;
	vres = 0;
	size = 0;
	nSamples = 0;
	sampler = nullptr;
	depth = 0;
}

CViewPlane::~CViewPlane() {
}

void CViewPlane::SetHorizontalResolution(int _h) {
	hres = _h;
}

void CViewPlane::SetVerticalResolution(int _v) {
	vres = _v;
}

void CViewPlane::SetPixelSize(double _s) {
	size = _s;
}

void CViewPlane::SetNumSamples(int _n) {
	nSamples = _n;
}

void CViewPlane::SetSampler(CSampler* _sampler) {
	sampler = _sampler;
}

void CViewPlane::SetMaxDepth(double _d) {
	depth = _d;
}
