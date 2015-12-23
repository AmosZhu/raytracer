/*
 * CSampler.h
 *
 *  Created on: Nov 3, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CSAMPLER_H_
#define CSAMPLER_H_

#include <vector>
#include "CPoint2D.h"
#include "CPoint3D.h"
#include "common.h"

class CSampler {
public:
	CSampler();
	CSampler(int _nsamples, int _nsets = 83);
	CSampler(const CSampler& _rhs);
	virtual ~CSampler();

	void Map_sample_to_unit_disk(void);
	void Map_sample_to_unit_semisphere(const double _e=0);

	CPoint2D Sample_unit_square(void);
	CPoint2D Sample_unit_disk(void);
	CPoint3D Sample_unit_semisphere(void);
	virtual void GenerateSamples()=0;

protected:
	virtual void ShuffleXCoor();
	virtual void ShuffleYCoor();

protected:
	int m_nsamples;
	int m_nsets;
	int m_count;
	std::vector<CPoint2D> m_samples;
	std::vector<CPoint2D> m_diskSamples;
	std::vector<CPoint3D> m_semisphereSamples;

};

#endif /* CSAMPLER_H_ */
