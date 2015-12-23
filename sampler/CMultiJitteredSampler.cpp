/*
 * CMultiJitteredSampler.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: Dizhong.Zhu
 */

#include "CMultiJitteredSampler.h"
#include <math.h>
#include <cstdlib>
#include <time.h>

CMultiJitteredSampler::CMultiJitteredSampler() :
		CSampler() {
}

CMultiJitteredSampler::CMultiJitteredSampler(int _nsamples, int _nsets) :
		CSampler(_nsamples, _nsets) {
	GenerateSamples();
}

CMultiJitteredSampler::CMultiJitteredSampler(const CMultiJitteredSampler& _rhs) :
		CSampler(_rhs) {
}

CMultiJitteredSampler::~CMultiJitteredSampler() {
}

void CMultiJitteredSampler::GenerateSamples() {
	int nJittSize = (int) sqrt(m_nsamples);
	int offset = -1;
	CPoint2D pt;
	srand(time(nullptr));
	for (int i = 0; i < m_nsets; i++) {
		for (int j = 0; j < m_nsamples; j++) {
			if (j % nJittSize == 0) {
				offset++;
			}
			pt.x = (double) (j % nJittSize * nJittSize + offset
					+ double(rand()) / double(RAND_MAX)) / m_nsamples;
			pt.y = (double) (j + double(rand()) / double(RAND_MAX))
					/ m_nsamples;
			m_samples.push_back(pt);
		}
	}
	ShuffleXCoor();
	ShuffleYCoor();

}

void CMultiJitteredSampler::ShuffleXCoor() {
	int nJittSize = (int) sqrt(m_nsamples);
	srand(time(nullptr));
	double temp;
	int target;
	for (int k = 0; k < m_nsets; k++) {
		for (int i = 0; i < nJittSize; i++) {
			for (int j = 0; j < nJittSize; j++) {
				target = rand() % nJittSize;
				temp = m_samples[i + target * nJittSize + k * m_nsamples].x;
				m_samples[i + target * nJittSize + k * m_nsamples].x =
						m_samples[i + j * nJittSize + k * m_nsamples].x;
				m_samples[i + j * nJittSize + k * m_nsamples].x = temp;
			}
		}
	}
}

void CMultiJitteredSampler::ShuffleYCoor() {
	int nJittSize = (int) sqrt(m_nsamples);
	srand(time(nullptr));
	double temp;
	int target;
	for (int k = 0; k < m_nsets; k++) {
		for (int i = 0; i < nJittSize; i++) {
			for (int j = 0; j < nJittSize; j++) {
				target = rand() % nJittSize;
				temp = m_samples[i * nJittSize + target + k * m_nsamples].y;
				m_samples[i * nJittSize + target + k * m_nsamples].y =
						m_samples[i * nJittSize + j + k * m_nsamples].y;
				m_samples[i * nJittSize + j + k * m_nsamples].y = temp;
			}
		}
	}
}
