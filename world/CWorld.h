/*
 * CWorld.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CWORLD_H_
#define CWORLD_H_

#include "CRGBColor.h"
#include "CViewPlane.h"
#include "CSphere.h"
#include "CTracer.h"

class CWorld {
public:
	CViewPlane vp;
	CTracer* tracer_ptr;
	CSphere sphere;
	CRGBColor bg_color;

public:
	CWorld();
	~CWorld();

	void Build();
	void Render();

};

#endif /* CWORLD_H_ */
