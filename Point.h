/*
 * Point.h
 *
 *  Created on: 06.12.2014
 *      Author: �������
 */

#include <fstream>
#include <math.h>
#ifndef OL_H_
#define OL_H_

class Point
{
private:
	double Xi;			//
	double Yi;			//координаты
	double Zi;			//
	double O;			//хрень
	double W;			//вторая хрень
	double Ri;		//-_- третья
	double sigma;	//ну, эт сигма
	float t; 		//время в которое точечка находится на координатах Хи Уи Зи
	int number;		//номер точечки

public:
	//конструктор. С помощью него, создается объект Point
	Point(double Xi, double Yi, double Zi, double O, double W, float t, int number);

	//Геттеры. Нужны для получения значений объекта Point. Const означает, что переменная не будет изменена(случайно)
	double getXi()const;
	double getYi()const;
	double getZi()const;
	double getO()const;
	double getW()const;
	double getRi() const;
	double getSigma() const;
	int getNumber() const;
	float getT() const;


};




#endif /* OL_H_ */
