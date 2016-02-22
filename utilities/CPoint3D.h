/*
 * CPoint3D.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CPOINT3D_H_
#define CPOINT3D_H_

#include "CVector3D.h"

class CPoint3D {
public:
	double x, y, z;
public:
	CPoint3D();
	CPoint3D(double _c);
	CPoint3D(double _x, double _y, double _z);
	CPoint3D(const CPoint3D& _rhs);
	~CPoint3D();

	double Distance(CPoint3D& _dst);

public:
	CPoint3D operator*(const double _s);
	CPoint3D operator/(const double _s);
	CPoint3D& operator=(const CPoint3D& _rhs);
	CPoint3D operator+(const CVector3D& _rhs) const;
	CPoint3D operator+(const CPoint3D& _rhs) const;
	CPoint3D operator-(const CVector3D& _rhs) const;
	CVector3D operator-(const CPoint3D& _rhs) const; //Point minus point is a vector

};

#endif /* CPOINT3D_H_ */
