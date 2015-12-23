/*
 * CPlane.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CPLANE_H_
#define CPLANE_H_

#include "CGeometricObject.h"
#include "CPoint3D.h"
#include "CVector3D.h"

class CPlane: public CGeometricObject {
public:
	CPlane();
	CPlane(CPoint3D _point, CVector3D _normal);
	~CPlane();
	CPlane* Clone() const;

	bool Hit(const CRay& _ray, double& _tmin, CShadeRec& _sr);

private:
	CVector3D m_normal;
	CPoint3D m_point;
};

#endif /* CPLANE_H_ */
