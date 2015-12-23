/*
 * CRenderPixel.h
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CRENDERPIXEL_H_
#define CRENDERPIXEL_H_


class CRenderPixel
{
public:
	CRenderPixel(int,int,int,int,int);
	CRenderPixel(const CRenderPixel& rhs);
	CRenderPixel(CRenderPixel&& rhs);
	~CRenderPixel();

public:
	int x,y;
	int r,g,b;

	};


#endif /* CRENDERPIXEL_H_ */
