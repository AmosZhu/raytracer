/*
 * CPoint2D.h
 *
 *  Created on: Nov 3, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CPOINT2D_H_
#define CPOINT2D_H_

class CPoint2D {
public:
	double x, y;
public:
	CPoint2D();
	CPoint2D(double _c);
	CPoint2D(double _x, double _y);
	CPoint2D(const CPoint2D& _rhs);
	~CPoint2D();

public:
	CPoint2D operator*(const double _s);
	CPoint2D operator/(const double _s);
	CPoint2D& operator=(const CPoint2D& _rhs);
};

#endif /* CPOINT2D_H_ */
