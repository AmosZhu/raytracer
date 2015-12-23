/*
 * CRay.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CRay.h"

CRay::CRay() :
		o(0.0), d(0.0) {

}

CRay::CRay(CPoint3D _o, CVector3D _d) :
		o(_o), d(_d) {
}

CRay::~CRay() {
}

