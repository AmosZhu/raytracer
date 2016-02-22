/*
 * CStereoCamera.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: Dizhong.Zhu
 */

#include "CStereoCamera.h"
#include "CWorld.h"
#include <math.h>

CStereoCamera::CStereoCamera() :
		CCamera() {
	m_type = parallel;
	m_beta = 0;
	m_pixelGap = 0;
	m_leftCamera = nullptr;
	m_rightCamera = nullptr;
}

CStereoCamera::CStereoCamera(const CStereoCamera& _rhs) :
		CCamera(_rhs) {
	m_type = _rhs.m_type;
	m_beta = _rhs.m_beta;
	m_pixelGap = _rhs.m_pixelGap;
	m_leftCamera = _rhs.m_leftCamera;
	m_rightCamera = _rhs.m_rightCamera;
}

CStereoCamera::~CStereoCamera() {
}

void CStereoCamera::Set_Stereo_angle(double _angle) {
	m_beta = _angle;
}

void CStereoCamera::Set_Left_camera(CCamera* _camera) {
	m_leftCamera = _camera;
}

void CStereoCamera::Set_Right_camera(CCamera* _camera) {
	m_rightCamera = _camera;
}

void CStereoCamera::Set_PixelGap(int _gap) {
	m_pixelGap = _gap;
}

void CStereoCamera::Setup_Camera() {
	double r = m_eye.Distance(m_lookat);
	double x = r * tan(m_beta * 0.5);

	m_leftCamera->SetEye(m_eye - x * m_u);
	m_leftCamera->SetLookat(m_lookat - x * m_u);
	m_leftCamera->SetUp(m_up);
	m_leftCamera->Comput_UVW();

	m_rightCamera->SetEye(m_eye + x * m_u);
	m_rightCamera->SetLookat(m_lookat + x * m_u);
	m_rightCamera->SetUp(m_up);
	m_rightCamera->Comput_UVW();
}

void CStereoCamera::Render_Scence(CWorld* _world) {
	int hres = _world->vp.hres;
	int vres = _world->vp.vres;

	_world->m_screen->Clear();
	_world->m_screen->OpenWindow(2 * hres + m_pixelGap, vres, _world->vp.size);

	double r = m_eye.Distance(m_lookat);
	double x = r * tan(m_beta * 0.5);

	if (m_type == parallel) {
		m_leftCamera->Render_Stereo(_world, x, 0);
		m_rightCamera->Render_Stereo(_world, -x, hres + m_pixelGap);
	} else if (m_type == transverse) {
		m_rightCamera->Render_Stereo(_world, -x, 0);
		m_leftCamera->Render_Stereo(_world, x, hres + m_pixelGap);
	}
}

void CStereoCamera::Using_Parallel() {
	m_type = parallel;
}

void CStereoCamera::Using_Transverse() {
	m_type = transverse;
}
