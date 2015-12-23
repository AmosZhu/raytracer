/*
 * CGeometricObject.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CGeometricObject.h"

CGeometricObject::CGeometricObject() {
}

CGeometricObject::~CGeometricObject() {
}

void CGeometricObject::SetColor(const CRGBColor _color) {
	m_color = _color;
}

CRGBColor CGeometricObject::GetColor() {
	return m_color;
}
