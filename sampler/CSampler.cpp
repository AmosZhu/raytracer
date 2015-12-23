/*
 * CSampler.cpp
 *
 *  Created on: Nov 3, 2015
 *      Author: Dizhong.Zhu
 */

#include "CSampler.h"
#include <cstdlib>
#include <math.h>

CSampler::CSampler() :
		m_nsamples(0), m_nsets(83), m_count(0) {

}

CSampler::CSampler(int _nsamples, int _nsets) :
		m_nsamples(_nsamples), m_nsets(_nsets), m_count(0) {
}

CSampler::CSampler(const CSampler& _rhs) {
	m_nsamples = _rhs.m_nsamples;
	m_nsets = _rhs.m_nsets;
	m_samples = _rhs.m_samples;
	m_diskSamples = _rhs.m_diskSamples;
	m_semisphereSamples = _rhs.m_semisphereSamples;
	m_count = _rhs.m_count;
}

CSampler::~CSampler() {
	m_samples.clear();
	m_diskSamples.clear();
	m_semisphereSamples.clear();
}

void CSampler::Map_sample_to_unit_disk(void) {
	int i, j;
	double r, phi;
	CPoint2D spt;  //Sample point

	m_diskSamples.reserve(m_nsamples * m_nsets);

	for (j = 0; j < m_nsets; j++) {
		for (i = 0; i < m_nsamples; i++) {
			spt.x = 2.0 * m_samples[i].x - 1.0;
			spt.y = 2.0 * m_samples[i].y - 1.0;

			if (spt.x > spt.y && spt.x > -spt.y) //Sector 1
					{
				r = spt.x;
				phi = spt.y / spt.x;
			} else if (spt.x < spt.y && spt.x > -spt.y)  //Sector 2
					{
				r = spt.y;
				phi = 2 - spt.x / spt.y;
			} else if (spt.x < spt.y && spt.x < -spt.y) //sector 3
					{
				r = -spt.x;
				phi = 4 - spt.y / spt.x;
			} else {
				r = -spt.y;
				phi = 6 - spt.x / spt.y;
			}
			phi *= PI / 4.0;

			m_diskSamples[i + j * m_nsamples].x = r * cos(phi);
			m_diskSamples[i + j * m_nsamples].y = r * sin(phi);
		}
	}
}

void CSampler::Map_sample_to_unit_semisphere(const double _e) {
	CPoint3D pt;
	int i, j;
	double costheta, sintheta, cosphi, sinphi;
	double r1;
	m_semisphereSamples.reserve(m_nsets * m_nsamples);
	for (j = 0; j < m_nsets; j++) {
		for (i = 0; i < m_nsamples; i++) {
			r1 = 2 * PI * m_samples[i].x;
			cosphi = cos(r1);
			sinphi = sin(r1);
			costheta = pow(1.0 - m_samples[i].y, 1 / (_e + 1));
			sintheta = sqrt(1 - costheta * costheta);
			double pu = sintheta * cosphi;
			double pv = sintheta * sinphi;
			double pw = costheta;
			m_semisphereSamples[j * m_nsamples + i] = CPoint3D(pv, pw, pu);
		}
	}
}

CPoint2D CSampler::Sample_unit_square(void) {
	return m_samples[m_count++ % (m_nsamples * m_nsets)];
}

CPoint2D CSampler::Sample_unit_disk(void) {
	return m_diskSamples[m_count++ % (m_nsamples * m_nsets)];
}

CPoint3D CSampler::Sample_unit_semisphere() {
	return m_semisphereSamples[m_count++ % (m_nsamples * m_nsets)];
}

void CSampler::ShuffleXCoor() {
	int target;
	double temp;
	for (int i = 0; i < m_nsets; i++) {
		for (int j = 0; j < m_nsamples; j++) {
			target = std::rand() % m_nsamples;
			temp = m_samples[j + i * m_nsamples].x;
			m_samples[j + i * m_nsamples].x =
					m_samples[target + i * m_nsamples].x;
			m_samples[target + i * m_nsamples].x = temp;
		}
	}
}

void CSampler::ShuffleYCoor() {
	int target;
	double temp;
	for (int i = 0; i < m_nsets; i++) {
		for (int j = 0; j < m_nsamples; j++) {
			target = rand() % m_nsamples;
			temp = m_samples[j + i * m_nsamples].y;
			m_samples[j + i * m_nsamples].y =
					m_samples[target + i * m_nsamples].y;
			m_samples[target + i * m_nsamples].y = temp;
		}
	}
}
