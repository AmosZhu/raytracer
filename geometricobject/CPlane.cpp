/*
 * CPlane.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author: Dizhong.Zhu
 */

#include "CPlane.h"
#include "common.h"
#include <math.h>

CPlane::CPlane() {
}

CPlane::CPlane(CPoint3D _point, CVector3D _normal) {
	m_point = _point;
	m_normal = _normal;
}

CPlane* CPlane::Clone() const {
	CPlane* plane = new CPlane(*this);
	return plane;
}

CPlane::~CPlane() {
}

bool CPlane::Hit(const CRay& _ray, double& _tmin, CShadeRec& _sr) {
	double dominator = _ray.d * m_normal;
	if (fabs(dominator) <= KEPSILON) {
		return false;  //Parallel
	}
	double t = (m_point - _ray.o) * m_normal / dominator;
	if (t > KEPSILON) {
		_tmin = t;
		_sr.isHit = true;
		return true;
	}

	return false;
}
