/*
 * CWorld.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CWorld.h"

CWorld::CWorld() {
	tracer_ptr=nullptr;
}

CWorld::~CWorld() {
}

void CWorld::Build() {
	vp.SetHorizontalResolution(200);
	vp.SetVerticalResolution(200);
	vp.SetPixelSize(1.0);

	bg_color=CRGBColor(0,0,0);

	tracer_ptr=new CTracer(this);

	sphere.SetCenter(0);
	sphere.SetRadius(85.0);

}

void CWorld::Render() {

}

