/*
 * CCamera.h
 *
 *  Created on: Dec 23, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CCAMERA_H_
#define CCAMERA_H_

#include "CVector3D.h"
#include "CPoint3D.h"

class CWorld;

class CCamera {
public:
	CCamera();
	CCamera(const CCamera& _rhs);
	CCamera(CCamera&& _rhs);
	virtual ~CCamera();

	void Comput_UVW();
	virtual void Render_Scence(CWorld* _world)=0;
	void SetEye(CPoint3D _e);
	void SetLookat(CPoint3D _lookat);
	void SetUp(CVector3D _up);

protected:
	CPoint3D m_eye;
	CPoint3D m_lookat;
	CVector3D m_up;
	CVector3D m_u, m_v, m_w;
};

#endif /* CCAMERA_H_ */
