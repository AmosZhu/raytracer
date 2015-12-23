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
	int nSamples;

public:
	CViewPlane();
	~CViewPlane();

	void SetHorizontalResolution(int _h);
	void SetVerticalResolution(int _v);
	void SetPixelSize(double _s);
	void SetNumSamples(int _n);
	};



#endif /* CVIEWPLANE_H_ */
