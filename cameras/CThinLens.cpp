/*
 * CThinLens.cpp
 *
 *  Created on: Dec 25, 2015
 *      Author: Dizhong.Zhu
 */

#include "CThinLens.h"
#include "CRGBColor.h"
#include "CRay.h"
#include "CWorld.h"

CThinLens::CThinLens() :
		CCamera() {
	m_d = 0;
	m_f = 0;
	m_zoom = 1;
	m_radius = 0;
	sampler = nullptr;
}

CThinLens::CThinLens(const CThinLens& _rhs) :
		CCamera(_rhs) {
	m_d = _rhs.m_d;
	m_f = _rhs.m_f;
	m_zoom = _rhs.m_zoom;
	m_radius = _rhs.m_radius;
	sampler = _rhs.sampler;
}

CThinLens::~CThinLens() {
}

void CThinLens::Render_Scence(CWorld* _world) {
	CPoint2D lp;
	CPoint2D sp;
	CPoint2D dp;
	CPoint2D pp;
	CRGBColor pixelColor;
	CRay ray;

	double size = _world->vp.size;
	int hres = _world->vp.hres;
	int vres = _world->vp.vres;
	int nSamples = _world->vp.nSamples;

	_world->m_screen->Clear();
	_world->m_screen->OpenWindow(hres, vres, _world->vp.size);
	size /= m_zoom;

	for (int c = 0; c < hres; c++) {
		for (int r = 0; r < vres; r++) {
			pixelColor = CRGBColor(0, 0, 0);
			for (int p = 0; p < nSamples; p++) {
				dp = this->sampler->Sample_unit_square();
				lp = dp * m_radius;

				pp = _world->vp.sampler->Sample_unit_square();
				sp.x = size * (c - hres / 2 + pp.x);
				sp.y = size * (r - vres / 2 + pp.y);

				ray.o = m_eye + lp.x * m_u + lp.y * m_v;
				ray.d = Ray_Direction(sp, lp);
				pixelColor += _world->tracer_ptr->Trace_Ray(ray);
			}
			pixelColor /= nSamples;
			_world->m_screen->SetPixel(c, r, pixelColor);
		}
	}
}

CVector3D CThinLens::Ray_Direction(CPoint2D _sp, CPoint2D _lp) const {
	CVector3D direction;
	CPoint2D p;
	p.x = _sp.x * m_f / m_d;
	p.y = _sp.y * m_f / m_d;

	direction = (p.x - _lp.x) * m_u + (p.y - _lp.y) * m_v - m_f * m_w;
	direction.Normalize();

	return direction;
}

void CThinLens::Set_ViewDistance(double _d) {
	m_d = _d;
}

void CThinLens::Set_FocalDistance(double _f) {
	m_f = _f;
}

void CThinLens::Set_Zoom(double _z) {
	m_zoom = _z;
}

void CThinLens::Set_Radius(double _r) {
	m_radius = _r;
}

void CThinLens::Set_Sampler(CSampler* _sampler) {
	sampler = _sampler;
	sampler->Map_sample_to_unit_disk();
}
