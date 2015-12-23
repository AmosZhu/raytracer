/*
 * CNRookSampler.h
 *
 *  Created on: Nov 3, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CNROOKSAMPLER_H_
#define CNROOKSAMPLER_H_

#include "CSampler.h"

class CNRookSampler: public CSampler {
public:
	CNRookSampler();
	CNRookSampler(int _nsamples, int _nsets = 83);
	CNRookSampler(const CNRookSampler& _rhs);
	~CNRookSampler();

	void GenerateSamples();
};

#endif /* CNROOKSAMPLER_H_ */
