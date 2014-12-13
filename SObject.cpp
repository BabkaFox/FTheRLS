/*
 * Класс описывающий объект
 *
 *
 *
 */


#include "SObject.h"
# define M_PI 3.14159265358979323846  /* pi */
using namespace std;

//конструктор
SObject::SObject(int N, double Vi, int gamma, int objX, int objY, int objZ) {

	this->N = N;
	this->Vi = Vi;
	this->gamma = gamma;
	this->tObj = 0.0;
	this->isFly = false;	//Еще не пролетели мимо РЛС

	//Начальное расстояние от цели до РЛС не получится посчитать. только после начала движения
	this->R = 0;

	//задаем размер объекту
	this->sizeObjX = 12;
	this->sizeObjY = 12;
	this->sizeObjZ = 12;

	//задаем координаты объекта //на данный момент РЛС на координатах rls(25,30,0);
	this->objX = objX;
	this->objY = objY;
	this->objZ = objZ;

	//задаем начальные координаты точкам
	for (int numb = 0; numb < N; ++numb){
		double x = (rand() % (sizeObjX + 1) + (-sizeObjX/2)) + objX;
		double y = (rand() % (sizeObjY + 1) + (-sizeObjY/2)) + objY;
		double z = (rand() % (sizeObjZ + 1) + (-sizeObjZ/2)) + objZ;
		double O = rand() % 360 + 1;  //от 0 до 360
		double W = rand() % 360 + 1;
		//В массив содаем и заносим объекты Point
		vPoint.push_back(Point(x,y,z,O,W,0.0,numb+1));
	}
}
//конструктор2 получает новые X,Y,Z и предыдущий массив точек для получения старых координат

SObject::SObject(SObject oldObj, float tObj, double R, bool isFly, double x, double y, double z) {
	this->N = oldObj.getN();
	this->Vi = oldObj.getVi();
	this->gamma = oldObj.getGamma();
	this->tObj = tObj;	//устанавливаем новое время
	this->R = R;		//новое расстояние до рлс
	this->isFly = isFly;

	//задаем размер объекту из старого
	this->sizeObjX = oldObj.getSizeObjX();
	this->sizeObjY = oldObj.getSizeObjY();
	this->sizeObjZ = oldObj.getSizeObjZ();

	//задаем новые координаты объекта
	this->objX = x + oldObj.getObjX();
	this->objY = y + oldObj.getObjY();
	this->objZ = z + oldObj.getObjZ();

	//задаем координаты точкам
	for (int numb = 0; numb < N; ++numb){
		double Px = x + oldObj.getVPoint()[numb].getXi();
		double Py = y + oldObj.getVPoint()[numb].getYi();
		double Pz = z + oldObj.getVPoint()[numb].getZi();
		double O = oldObj.getVPoint()[numb].getO();
		double W = oldObj.getVPoint()[numb].getW();
		//В массив содаем и заносим объекты Point
		this->vPoint.push_back(Point(Px,Py,Pz,O,W,tObj,numb+1));
	}
}



vector<Point> const &SObject::getVPoint() const {
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

double SObject::getR() const {
	return R;
}

bool SObject::getFly() const {
	return isFly;
}


