/*
 * CRGBColor.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CRGBCOLOR_H_
#define CRGBCOLOR_H_

class CRGBColor {
public:
	int r, g, b;

public:
	CRGBColor();
	CRGBColor(const CRGBColor& _rhs);
	CRGBColor(CRGBColor&& _rhs);
	CRGBColor(int _c);
	CRGBColor(int _r, int _g, int _b);
	~CRGBColor();

public:
	CRGBColor& operator=(const CRGBColor& _rhs);
	CRGBColor& operator+=(const CRGBColor& _rhs);
	CRGBColor& operator/=(const int& _s);
	CRGBColor& operator/=(const CRGBColor& _rhs);
};

#endif /* CRGBCOLOR_H_ */
