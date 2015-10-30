/*
 * CTracer.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CTracer.h"

CTracer::CTracer() {
	m_world = nullptr;
}

CTracer::CTracer(CWorld* world) {
	m_world = world;
}

CTracer::~CTracer() {
	m_world = nullptr;
}

CRGBColor CTracer::Trace_Ray(const CRay& ray) {
	return CRGBColor(0, 0, 0);
}

