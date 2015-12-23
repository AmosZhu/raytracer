/*
 * CTracer.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CTRACER_H_
#define CTRACER_H_

#include "CRGBColor.h"
#include "CRay.h"

class CWorld;

class CTracer {
public:
	CTracer();
	CTracer(CWorld* world);
	virtual ~CTracer();

	virtual CRGBColor Trace_Ray(const CRay& ray);

protected:
	CWorld* m_world;
};

#endif /* CTRACER_H_ */
