/*
 * Move.cpp
 *
 *  Created on: 06.12.2014
 *      Author: �������
 */

//------------����� �������� ��������� �����---------------//
#include "PointMove.h"
#include "Mosh.h"
# define M_PI 3.14159265358979323846  /* pi */
using namespace std;

//конструктор
PointMove::PointMove(int N, double Vi, int gamma) {

	this->N = N;
	this->Vi = Vi;
	this->gamma = gamma;
}


void PointMove::move(){

	double  Vx=0,		//что-то типа начальных координат точек
			Vy=0,
			Vz=0,
			X0=1.0,
			Y0=1.0,
			Z0=1.0;

	Vx = getVi()*cos(getGamma());    //Равносильно Vx = Vi*cos(gamma). По "слово забыл" инкапсуляция должно быть так написанно
	Vy = getVi()*sin(getGamma());
	Vz = 0;

	int tend = 1000;
	for (int numb = 0; numb < getN(); ++numb){
		for (int t = 0; t < tend; t+=30) {
			double x = (Vx*t+X0);
			double y = (Vy*t+Y0);
			double z = (Vz*t+Z0);
			double O = 180 + 1;
			double W = 360 + 1;
			//В массив содаем и заносим объекты Point
			vPoint.push_back(Point(x,y,z,O,W,t,numb+1));
		}
	}

	/*for (int i = 0; i <vPoint.size(); ++i) {
		cout<<"Точка: "<<vPoint[i].getNumber()
				<<" X: "<<vPoint[i].getXi()
				<<" Y: "<<vPoint[i].getYi()
				<<" Z: "<<vPoint[i].getZi()
				<<" O: "<<vPoint[i].getO()
				<<" W: "<<vPoint[i].getW()
				<<" t: "<<vPoint[i].getT()
				<<endl;
	}*/
	//Создаем объект который будет считать мощность по разным алгоритмам

	Mosh mosh(vPoint);
	mosh.moshnost();
	mosh.writeResult();
}


std::vector<Point> const &PointMove::getVPoint() const {
	return vPoint;
}
//Геттеры
int PointMove::getN() const {
	return N;
}

double PointMove::getVi() const {
	return Vi;
}

int PointMove::getGamma() const {
	return gamma;
}

float PointMove::getLyam() const {
	return lyam;
}


double PointMove::getSumUx() const {
	return sumUx;
}

double PointMove::getSumUy() const {
	return sumUy;
}

double PointMove::getP() const {
	return P;
}

double PointMove::getIprOL() const {
	return iprOL;
}
