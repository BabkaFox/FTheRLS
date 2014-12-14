/*
 * main.cpp
 *
 *  Created on: 06.12.2014
 *      Author: �������
 */

#include <iostream>
#include <vector>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include "ConfigINI.h"
#include "RLS.h"
#include "SObject.h"
#include "Mosh.h"
#include "MoveSObject.h"

using namespace std;

int main() {
	srand(time(NULL)); //Сброс рандомайзера
	ConfigINI *ini = new ConfigINI("config.ini");

	float Vi 	= ini->getIntValue("param", "V");
	float gamma = ini->getIntValue("param", "gamma");
	int N 	    = ini->getIntValue("param", "N");
	int X 	    = ini->getIntValue("coord", "objX");//Начальные координаты объекта(цели)
	int Y 	    = ini->getIntValue("coord", "objY");////Начальные координаты объекта(цели)
	int Z 	    = ini->getIntValue("coord", "objZ");////Начальные координаты объекта(цели)

	delete ini;
	//Создаем объект sObject. и с помощью конструктора
	//проинициализировали его переменные
	SObject sObject(N,Vi,gamma,X,Y,Z);

	//Создаем объект RLS с координатами х = 25, у = 30, z = 1
	RLS rls(2,2,1,1,1.0);

	//Моделируем движение. Передаем объект с точками и РЛС.
	//Елси true - то перемещаемся змейкой. Иначе летим по прямой
	MoveSObject moveSObject(sObject, rls, true);

	//Мощьность сигнала
	Mosh mosh(moveSObject.getVSObject());
	mosh.moshnost();
	mosh.writeResult2();
//	mosh.writeResultTest();

	return 0;
}




