/*
 * RLS.h
 *
 *  Created on: 06.12.2014
 *      Author: Евгения
 */
#include <fstream>
#include <math.h>
#ifndef RLS_H_
#define RLS_H_

class RLS
{
    public:
	int Xrls;
	int Yrls;
	int Zrls;
	int alpha;

	float Ri;
	float Pri;
	float lyam;

	float getlyam();
	void getRLS(int Xrls, int Yrls, int Zrls, int alpha, float lyam);

};


#endif /* RLS_H_ */
