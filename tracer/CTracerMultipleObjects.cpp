/*
 * CTracerMultipleObjects.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author: Dizhong.Zhu
 */

#include "CTracerMultipleObjects.h"
#include "CWorld.h"
#include "CShadeRec.h"

CTracerMultipleObjects::CTracerMultipleObjects() :
		CTracer() {
}

CTracerMultipleObjects::CTracerMultipleObjects(CWorld* _world) :
		CTracer(_world) {
}

CTracerMultipleObjects::~CTracerMultipleObjects() {
}

CRGBColor CTracerMultipleObjects::Trace_Ray(const CRay& _ray) {
	CShadeRec sr(m_world->HitObjects(_ray));

	if (sr.isHit) {
		return sr.color;
	} else {
		return m_world->bg_color;
	}
}
