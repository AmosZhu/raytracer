/*
 * CThinLens.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CTHINLENS_H_
#define CTHINLENS_H_

#include "CCamera.h"
#include "CSampler.h"
#include "CPoint2D.h"

class CThinLens: public CCamera {
public:
	CThinLens();
	CThinLens(const CThinLens& _rhs);
	~CThinLens();

	void Render_Scence(CWorld* _world);
	CVector3D Ray_Direction(CPoint2D _sp, CPoint2D _lp) const;

	void Set_ViewDistance(double _d);
	void Set_FocalDistance(double _f);
	void Set_Zoom(double _z);
	void Set_Radius(double _r);
	void Set_Sampler(CSampler* _sampler);
private:
	CSampler* sampler;
private:
	double m_d;
	double m_f;
	double m_zoom;
	double m_radius;
};

#endif /* CTHINLENS_H_ */
