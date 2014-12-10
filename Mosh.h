#include "RLS.h"
#include "Point.h"
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

public:
    //конструктор
    Mosh(std::vector<Point> &vPoint);
    //первый алгоритм..бла-бла
    void moshnost();
    //запись в файл
    void writeResult();

};

#endif

