/*
 * CNRookSampler.cpp
 *
 *  Created on: Nov 3, 2015
 *      Author: Dizhong.Zhu
 */

#include "CNRookSampler.h"
#include <cstdlib>
#include <time.h>

CNRookSampler::CNRookSampler() :
		CSampler() {
}

CNRookSampler::CNRookSampler(int _nsamples, int _nsets) :
		CSampler(_nsamples, _nsets) {
	GenerateSamples();
}

CNRookSampler::CNRookSampler(const CNRookSampler& _rhs) :
		CSampler(_rhs) {
}

CNRookSampler::~CNRookSampler() {
}

void CNRookSampler::GenerateSamples() {
	CPoint2D pt;
	srand(time(nullptr));
	for (int i = 0; i < m_nsets; i++) {
		for (int j = 0; j < m_nsamples; j++) {
			pt.x = (double(j) + double(rand()) / double(RAND_MAX)) / m_nsamples;
			pt.y = (double(j) + double(rand()) / double(RAND_MAX)) / m_nsamples;
			m_samples.push_back(pt);
		}
	}
	ShuffleXCoor();
	ShuffleYCoor();
}

