/*
 * CSingleSphere.h
 *
 *  Created on: Oct 31, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CSINGLESPHERE_H_
#define CSINGLESPHERE_H_

#include "CTracer.h"


class CSingleSphere: public CTracer {
public:
	CSingleSphere();
	CSingleSphere(CWorld* world);
	~CSingleSphere();

	CRGBColor Trace_Ray(const CRay& ray);
};

#endif /* CSINGLESPHERE_H_ */
