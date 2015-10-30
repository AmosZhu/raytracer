/*
 * CViewPlane.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CVIEWPLANE_H_
#define CVIEWPLANE_H_

class CViewPlane
{
public:
	int hres;
	int vres;
	double size;

public:
	CViewPlane();
	~CViewPlane();

	void SetHorizontalResolution(int h);
	void SetVerticalResolution(int v);
	void SetPixelSize(double s);
	};



#endif /* CVIEWPLANE_H_ */
