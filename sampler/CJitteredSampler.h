/*
 * CJitteredSampler.h
 *
 *  Created on: Nov 5, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CJITTEREDSAMPLER_H_
#define CJITTEREDSAMPLER_H_

#include "CSampler.h"

class CJitteredSampler:public CSampler
{
public:
	CJitteredSampler();
	CJitteredSampler(int _nsamples, int _nsets = 83);
	CJitteredSampler(const CJitteredSampler& _rhs);
	~CJitteredSampler();

	void GenerateSamples();
};



#endif /* CJITTEREDSAMPLER_H_ */
