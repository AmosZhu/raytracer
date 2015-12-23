/*
 * UT_MapDisk.cpp
 *
 *  Created on: Dec 21, 2015
 *      Author: Dizhong.Zhu
 */

#include "UT_MapDisk.h"
#include "CDisplayScreen.h"
#include "CHammersleySampler.h"
#include "CPoint2D.h"
#include <GL/freeglut.h>

static CDisplayScreen* hScreen;

static void display() {
	hScreen->Paint();
}
void UT_MapDisk() {

	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();

	int nSamples = 512;
	int width = nSamples, height = nSamples;

	//CMultiJitteredSampler* sampler=new CMultiJitteredSampler(nSamples,1);
	//CNRookSampler* sampler=new CNRookSampler(nSamples,1);
	//CJitteredSampler* sampler=new CJitteredSampler(nSamples,1);
	CHammersleySampler* sampler = new CHammersleySampler(nSamples, 1);
	sampler->Map_sample_to_unit_disk();

	CPoint2D pt;
	for (int i = 0; i < nSamples; i++) {
		pt = sampler->Sample_unit_disk();
		//Move center(1,1) to (0,0)
		pt.x+=1.0;
		pt.y+=1.0;
		pt = pt * nSamples/2;
		hScreen->SetPixel(pt.x, pt.y, CRGBColor(255, 255, 255));
	}

	hScreen->OpenWindow(width, height, 1);

	glutDisplayFunc(display);
	glutMainLoop();
}

