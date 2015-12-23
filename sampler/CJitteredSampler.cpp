/*
 * CJitteredSampler.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: Dizhong.Zhu
 */

#include "CJitteredSampler.h"
#include <math.h>
#include <cstdlib>
#include <time.h>

CJitteredSampler::CJitteredSampler() :
		CSampler() {
}

CJitteredSampler::CJitteredSampler(int _nsamples, int _nsets) :
		CSampler(_nsamples, _nsets) {
	GenerateSamples();
}

CJitteredSampler::CJitteredSampler(const CJitteredSampler& _rhs) :
		CSampler(_rhs) {
}

CJitteredSampler::~CJitteredSampler() {
}

void CJitteredSampler::GenerateSamples() {
	int size = (int) sqrt(m_nsamples);
	CPoint2D pt;
	int k, i, j;
	srand(time(nullptr));
	for (k = 0; k < m_nsets; k++) {
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				pt.x = (i + double(rand()) / double(RAND_MAX)) / size;
				pt.y = (j + double(rand()) / double(RAND_MAX)) / size;
				m_samples.push_back(pt);
			}
		}
	}

}
