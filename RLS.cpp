/*
 * RLS.cpp
 *
 *  Created on: 06.12.2014
 *      Author: �������
 */

#include "RLS.h"


    RLS::RLS(int Xrls, int Yrls, int Zrls, int alpha, float lyam)
    {
	    this->Xrls = Xrls;
		this->Yrls = Yrls;
		this->Zrls = Zrls;
		this->alpha = alpha;
		this->lyam = lyam;


	    double Pper, Dpr, Dper, Fpr, Fper;

		Pper = 1;
		Dpr = 1;
		Dper = 1;
		Fpr = 1;
		Fper = 1;
		lyam = 0.3;

	}

int RLS::getXrls() const {
	return Xrls;
}

int RLS::getYrls() const {
	return Yrls;
}

int RLS::getZrls() const {
	return Zrls;
}

