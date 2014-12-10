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
#include "PointMove.h"
#include "CountSign.h"
using namespace std;

int main() {

	ConfigINI *ini = new ConfigINI("config.ini");

	float Vi 	= ini->getIntValue("param", "V");
	float gamma = ini->getIntValue("param", "gamma");
	int N 	    = ini->getIntValue("param", "N");

	delete ini;

	int k = 1; //FIXME:Кол-во вызовов move. хз зачем это тут. Удалить если не нужно.

	PointMove StartPointMove(N,Vi,gamma);		//Создали объект StartPointMove. и с помощью конструктора
												// StartPointMove() проинициализировали его переменные

	/*while (k --> 0){
		int tend=1000;
		for( int t=0; t<=tend; t+=30){
			StartPointMove.move(t);
		}
	}//while --k*/
	while (k --> 0){
		StartPointMove.move();
	}
//	StartPointMove.Mosh();

	return 0;
}




