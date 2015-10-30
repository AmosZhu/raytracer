/*
 * CGeometricObject.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CGEOMETRICOBJECT_H_
#define CGEOMETRICOBJECT_H_

#include "CRay.h"

class CGeometricObject {
public:
	static double epsilon;

public:
	CGeometricObject();
	virtual ~CGeometricObject();

	virtual CGeometricObject* Clone() const =0;
	virtual bool Hit(const CRay& ray)=0;
};

#endif /* CGEOMETRICOBJECT_H_ */
