/*
 * UT_NRook.cpp
 *
 *  Created on: Nov 3, 2015
 *      Author: Dizhong.Zhu
 */

#include "UT_NRook.h"
#include <GL/freeglut.h>
#include "CDisplayScreen.h"
#include <math.h>
#include "CWorld.h"
#include "CNRookSampler.h"
#include "CJitteredSampler.h"
#include "CMultiJitteredSampler.h"
#include "CHammersleySampler.h"

static CDisplayScreen* hScreen;

static void display() {
	hScreen->Paint();
}
void UT_NRook() {

	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();

	int nSamples=256;
	int width = nSamples, height = nSamples;

	//CMultiJitteredSampler* sampler=new CMultiJitteredSampler(nSamples,1);
	//CNRookSampler* sampler=new CNRookSampler(nSamples,1);
	//CJitteredSampler* sampler=new CJitteredSampler(nSamples,1);
	CHammersleySampler* sampler=new CHammersleySampler(nSamples,1);

	CPoint2D pt;
	for(int i=0;i<nSamples;i++)
	{
		pt = sampler->Sample_unit_square();
		pt = pt * nSamples;
		hScreen->SetPixel(pt.x,pt.y,CRGBColor(255,255,255));
	}

	hScreen->OpenWindow(width, height, 4);

	glutDisplayFunc(display);
	glutMainLoop();
}

