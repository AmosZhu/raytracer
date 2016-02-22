/*
 * CViewPlane.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CVIEWPLANE_H_
#define CVIEWPLANE_H_

#include "CSampler.h"

class CViewPlane {
public:
	int hres;
	int vres;
	double size;
	int nSamples;
	CSampler* sampler;
	double depth;

public:
	CViewPlane();
	~CViewPlane();

	void SetHorizontalResolution(int _h);
	void SetVerticalResolution(int _v);
	void SetPixelSize(double _s);
	void SetNumSamples(int _n);
	void SetSampler(CSampler* _sampler);
	void SetMaxDepth(double _d);
};

#endif /* CVIEWPLANE_H_ */
