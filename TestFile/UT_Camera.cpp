/*
 * UT_Camera.cpp
 *
 *  Created on: Dec 23, 2015
 *      Author: Dizhong.Zhu
 */

#include "UT_Camera.h"
#include <GL/freeglut.h>
#include "CDisplayScreen.h"
#include <math.h>
#include "CWorld.h"
#include "CPinhole.h"
#include "CThinLens.h"
#include "CFishEye.h"
#include "CStereoCamera.h"
#include "CMultiJitteredSampler.h"
#include "CTracerMultipleObjects.h"
#include "CPlane.h"
#include <stdio.h>

static CDisplayScreen* hScreen;

static void display() {
	hScreen->Paint();
}
void UT_PinholeCamera() {

	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();
	CPinhole* pCam = new CPinhole();

	/*
	 * Add world
	 */

	CWorld world;
	world.Build();
	pCam->SetEye(CPoint3D(0, 0, 800));
	pCam->SetUp(CVector3D(0, 1, 0));
	pCam->SetLookat(CPoint3D(0, 200, 0));
	pCam->Set_ViewDistance(400);
	pCam->Set_Zoom(2);
	pCam->Comput_UVW();
	world.Set_Camera(pCam);
	world.Render_Scence();

	glutDisplayFunc(display);
	glutMainLoop();
}

void UT_ThinlensCamera() {
	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();
	CThinLens* pCam = new CThinLens();

	/*
	 * Add world
	 */

	CWorld world;
	int num_samples = 4;
	world.vp.SetHorizontalResolution(480);
	world.vp.SetVerticalResolution(480);
	world.vp.SetPixelSize(2);
	world.vp.SetNumSamples(num_samples);
	world.vp.SetSampler(new CMultiJitteredSampler(num_samples));
	world.vp.SetMaxDepth(0);

	world.bg_color = CRGBColor(0, 0, 0);

	world.tracer_ptr = new CTracerMultipleObjects(&world);
	//
	//	sphere.SetCenter(0);
	//	sphere.SetRadius(85.0);
	//

	CSphere* pSphere = new CSphere(CPoint3D(0, -25, 0), 150);
	pSphere->SetColor(CRGBColor(255, 0, 0));
	world.AddObject(pSphere);

	pSphere = new CSphere(CPoint3D(0, 100, 0), 60);
	pSphere->SetColor(CRGBColor(255, 255, 0));
	world.AddObject(pSphere);

	pSphere = new CSphere(CPoint3D(300, 300, 300), 50);
	pSphere->SetColor(CRGBColor(0, 255, 0));
	world.AddObject(pSphere);

	CPlane* pPlane = new CPlane(CPoint3D(0, 0, 0), CVector3D(0, 1, 1));
	pPlane->SetColor(CRGBColor(100, 100, 0));
	world.AddObject(pPlane);

	pCam->SetEye(CPoint3D(0, 0, 800));
	pCam->SetUp(CVector3D(0, 1, 0));
	pCam->SetLookat(CPoint3D(0, 300, 300));
	pCam->Set_ViewDistance(400);
	pCam->Set_FocalDistance(800);
	pCam->Set_Radius(1);
	pCam->Set_Zoom(1);
	pCam->Set_Sampler(new CMultiJitteredSampler(num_samples));
	pCam->Comput_UVW();

	world.Set_Camera(pCam);
	world.Render_Scence();

	glutDisplayFunc(display);
	glutMainLoop();
}

void UT_FishEyeCamera() {
	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();
	CFishEye* pCam = new CFishEye();

	/*
	 * Add world
	 */

	CWorld world;
	int num_samples = 256;
	world.vp.SetHorizontalResolution(480);
	world.vp.SetVerticalResolution(480);
	world.vp.SetPixelSize(2);
	world.vp.SetNumSamples(num_samples);
	world.vp.SetSampler(new CMultiJitteredSampler(num_samples));
	world.vp.SetMaxDepth(0);

	world.bg_color = CRGBColor(0, 0, 0);

	world.tracer_ptr = new CTracerMultipleObjects(&world);
//
//	sphere.SetCenter(0);
//	sphere.SetRadius(85.0);
//

	CSphere* pSphere = new CSphere(CPoint3D(0, -25, 0), 150);
	pSphere->SetColor(CRGBColor(255, 0, 0));
	world.AddObject(pSphere);

	pSphere = new CSphere(CPoint3D(0, 100, 0), 60);
	pSphere->SetColor(CRGBColor(255, 255, 0));
	world.AddObject(pSphere);

	pSphere = new CSphere(CPoint3D(300, 300, 300), 50);
	pSphere->SetColor(CRGBColor(0, 255, 0));
	world.AddObject(pSphere);

	CPlane* pPlane = new CPlane(CPoint3D(0, 0, 0), CVector3D(0, 1, 1));
	pPlane->SetColor(CRGBColor(100, 100, 0));
	world.AddObject(pPlane);

	pCam->SetEye(CPoint3D(0, 0, 800));
	pCam->SetUp(CVector3D(0, 1, 0));
	pCam->SetLookat(CPoint3D(0, 300, 300));
	pCam->Set_MaxPhi(90);

	pCam->Comput_UVW();

	world.Set_Camera(pCam);
	world.Render_Scence();

	glutDisplayFunc(display);
	glutMainLoop();
}

void UT_StereoCamera() {
	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();
	CStereoCamera* pCam = new CStereoCamera();
	CPinhole* pLCam = new CPinhole();
	CPinhole* pRCam = new CPinhole();
	/*
	 * Add world
	 */

	CWorld world;
	int num_samples = 256;
	world.vp.SetHorizontalResolution(400);
	world.vp.SetVerticalResolution(400);
	world.vp.SetPixelSize(2);
	world.vp.SetNumSamples(num_samples);
	world.vp.SetSampler(new CMultiJitteredSampler(num_samples));
	world.vp.SetMaxDepth(0);

	world.bg_color = CRGBColor(0, 0, 0);

	world.tracer_ptr = new CTracerMultipleObjects(&world);
//
//	sphere.SetCenter(0);
//	sphere.SetRadius(85.0);
//

	CSphere* pSphere = new CSphere(CPoint3D(0, -25, 0), 150);
	pSphere->SetColor(CRGBColor(255, 0, 0));
	world.AddObject(pSphere);

	pSphere = new CSphere(CPoint3D(0, 100, 0), 60);
	pSphere->SetColor(CRGBColor(255, 255, 0));
	world.AddObject(pSphere);

	pSphere = new CSphere(CPoint3D(300, 300, 300), 50);
	pSphere->SetColor(CRGBColor(0, 255, 0));
	world.AddObject(pSphere);

	CPlane* pPlane = new CPlane(CPoint3D(0, 0, 0), CVector3D(0, 1, 1));
	pPlane->SetColor(CRGBColor(100, 100, 0));
	world.AddObject(pPlane);

	double vpDist = 100;
	pLCam->Set_ViewDistance(vpDist);
	pRCam->Set_ViewDistance(vpDist);

	pCam->SetEye(CPoint3D(0, 0, 500));
	pCam->SetUp(CVector3D(0, 1, 0));
	pCam->SetLookat(CPoint3D(0, 300, 300));
	pCam->Set_Left_camera(pLCam);
	pCam->Set_Right_camera(pRCam);
	pCam->Using_Parallel();
	pCam->Set_Stereo_angle(PI / 3);
	pCam->Set_PixelGap(5);
	pCam->Comput_UVW();
	pCam->Setup_Camera();

	world.Set_Camera(pCam);
	world.Render_Scence();

	glutDisplayFunc(display);
	glutMainLoop();
}
