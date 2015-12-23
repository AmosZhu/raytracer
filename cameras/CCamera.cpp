/*
 * CCamera.cpp
 *
 *  Created on: Dec 23, 2015
 *      Author: Dizhong.Zhu
 */

#include "CCamera.h"

CCamera::CCamera() {
}

CCamera::CCamera(const CCamera& _rhs) {
	m_eye = _rhs.m_eye;
	m_lookat = _rhs.m_lookat;
	m_up = _rhs.m_up;
	m_u = _rhs.m_u;
	m_v = _rhs.m_v;
	m_w = _rhs.m_w;
}

CCamera::CCamera(CCamera&& _rhs) {
	m_eye = _rhs.m_eye;
	m_lookat = _rhs.m_lookat;
	m_up = _rhs.m_up;
	m_u = _rhs.m_u;
	m_v = _rhs.m_v;
	m_w = _rhs.m_w;
}

CCamera::~CCamera()
{}

void CCamera::SetEye(CPoint3D _e) {
	m_eye = _e;
}

void CCamera::SetLookat(CPoint3D _lookat) {
	m_lookat = _lookat;
}

void CCamera::SetUp(CVector3D _up) {
	m_up = _up;
}

void CCamera::Comput_UVW() {
	m_w = m_eye - m_lookat;
	m_w.Normalize();
	m_u = m_w ^ m_up;
	m_u.Normalize();
	m_v = m_u ^ m_w;
}
