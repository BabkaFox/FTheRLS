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

class SObject {

private:
	int sizeObjX;						//размер объекта. на данный момент, будет задаваться случайными числами от 5 до 12
	int sizeObjY;
	int sizeObjZ;
	int objX;
	int objY;
	int objZ;
	int N;							//Кол-во точек
	int gamma;
	float lyam;
	double Vi;
	double sumUx;
	double sumUy;
	double P;
	double iprOL;
	std::vector<Point> vPoint;		//массив Точек
	std::vector<double> posObj;		//массив кординат объекта

public:
	SObject() {
	}

	SObject(int N, double Vi, int gamma);		//конструктор класса вместо getPointMove
	void move();

	int getN() const;
	int getGamma() const;
	float getLyam() const;
	double getP() const;
	double getVi() const;
	double getSumUx() const;
	double getSumUy() const;
	double getIprOL() const;
	std::vector<Point> const &getVPoint() const;
	//геттеры для получения размера объекта
	int getSizeObjX() const;
	int getSizeObjY() const;
	int getSizeObjZ() const;
	//геттеры для получения координат объекта
	int getObjX() const;
	int getObjY() const;
	int getObjZ() const;
};

#endif /* MOVE_H_ */
