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
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>
#include "ConfigINI.h"
#include <cstdlib>
#include "RLS.h"
#include "Point.h"
#include "SObject.h"
#include "CountSign.h"
#include "Mosh.h"
#include "MoveSObject.h"

using namespace std;

int main() {
	srand(time(NULL)); //Сброс рандомайзера
	ConfigINI *ini = new ConfigINI("config.ini");

	float Vi 	= ini->getIntValue("param", "V");
	float gamma = ini->getIntValue("param", "gamma");
	int N 	    = ini->getIntValue("param", "N");

	delete ini;

	SObject sObject(N,Vi,gamma);		//Создали объект StartPointMove. и с помощью конструктора
											// StartPointMove() проинициализировали его переменные

	RLS rls(23,16,1,1,1.0);					//Создаем объект RLS с координатами х = 25, у = 30, z = 1

	MoveSObject moveSObject(sObject, rls);	//Моделируем движение. Передаем объект с точками и РЛС



	Mosh mosh(moveSObject.getVSObject());
	mosh.moshnost();
	mosh.writeResult2();

	return 0;
}




