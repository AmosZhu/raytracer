/*
 * CHammersleySampler.cpp
 *
 *  Created on: Dec 20, 2015
 *      Author: Dizhong.Zhu
 */

#include "CHammersleySampler.h"

CHammersleySampler::CHammersleySampler() :
		CSampler() {
}

CHammersleySampler::CHammersleySampler(int _nsamples, int _nsets) :
		CSampler(_nsamples, _nsets) {
	GenerateSamples();
}

CHammersleySampler::CHammersleySampler(const CHammersleySampler& _rhs) :
		CSampler(_rhs) {
}

CHammersleySampler::~CHammersleySampler() {
}

double CHammersleySampler::phi(int _j) {
	double res = 0.0;
	double c = 0.5;

	while (_j) {
		res += c * (double) (_j % 2);
		_j/=2;
		c*=0.5;
	}

	return res;
}

void CHammersleySampler::GenerateSamples() {
	int i, j;
	CPoint2D pt;
	for (i = 0; i < m_nsets; i++) {
		for (j = 0; j < m_nsamples; j++) {
			pt = CPoint2D((double)j/m_nsamples, phi(j));
			m_samples.push_back(pt);
		}
	}
}

