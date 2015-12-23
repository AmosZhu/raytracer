/*
 * CVector3D.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CVECTOR3D_H_
#define CVECTOR3D_H_

class CVector3D
{
public:
	double x,y,z;

public:
	CVector3D();
	CVector3D(double _c);
	CVector3D(double _x,double _y,double _z);
	~CVector3D();

	void Normalize();

public:
	CVector3D operator*(const double _s) const; //times a scalar
	double operator*(const CVector3D& _rhs) const; //dot product
	CVector3D operator^(const CVector3D& _rhs) const; //Cross product
	CVector3D operator+(const CVector3D& _rhs) const;
	CVector3D operator-(const CVector3D& _rhs) const;
public:
	friend CVector3D operator*(const double _lhs,const CVector3D& _rhs);
	};


#endif /* CVECTOR3D_H_ */
