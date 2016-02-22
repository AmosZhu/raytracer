/*
 * CFishEye.h
 *
 *  Created on: Dec 26, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CFISHEYE_H_
#define CFISHEYE_H_

#include "CCamera.h"
#include "CPoint2D.h"

class CFishEye: public CCamera {
public:
	CFishEye();
	CFishEye(const CFishEye& _rhs);
	~CFishEye();

	void Render_Scence(CWorld* _world);
	CVector3D Ray_Direction(CPoint2D _pt,int _hres,int _vres, double _s, double& _r_squared) const;

	void Set_MaxPhi(double _angle);
private:
	double m_maxphi;
};

#endif /* CFISHEYE_H_ */
