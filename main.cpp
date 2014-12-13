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
	int X 	    = ini->getIntValue("coord", "objX");
	int Y 	    = ini->getIntValue("coord", "objY");
	int Z 	    = ini->getIntValue("coord", "objZ");

	delete ini;

	SObject sObject(N,Vi,gamma,X,Y,Z);		//Создали объект StartPointMove. и с помощью конструктора
											// StartPointMove() проинициализировали его переменные

	RLS rls(2,2,1,1,1.0);					//Создаем объект RLS с координатами х = 25, у = 30, z = 1

	MoveSObject moveSObject(sObject, rls);	//Моделируем движение. Передаем объект с точками и РЛС



	Mosh mosh(moveSObject.getVSObject());
	mosh.moshnost();
	mosh.writeResult2();

	return 0;
}




