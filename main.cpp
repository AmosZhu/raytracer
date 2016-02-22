/*
 * main.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Dizhong.Zhu
 */

#include <GL/freeglut.h>
#include "CDisplayScreen.h"
#include "CWorld.h"

#include "UT_Sinusoid.h"
#include "UT_Basic.h"
#include "UT_NRook.h"
#include "UT_MapDisk.h"
#include "UT_MapSemisphere.h"
#include "UT_AxixAlignedPerspective.h"
#include "UT_Camera.h"

int main(int argc, char *argv[]) {
	//UT_MapSemisphere();
	//UT_Basic();
	//UT_AxixAlignedPerspective();
	//UT_PinholeCamera();
	//UT_ThinlensCamera();
	//UT_FishEyeCamera();
	UT_StereoCamera();
	return 1;
}

