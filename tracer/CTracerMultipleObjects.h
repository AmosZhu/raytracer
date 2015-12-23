/*
 * CTracerMultipleObjects.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CTRACERMULTIPLEOBJECTS_H_
#define CTRACERMULTIPLEOBJECTS_H_

#include "CTracer.h"

class CTracerMultipleObjects: public CTracer {
public:
	CTracerMultipleObjects();
	CTracerMultipleObjects(CWorld* _world);
	~CTracerMultipleObjects();

	CRGBColor Trace_Ray(const CRay& _ray);
};

#endif /* CTRACERMULTIPLEOBJECTS_H_ */
