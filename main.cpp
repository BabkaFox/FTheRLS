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

	int k = 1; //FIXME:Кол-во вызовов move. хз зачем это тут. Удалить если не нужно.

	SObject StartPointMove(N,Vi,gamma);		//Создали объект StartPointMove. и с помощью конструктора
											// StartPointMove() проинициализировали его переменные

	/*while (k --> 0){
		int tend=1000;
		for( int t=0; t<=tend; t+=30){
			StartPointMove.move(t);
		}
	}//while --k*/
	/*while (k --> 0){
		StartPointMove.move();
	}*/
//	StartPointMove.Mosh();

	MoveSObject sObject(StartPointMove);
	Mosh mosh(sObject.getVSObject());
	mosh.moshnost();
	mosh.writeResult();

	return 0;
}




