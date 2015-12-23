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
#include "CDisplayScreen.h"
#include "CShadeRec.h"
#include "CCamera.h"

class CWorld {
public:
	CViewPlane vp;
	CTracer* tracer_ptr;
	CSphere sphere;
	CRGBColor bg_color;
	CCamera* camera_ptr;
public:
	CWorld();
	~CWorld();

	void Destroy();
	void Build();
	void Render();
	void Render_Scence(); //Invoike camera render scence
	void Zaxis_aligned_perspective(double _eye, double _d);

	void AddObject(CGeometricObject* obj);
	void Set_Camera(CCamera* _cam);
	CShadeRec HitObjects(const CRay& _ray);

	CDisplayScreen* m_screen;

private:

	std::vector<CGeometricObject*> m_objects;

};

#endif /* CWORLD_H_ */
