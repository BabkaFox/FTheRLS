/*
 * Класс описывающий точку на объекте
 *
 *
 *
 */

 #include "Point.h"
#include "SObject.h"
# define M_PI 3.14159265358979323846  /* pi */

//конструктор для точки
Point::Point(double Xi, double Yi, double Zi, double O, double W, float t, int number) {
	this->Xi = Xi;
	this->Yi = Yi;
	this->Zi = Zi;
	this->O = O;
	this->W = W;
	this->t = t;
	this->number = number;

	double a1, a2, a3;
	double b1, b2, b3;
	double mod_a,mod_b;
	double W1,O1;

	//Какой-то комментарий, кодировка всё затерла (: Видимо перевод в радианы

	W1 = W*M_PI/180;
	O1 = O*M_PI/180;

	//Какой-то комментарий, кодировка всё затерла (: [2]

	a1 = sin(W1)*cos(O1);
	a2 = sin(W1)*sin(O1);
	a3 = cos(W1);
	b1 = Xi;
	b2 = Yi;
	b3 = Zi;
	mod_a = sqrt(a1*a1 + a2*a2 + a3*a3); //лол "а3а3а"
	mod_b = sqrt(b1*b1 + b2*b2 + b3*b3);

	this->sigma = fabs ((a1*b1 + a2*b2 + a3*b3)/(mod_a*mod_b));

	this->Ri = sqrt(Xi*Xi + Yi*Yi + Zi*Zi);


}
//Геттеры
double Point::getXi()const {
	return Xi;
}

double Point::getYi()const {
	return Yi;
}

double Point::getZi()const {
	return Zi;
}

double Point::getO()const {
	return O;
}

double Point::getW()const {
	return W;
}

double Point::getRi() const {
	return Ri;
}

double Point::getSigma() const {
	return sigma;
}

int Point::getNumber() const {
	return number;
}

float Point::getT() const {
	return t;
}
