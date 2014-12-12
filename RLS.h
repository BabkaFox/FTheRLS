/*
 * RLS.h
 *
 *  Created on: 06.12.2014
 *      Author: �������
 */
#include <fstream>
#include <math.h>
#ifndef RLS_H_
#define RLS_H_

class RLS
{
private:
	int Xrls;
	int Yrls;
	int Zrls;
	int alpha;
	float Ri;
	float Pri;
	float lyam;

public:
	//Конструктор рлс
	RLS(int Xrls, int Yrls, int Zrls, int alpha, float lyam);

	//геттеры

	int getXrls() const;
	int getYrls() const;
	int getZrls() const;
	int getAlpha() const;
	float getRi() const;
	float getPri() const;
	float getLyam() const;
};


#endif /* RLS_H_ */
