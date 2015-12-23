/*
 * CMultiJitteredSampler.h
 *
 *  Created on: Nov 12, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CMULTIJITTEREDSAMPLER_H_
#define CMULTIJITTEREDSAMPLER_H_

#include "CSampler.h"

class CMultiJitteredSampler: public CSampler {
public:
	CMultiJitteredSampler();
	CMultiJitteredSampler(int _nsamples, int _nsets = 83);
	CMultiJitteredSampler(const CMultiJitteredSampler& _rhs);
	~CMultiJitteredSampler();

	void GenerateSamples();

protected:
	void ShuffleXCoor();
	void ShuffleYCoor();
};

#endif /* CMULTIJITTEREDSAMPLER_H_ */
