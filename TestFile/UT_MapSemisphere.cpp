/*
 * UT_MapSemisphere.cpp
 *
 *  Created on: Dec 22, 2015
 *      Author: Dizhong.Zhu
 */

#include "UT_MapSemisphere.h"
#include "CDisplayScreen.h"
#include "CHammersleySampler.h"
#include "CPoint3D.h"
#include <GL/freeglut.h>

static CDisplayScreen* hScreen;
static CDisplayScreen screen2;

static void display() {
	//hScreen->Paint();
	screen2.Paint();

}
void UT_MapSemisphere() {

	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();


	//screen2.Init();

	int nSamples = 2048;
	int width = nSamples, height = nSamples;

	//CMultiJitteredSampler* sampler=new CMultiJitteredSampler(nSamples,1);
	//CNRookSampler* sampler=new CNRookSampler(nSamples,1);
	//CJitteredSampler* sampler=new CJitteredSampler(nSamples,1);
	CHammersleySampler* sampler = new CHammersleySampler(nSamples, 1);
	sampler->Map_sample_to_unit_semisphere(1);

	CPoint3D pt;
	for (int i = 0; i < nSamples; i++) {
		pt = sampler->Sample_unit_semisphere();
		pt.x+=1.0;
		pt.y+=1.0;
		pt.z+=1.0;
		pt = pt * nSamples/2;
		hScreen->SetPixel(pt.x, pt.y, CRGBColor(255, 255, 255));
		screen2.SetPixel(pt.x, pt.z, CRGBColor(255, 255, 255));
	}

	hScreen->OpenWindow(width, height, 1);
	screen2.OpenWindow(width,height,0.2);
	glutDisplayFunc(display);
	glutMainLoop();
}


