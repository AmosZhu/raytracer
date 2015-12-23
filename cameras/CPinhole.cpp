/*
 * CPinhole.cpp
 *
 *  Created on: Dec 23, 2015
 *      Author: Dizhong.Zhu
 */

#include "CPinhole.h"
#include "CRGBColor.h"
#include "CRay.h"
#include "CWorld.h"

CPinhole::CPinhole() :
		CCamera() {
	m_d = 0;
	m_zoom = 1;
}

CPinhole::CPinhole(const CPinhole& _rhs) :
		CCamera(_rhs) {
	m_d = _rhs.m_d;
	m_zoom = _rhs.m_zoom;
}

CPinhole::~CPinhole() {
}

void CPinhole::Render_Scence(CWorld* _world) {
	CRGBColor pixel_color;
	CRay ray;
	double x, y;
	double hres=_world->vp.hres;
	double vres=_world->vp.vres;
	double size = _world->vp.size / m_zoom;
	/*
	 * Clean before rendering
	 */
	_world->m_screen->Clear();
	_world->m_screen->OpenWindow(hres, vres, size);
	ray.o = m_eye;

	for (int c = 0; c < _world->vp.hres; c++) {
		for (int r = 0; r < _world->vp.vres; r++) {
			x=size*(c-hres/2+0.5);
			y=size*(r-vres/2+0.5);
			ray.d = Ray_Direction(CPoint2D(x,y));
			pixel_color = _world->tracer_ptr->Trace_Ray(ray);
			_world->m_screen->SetPixel(c, r, pixel_color);

		}
	}
}

CVector3D CPinhole::Ray_Direction(CPoint2D _pt) const {
	CVector3D direction = m_u * _pt.x + m_v * _pt.y - m_w * m_d;
	direction.Normalize();
	return direction;
}

void CPinhole::Set_ViewDistance(double _d) {
	m_d = _d;
}

void CPinhole::Set_Zoom(double _z) {
	m_zoom = _z;
}
