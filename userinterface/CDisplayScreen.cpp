/*
 * CDisplayScreen.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CDisplayScreen.h"
#include <string.h>
#include <GL/freeglut.h>

CDisplayScreen* CDisplayScreen::m_hInstance = nullptr;

CDisplayScreen::CDisplayScreen() {
}

CDisplayScreen::~CDisplayScreen() {
}

void CDisplayScreen::Init() {
	int argc = 1;
	char* argv[1];
	argv[0] = strdup("Hello");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glEnable(GL_POINT_SMOOTH);
}

void CDisplayScreen::OpenWindow(double _h, double _v, double _s) {
	m_hres = _h;
	m_vres = _v;
	m_size = _s;
	glutInitWindowSize(680,680);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Single Sphere");
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, -1, 1);
}

void CDisplayScreen::Paint() {
	std::vector<CRenderPixel*>::iterator it;
	double r, g, b;
	double x, y;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(m_size);
	glBegin(GL_POINTS);
	for (it = m_renderPixels.begin(); it != m_renderPixels.end(); it++) {
		r = (*it)->r / 255.0;
		g = (*it)->g / 255.0;
		b = (*it)->b / 255.0;
		x = (*it)->x / m_hres;
		y = (*it)->y / m_vres;
		glColor3f(r, g, b);
		glVertex2f(x, y);

	}
	glEnd();
	glFlush();
}

void CDisplayScreen::Clear() {
	m_renderPixels.clear();
}

void CDisplayScreen::SetPixel(int c, int r, const CRGBColor& color) {
	CRenderPixel* pixel = new CRenderPixel(c, r, color.r, color.g, color.b);
	m_renderPixels.push_back(pixel);
}

CDisplayScreen* CDisplayScreen::GetInstance() {
	if (m_hInstance == nullptr) {
		m_hInstance = new CDisplayScreen();
	}

	return m_hInstance;
}

