/*
 * CDisplayScreen.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CDISPLAYSCREEN_H_
#define CDISPLAYSCREEN_H_

#include <vector>
#include "CRenderPixel.h"
#include "CRGBColor.h"

class CDisplayScreen {
public:
	CDisplayScreen();
	~CDisplayScreen();

public:
	static CDisplayScreen* GetInstance();
	void Init();
	void Paint();
	void Clear();
	void SetPixel(int c,int r,const CRGBColor& color);

private:
	std::vector<CRenderPixel*> m_renderPixels;
	static CDisplayScreen* m_hInstance;
};

#endif /* CDISPLAYSCREEN_H_ */
