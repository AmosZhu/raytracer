/*
 * CRay.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CRAY_H_
#define CRAY_H_

#include "CVector3D.h"
#include "CPoint3D.h"

class CRay {
public:
	CPoint3D o;	//Origin
	CVector3D d;	//Direction

public:
	CRay();
	CRay(CPoint3D _o, CVector3D _d);

	~CRay();

};

#endif /* CRAY_H_ */
