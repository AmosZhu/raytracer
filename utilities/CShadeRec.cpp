/*
 * CShadeRec.cpp
 *
 *  Created on: Nov 1, 2015
 *      Author: Dizhong.Zhu
 */

#include "CShadeRec.h"

CShadeRec::CShadeRec(CWorld* _world) :
		color(0, 0, 0) {
	world = _world;
	isHit = false;
}

