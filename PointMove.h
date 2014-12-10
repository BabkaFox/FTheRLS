/*
 * Move.h
 *
 *  Created on: 06.12.2014
 *      Author: �������
 */

#include "RLS.h"
#include "Point.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#ifndef MOVE_H_
#define MOVE_H_

class PointMove{

private:
	int N;							//Кол-во точек
	int gamma;
	float lyam;
	double Vi;
	double sumUx;
	double sumUy;
	double P;
	double iprOL;
//	std::vector<double> Uy;
//	std::vector<double> Ux;
//	std::vector<double> Ppr;
	std::vector<Point> vPoint;		//массив Точек

public:
	PointMove(int N, double Vi, int gamma);		//конструктор класса вместо getPointMove
	void move();
	int getN() const;
	int getGamma() const;
	float getLyam() const;
	double getP() const;
	double getVi() const;
	double getSumUx() const;
	double getSumUy() const;
	double getIprOL() const;
//	std::vector<double> const &getUx() const;
//	std::vector<double> const &getUy() const;
//	std::vector<double> const &getPpr() const;
	std::vector<Point> const &getVPoint() const;
};

#endif /* MOVE_H_ */
