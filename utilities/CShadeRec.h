/*
 * CShadeRec.h
 *
 *  Created on: Nov 1, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CSHADEREC_H_
#define CSHADEREC_H_

#include "CRGBColor.h"

class CWorld;

class CShadeRec {
public:
	bool isHit;
	CRGBColor color;
	CWorld* world;

public:
	CShadeRec(CWorld* _world);
};

#endif /* CSHADEREC_H_ */
