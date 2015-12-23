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
	void OpenWindow(double _h,double _v,double _s=1.0);
	void Paint();
	void Clear();
	void SetPixel(int c,int r,const CRGBColor& color);

private:
	std::vector<CRenderPixel*> m_renderPixels;
	static CDisplayScreen* m_hInstance;

	double m_hres;
	double m_vres;
	double m_size;
	CRGBColor m_bgColor;
};

#endif /* CDISPLAYSCREEN_H_ */
