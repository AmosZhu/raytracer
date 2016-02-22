/*
 * CWorld.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CWorld.h"
#include "CSingleSphere.h"
#include "CTracerMultipleObjects.h"
#include "CMultiJitteredSampler.h"
#include "common.h"
#include "CPlane.h"

CWorld::CWorld() {
	tracer_ptr = nullptr;
	camera_ptr = nullptr;
	m_screen = CDisplayScreen::GetInstance();
}

CWorld::~CWorld() {
	Destroy();
}

void CWorld::Destroy() {
	/*
	 * Clear objects pointer vector
	 */
	int size = m_objects.size();
	for (int i = 0; i < size; i++) {
		delete m_objects[i];
		m_objects[i] = nullptr;
	}

	m_objects.clear();
}

void CWorld::Build() {
	int num_samples=1024;
	vp.SetHorizontalResolution(120);
	vp.SetVerticalResolution(120);
	vp.SetPixelSize(8);
	vp.SetNumSamples(num_samples);
	vp.SetSampler(new CMultiJitteredSampler(num_samples));
	vp.SetMaxDepth(0);

	bg_color = CRGBColor(0, 0, 0);

	tracer_ptr = new CTracerMultipleObjects(this);
//
//	sphere.SetCenter(0);
//	sphere.SetRadius(85.0);
//

	CSphere* pSphere = new CSphere(CPoint3D(0, -25, 0), 150);
	pSphere->SetColor(CRGBColor(255, 0, 0));
	AddObject(pSphere);

	pSphere = new CSphere(CPoint3D(0, 100, 0), 60);
	pSphere->SetColor(CRGBColor(255, 255, 0));
	AddObject(pSphere);

	pSphere=new CSphere(CPoint3D(300,300,300),50);
	pSphere->SetColor(CRGBColor(0,255,0));
	AddObject(pSphere);

	CPlane* pPlane = new CPlane(CPoint3D(0, 0, 0), CVector3D(0, 1, 1));
	pPlane->SetColor(CRGBColor(100, 100, 0));
	AddObject(pPlane);
}

void CWorld::AddObject(CGeometricObject* obj) {
	if (obj != nullptr) {
		m_objects.push_back(obj);
	}
}

void CWorld::Set_Camera(CCamera* _cam) {
	camera_ptr = _cam;
}

CShadeRec CWorld::HitObjects(const CRay& _ray) {
	CShadeRec sr(this);
	CRGBColor color;
	int nObjects = m_objects.size();
	double tmin;
	double t = KINFINITY;

	for (int i = 0; i < nObjects; i++) {
		if (m_objects[i]->Hit(_ray, tmin, sr) && (tmin < t)) {
			sr.isHit = true;
			sr.color = m_objects[i]->GetColor();
			t = tmin;
		}
	}
	return sr;
}

void CWorld::Render() {
	CRGBColor pixel_color;
	CRay ray;
	double zw = 100;
	double x, y;

	/*
	 * Clean before rendering
	 */
	m_screen->Clear();
	m_screen->OpenWindow(vp.hres, vp.vres, vp.size);
	ray.d = CVector3D(0, 0, -1);

	for (int c = 0; c < vp.hres; c++) {
		for (int r = 0; r < vp.vres; r++) {
			x = vp.size * (c - vp.hres / 2 + 0.5);
			y = vp.size * (r - vp.vres / 2 + 0.5);
			ray.o = CPoint3D(x, y, zw);
			pixel_color = tracer_ptr->Trace_Ray(ray);
			m_screen->SetPixel(c, r, pixel_color);

		}
	}
}

void CWorld::Render_Scence() {
	camera_ptr->Render_Scence(this);
}

void CWorld::Zaxis_aligned_perspective(double _eye, double _d) {
	CRGBColor pixel_color;
	CRay ray;
	double x, y;
	m_screen->Clear();
	m_screen->OpenWindow(vp.hres, vp.vres, vp.size);

	ray.o = CPoint3D(0, 0, _eye);
	for (int c = 0; c < vp.hres; c++) {
		for (int r = 0; r < vp.vres; r++) {
			x = vp.size * (c - vp.hres / 2 + 0.5);
			y = vp.size * (r - vp.vres / 2 + 0.5);
			ray.d = CVector3D(x, y, -_d);
			ray.d.Normalize();
			pixel_color = tracer_ptr->Trace_Ray(ray);
			m_screen->SetPixel(c, r, pixel_color);
		}
	}

}
