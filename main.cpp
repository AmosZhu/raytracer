/*
 * main.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include <GL/freeglut.h>
#include "CDisplayScreen.h"
#include "CWorld.h"

void display() {
	CDisplayScreen* hScreen = CDisplayScreen::GetInstance();
	hScreen->Paint();
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Hello");

	/*
	 * Add world
	 */
	CWorld world;
	world.Build();
	world.Render();

	glutDisplayFunc(display);
	glutMainLoop();
	return 1;

}

