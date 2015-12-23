/*
 * UT_AxixAlignedPerspective.cpp
 *
 *  Created on: Dec 23, 2015
 *      Author: Dizhong.Zhu
 */

#include "UT_AxixAlignedPerspective.h"

#include <GL/freeglut.h>
#include "CDisplayScreen.h"
#include <math.h>
#include "CWorld.h"

static CDisplayScreen* hScreen;

static void display() {
	hScreen->Paint();
}
void UT_AxixAlignedPerspective() {

	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();

	/*
	 * Add world
	 */

	CWorld world;
	world.Build();
	world.Zaxis_aligned_perspective(500,400);

	glutDisplayFunc(display);
	glutMainLoop();
}



