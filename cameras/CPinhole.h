/*
 * CPinhole.h
 *
 *  Created on: Dec 23, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CPINHOLE_H_
#define CPINHOLE_H_

#include "CCamera.h"
#include "CPoint2D.h"

class CPinhole: public CCamera {
public:
	CPinhole();
	CPinhole(const CPinhole& _rhs);
	~CPinhole();

	void Render_Scence(CWorld* _world);
	CVector3D Ray_Direction(CPoint2D _pt) const;
	void Render_Stereo(CWorld* _world, double _x, int _offset);
	void Set_ViewDistance(double _d);
	void Set_Zoom(double _z);
private:
	double m_d;
	double m_zoom;
};

#endif /* CPINHOLE_H_ */
