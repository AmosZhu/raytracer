/*
 * CSingleSphere.cpp
 *
 *  Created on: Oct 31, 2015
 *      Author: Dizhong.Zhu
 */

#include "CSingleSphere.h"
#include "CWorld.h"

CSingleSphere::CSingleSphere() :
		CTracer() {
}

CSingleSphere::CSingleSphere(CWorld* world) :
		CTracer(world) {
}

CSingleSphere::~CSingleSphere() {
}

CRGBColor CSingleSphere::Trace_Ray(const CRay& ray) {
	double tmin;
	CShadeRec sr(m_world);
	if (m_world->sphere.Hit(ray, tmin,sr)) {
		return CRGBColor(255, 0, 0);
	} else {
		return CRGBColor(0, 0, 0);
	}
}

