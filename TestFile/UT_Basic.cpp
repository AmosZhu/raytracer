/*
 * UT_Basic.cpp
 *
 *  Created on: Nov 3, 2015
 *      Author: Dizhong.Zhu
 */

#include "UT_Basic.h"
#include <GL/freeglut.h>
#include "CDisplayScreen.h"
#include <math.h>
#include "CWorld.h"

static CDisplayScreen* hScreen;

static void display() {
	hScreen->Paint();
}
void UT_Basic() {

	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();

	/*
	 * Add world
	 */

	CWorld world;
	world.Build();
	world.Render();

	glutDisplayFunc(display);
	glutMainLoop();
}

