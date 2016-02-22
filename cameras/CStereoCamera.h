/*
 * CStereoCamera.h
 *
 *  Created on: Jan 7, 2016
 *      Author: Dizhong.Zhu
 */

#ifndef CSTEREOCAMERA_H_
#define CSTEREOCAMERA_H_

#include "CCamera.h"

typedef enum {
	parallel, transverse,
} ViewingType;

class CStereoCamera: public CCamera {
public:
	CStereoCamera();
	CStereoCamera(const CStereoCamera& _rhs);
	~CStereoCamera();

	void Set_Stereo_angle(double _angle);
	void Set_Left_camera(CCamera* _camera);
	void Set_Right_camera(CCamera* _camera);
	void Set_PixelGap(int _gap);
	void Setup_Camera();
	void Render_Scence(CWorld* _world);

	void Using_Parallel();
	void Using_Transverse();

private:
	ViewingType m_type;
	double m_beta;
	CCamera* m_leftCamera;
	CCamera* m_rightCamera;
	int m_pixelGap;
};

#endif /* CSTEREOCAMERA_H_ */
