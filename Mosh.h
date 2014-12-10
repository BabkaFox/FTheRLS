#include "RLS.h"
#include "Point.h"
#include "SObject.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "SObject.h"

#ifndef MOSH_H_
#define MOSH_H_

class Mosh{
private:
    double P;
    double iprOL;
    std::vector<Point> vPoint;		//массив Точек
    std::vector<double> Uy;
    std::vector<double> Ux;
    std::vector<double> Ppr;
    SObject obj;                    //сюда положим объект
public:
    //конструктор
//    Mosh(std::vector<Point> &vPoint);
    Mosh(SObject &obj);
    //первый алгоритм..бла-бла
    void moshnost();
    //запись в файл
    void writeResult();

};

#endif

