/*
 * CGeometricObject.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CGEOMETRICOBJECT_H_
#define CGEOMETRICOBJECT_H_

#include "CRay.h"
#include "CRGBColor.h"
#include "CShadeRec.h"

class CGeometricObject {
public:
	CGeometricObject();
	virtual ~CGeometricObject();

	virtual CGeometricObject* Clone() const =0;
	virtual bool Hit(const CRay& _ray, double& _tmin,CShadeRec& _sr)=0;

	void SetColor(const CRGBColor _color);
	CRGBColor GetColor();

private:
	CRGBColor m_color;
};

#endif /* CGEOMETRICOBJECT_H_ */
