/*
 * CHammersleySampler.h
 *
 *  Created on: Dec 20, 2015
 *      Author: Dizhong.Zhu
 */

#ifndef CHAMMERSLEYSAMPLER_H_
#define CHAMMERSLEYSAMPLER_H_

#include "CSampler.h"

class CHammersleySampler: public CSampler {
public:
	CHammersleySampler();
	CHammersleySampler(int _nsamples, int _nsets = 83);
	CHammersleySampler(const CHammersleySampler& _rhs);
	~CHammersleySampler();

	void GenerateSamples();

private:
	double phi(int _j);
};

#endif /* CHAMMERSLEYSAMPLER_H_ */
