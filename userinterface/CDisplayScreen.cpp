/*
 * CDisplayScreen.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include "CDisplayScreen.h"

CDisplayScreen* CDisplayScreen::m_hInstance = nullptr;

CDisplayScreen::CDisplayScreen() {
}

CDisplayScreen::~CDisplayScreen() {
}

void CDisplayScreen::Init() {

}

void CDisplayScreen::Paint() {
	std::vector<CRenderPixel*>::iterator it;
	for (it = m_renderPixels.begin(); it != m_renderPixels.end(); it++) {

	}
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

