/*
 * CSphere.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CSPHERE_H_
#define CSPHERE_H_

#include "CPoint3D.h"
#include "CGeometricObject.h"

class CSphere: public CGeometricObject {

public:
	CSphere();
	CSphere(CPoint3D _center, double _radius);
	~CSphere();
	CSphere* Clone() const;

	void SetCenter(CPoint3D center);
	void SetCenter(double _x, double _y, double _z);
	void SetRadius(double radius);

	bool Hit(const CRay& _ray, double& _tmin, CShadeRec& _sr);

private:
	CPoint3D m_center;
	double m_radius;
};

#endif /* CSPHERE_H_ */
