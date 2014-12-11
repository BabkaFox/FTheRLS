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
	this->sizeObjX = rand() % 5 + 12;
	this->sizeObjY = rand() % 5 + 12;
	this->sizeObjZ = rand() % 5 + 12;

	//задаем координаты объекта
	this->objX = rand() % 5 + 12;
	this->objY = rand() % 5 + 12;
	this->objZ = rand() % 5 + 12;

	//задаем начальные координаты точкам с учетом местоположения объекта
	for (int numb = 0; numb < N; ++numb){
		double x = objX + rand() % (sizeObjX*sizeObjY*sizeObjZ + 1) + (-sizeObjX*sizeObjY*sizeObjZ/2);	//FIXME: рандом не правильно задает координаты
		double y = objY + rand() % (sizeObjX*sizeObjY*sizeObjZ + 1) + (-sizeObjX*sizeObjY*sizeObjZ/2);
		double z = objZ + rand() % (sizeObjX*sizeObjY*sizeObjZ + 1) + (-sizeObjX*sizeObjY*sizeObjZ/2);
		double O = rand() % 360 + 1;  //от 0 до 360
		double W = rand() % 360 + 1;
		//В массив содаем и заносим объекты Point
		vPoint.push_back(Point(x,y,z,O,W,0.0,numb+1));
	}


}
//конструктор2
SObject::SObject(int N, double Vi, int gamma,double tObj, double x,double y,double z, int sizeObjX,int sizeObjY,int sizeObjZ) {

	this->N = N;
	this->Vi = Vi;
	this->gamma = gamma;
	this->tObj = tObj;

	//задаем размер объекту
	this->sizeObjX = sizeObjX;
	this->sizeObjY = sizeObjY;
	this->sizeObjZ = sizeObjZ;

	//задаем координаты объекта
	this->objX = x;
	this->objY = y;
	this->objZ = z;

	//задаем начальные координаты точкам с учетом местоположения объекта
	for (int numb = 0; numb < N; ++numb){
		x = objX + rand() % (sizeObjX*sizeObjY*sizeObjZ + 1) + (-sizeObjX*sizeObjY*sizeObjZ/2);	//FIXME: рандом не правильно задает координаты
		y = objY + rand() % (sizeObjX*sizeObjY*sizeObjZ + 1) + (-sizeObjX*sizeObjY*sizeObjZ/2);
		z = objZ + rand() % (sizeObjX*sizeObjY*sizeObjZ + 1) + (-sizeObjX*sizeObjY*sizeObjZ/2);
		double O = rand() % 360 + 1;  //от 0 до 360
		double W = rand() % 360 + 1;
		//В массив содаем и заносим объекты Point
		vPoint.push_back(Point(x,y,z,O,W,tObj,numb+1));
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

int SObject::getObjX() const {
	return objX;
}

int SObject::getObjY() const {
	return objX;
}

int SObject::getObjZ() const {
	return objX;
}