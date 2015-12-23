/*
 * UT_Sinusoid.cpp
 *
 *  Created on: Nov 3, 2015
 *      Author: Dizhong.Zhu
 */

#include "UT_Sinusoid.h"

#include <GL/freeglut.h>
#include "CDisplayScreen.h"
#include <math.h>

static CDisplayScreen* hScreen;

static void display() {
	hScreen->Paint();
}

void UT_Sinusoid() {

	hScreen = CDisplayScreen::GetInstance();
	hScreen->Init();


	int width = 800, height = 800;
	double peroid = 100;
	double z;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			z = 255.0
					* sin(
							pow((double(y) / peroid), 2)
									* pow((double(x) / peroid), 2));
			hScreen->SetPixel(x, y, CRGBColor(z, z, z));
		}
	}

	hScreen->OpenWindow(width, height, 1);

	glutDisplayFunc(display);
	glutMainLoop();
	return;
}
