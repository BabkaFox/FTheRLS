/*
 * Класс описывающий объект
 *
 *
 *
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
#ifndef OBJ_H_
#define OBJ_H_

class SObject {

private:
	int sizeObjX;						//размер объекта. на данный момент, будет задаваться случайными числами от 5 до 12
	int sizeObjY;
	int sizeObjZ;
	double objX;
	double objY;
	double objZ;
	double tObj;					//время у объекта
	double R;						//Расстояние от объекта то РЛС
	bool isFly;						//пролетели РЛС ? true : false
	int N;							//Кол-во точек
	int gamma;
	float lyam;
	double Vi;
	double sumUx;
	double sumUy;
	double P;
	double iprOL;
	std::vector<Point> vPoint;		//массив Точек

public:
	//конструкторы
	SObject(int N, double Vi, int gamma);
	SObject(int N, double Vi, int gamma, float tObj,double R,bool isFly,double x,double y,double z, int sizeObjX,int sizeObjY,int sizeObjZ,std::vector<Point> vPoint);

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
	double getObjX() const;
	double getObjY() const;
	double getObjZ() const;
	double getT() const;
	double getR() const;
	bool getFly() const;


	//сеттеры для установки значений
	void setObjX(double objX) {
		SObject::objX = objX;
	}

	void setObjY(double objY) {
		SObject::objY = objY;
	}

	void setObjZ(double objZ) {
		SObject::objZ = objZ;
	}

	void setVPoint(std::vector<Point> const &vPoint) {
		SObject::vPoint = vPoint;
	}

	void setR(double R) {
		SObject::R = R;
	}
};

#endif /* OBJ_H_ */
