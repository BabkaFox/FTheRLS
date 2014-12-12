/*
 * Класс описывающий объект
 *
 *
 *
 */


#include "SObject.h"
#include "Mosh.h"
# define M_PI 3.14159265358979323846  /* pi */
using namespace std;

//конструктор
SObject::SObject(int N, double Vi, int gamma) {

	this->N = N;
	this->Vi = Vi;
	this->gamma = gamma;
	this->tObj = 0.0;

	//задаем размер объекту
	this->sizeObjX = 12;
	this->sizeObjY = 12;
	this->sizeObjZ = 12;

	//задаем координаты объекта //на данный момент РЛС на координатах rls(25,30,0);
	this->objX = 3;
	this->objY = 2;
	this->objZ = 12;

	//задаем начальные координаты точкам
	for (int numb = 0; numb < N; ++numb){
		double x = rand() % (sizeObjX + 1) + (-sizeObjX/2);
		double y = rand() % (sizeObjY + 1) + (-sizeObjY/2);
		double z = rand() % (sizeObjZ + 1) + (-sizeObjZ/2);
		double O = rand() % 360 + 1;  //от 0 до 360
		double W = rand() % 360 + 1;
		//В массив содаем и заносим объекты Point
		vPoint.push_back(Point(x,y,z,O,W,0.0,numb+1));
	}
}
//конструктор2 получает новые X,Y,Z и предыдущий массив точек для получения старых координат
SObject::SObject(int N, double Vi, int gamma,float tObj, double x,double y,double z, int sizeObjX,int sizeObjY,int sizeObjZ,vector<Point> vPoint) {

	this->N = N;
	this->Vi = Vi;
	this->gamma = gamma;
	this->tObj = tObj;

	//задаем размер объекту
	this->sizeObjX = sizeObjX;
	this->sizeObjY = sizeObjY;
	this->sizeObjZ = sizeObjZ;

	//задаем новые координаты объекта
	this->objX = x;
	this->objY = y;
	this->objZ = z;

	//задаем координаты точкам
	for (int numb = 0; numb < N; ++numb){
		x = x + vPoint[numb].getXi();
		y = y + vPoint[numb].getYi();
		z = z + vPoint[numb].getZi();
		double O = vPoint[numb].getO();
		double W = vPoint[numb].getW();  	//TODO: найти другое решение. а это это пздц какой то
		//В массив содаем и заносим объекты Point
		this->vPoint.push_back(Point(x,y,z,O,W,tObj,numb+1));
	}
}

void SObject::move(){
	//двигаем
	double  Vx=0,		//что-то типа начальных координат точек
			Vy=0,
			Vz=0;

	Vx = getVi()*cos(getGamma());
	Vy = getVi()*sin(getGamma());
	Vz = 0;

	int tend = 1000;
	for (int numb = 0; numb < getN(); ++numb){
		for (int t = 0; t < tend; t+=30) {
			double x = (Vx*t+vPoint[numb].getXi());	//получение новой координаты Х путем сложения Вх+т со старой координатой
			double y = (Vy*t+vPoint[numb].getYi());
			double z = (Vz*t+vPoint[numb].getZi());
			double O = vPoint[numb].getO();
			double W = vPoint[numb].getW();
			//Содаем и заносим объекты Point
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

	/*Mosh mosh(vPoint);
	mosh.moshnost();
	mosh.writeResult();*/
}


std::vector<Point> const &SObject::getVPoint() const {
	return vPoint;
}
//Геттеры
int SObject::getN() const {
	return N;
}

double SObject::getVi() const {
	return Vi;
}

int SObject::getGamma() const {
	return gamma;
}

float SObject::getLyam() const {
	return lyam;
}


double SObject::getSumUx() const {
	return sumUx;
}

double SObject::getSumUy() const {
	return sumUy;
}

double SObject::getP() const {
	return P;
}

double SObject::getIprOL() const {
	return iprOL;
}

int SObject::getSizeObjX() const {
	return sizeObjX;
}

int SObject::getSizeObjY() const {
	return sizeObjX;
}

int SObject::getSizeObjZ() const {
	return sizeObjX;
}

double SObject::getT() const {
	return tObj;
}

double SObject::getObjX() const {
	return objX;
}

double SObject::getObjY() const {
	return objY;
}

double SObject::getObjZ() const {
	return objZ;
}