/*
 * CFishEye.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: Dizhong.Zhu
 */

#include "CFishEye.h"
#include "CWorld.h"
#include "CRGBColor.h"
#include <math.h>
#include <stdio.h>
CFishEye::CFishEye() :
		CCamera() {
	m_maxphi = 0;
}

CFishEye::CFishEye(const CFishEye& _rhs) :
		CCamera(_rhs) {
	m_maxphi = _rhs.m_maxphi;
}

CFishEye::~CFishEye() {
}

void CFishEye::Render_Scence(CWorld* _world) {
	double r_squared;
	CPoint2D pp;
	CPoint2D sp; //View plane sample point
	CRGBColor pixelColor;
	CRay ray;

	int nSamples = _world->vp.nSamples;
	int hres = _world->vp.hres;
	int vres = _world->vp.vres;
	int size = _world->vp.size;

	_world->m_screen->Clear();
	_world->m_screen->OpenWindow(hres, vres, _world->vp.size);
	ray.o = m_eye;

	for (int c = 0; c < hres; c++) {
		for (int r = 0; r < vres; r++) {
			pixelColor = CRGBColor(0, 0, 0);
			for (int p = 0; p < nSamples; p++) {
				pp = _world->vp.sampler->Sample_unit_square();
				sp.x = size * (c - hres * 0.5 + pp.x);
				sp.y = size * (r - vres * 0.5 + pp.y);

				ray.d = Ray_Direction(sp, hres, vres, size, r_squared);
				if (r_squared <= 1.0) {
					pixelColor += _world->tracer_ptr->Trace_Ray(ray);
				}
			}
			pixelColor /= nSamples;
			_world->m_screen->SetPixel(c, r, pixelColor);
		}
	}
}

CVector3D CFishEye::Ray_Direction(CPoint2D _pt, int _hres, int _vres, double _s,
		double& _r_squared) const {
	//Normalize _pt;
	CVector3D dir;
	CPoint2D sp(_pt.x / (_s * _hres) * 2, _pt.y / (_s * _vres) * 2);
	_r_squared = sp.x * sp.x + sp.y * sp.y;
	if (_r_squared <= 1.0) {
		double r = sqrt(_r_squared);
		double phi = r * m_maxphi * PI_ON_180; //Proportional of max phi
		double cos_phi = cos(phi);
		double sin_phi = sin(phi);
		double sin_alpha = sp.y / r;
		double cos_alpha = sp.x / r;

		dir = sin_phi * cos_alpha * m_u + sin_phi * sin_alpha * m_v
				- cos_phi * m_w;

		return dir;
	} else {
		return CVector3D(0, 0, 0);
	}
}

void CFishEye::Set_MaxPhi(double _angle) {
	m_maxphi = _angle / 2 ;
}
