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

static CDisplayScreen* hScreen;

static void display() {
	hScreen->Paint();
}
void UT_PinholeCamera() {

	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();
	CPinhole* pCam=new CPinhole();

	/*
	 * Add world
	 */

	CWorld world;
	world.Build();
	pCam->SetEye(CPoint3D(1000,1000,600));
	pCam->SetUp(CVector3D(0,1,0));
	pCam->SetLookat(CPoint3D(0,0,0));
	pCam->Set_ViewDistance(400);
	pCam->Set_Zoom(2);
	pCam->Comput_UVW();
	world.Set_Camera(pCam);
	world.Render_Scence();

	glutDisplayFunc(display);
	glutMainLoop();
}


