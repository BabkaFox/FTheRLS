/*
 * Класс описывающий движение
 *
 *
 *
 */

#include "Point.h"
#include "MoveSObject.h"
#include "Mosh.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <sstream>


MoveSObject::MoveSObject(SObject &obj1) {
    SObject obj = obj1;

    double  Vx=0,		//что-то типа начальных координат точек
            Vy=0,
            Vz=0;

    Vx = obj.getVi()*cos(obj.getGamma());
    Vy = obj.getVi()*sin(obj.getGamma());
    Vz = 0;
    vSObject.push_back(obj1);
    int tend = 1000;
    for (int t = 30; t < tend; t+=30) {
//        vSObject[t/30+1].setObjX((vSObject[t/30].getVi()*cos(vSObject[t/30].getGamma()))*t+vSObject[t/30].getObjX());
//        vSObject[t/30+1].setObjY((vSObject[t/30].getVi()*sin(vSObject[t/30].getGamma()))*t+vSObject[t/30].getObjY());
//        vSObject[t/30+1].setObjZ(t+vSObject[t/30].getObjZ());

        double x = (Vx*t+vSObject[t/30-1].getObjX());
        double y = (Vy*t+vSObject[t/30-1].getObjY());
        double z = (Vz*t+vSObject[t/30-1].getObjZ());
        //Содаем и заносим объекты
        vSObject.push_back(SObject(obj.getN(),obj.getVi(),obj.getGamma(),t,x,y,z,obj.getSizeObjX(),obj.getSizeObjX(),obj.getSizeObjX(),obj.getVPoint()));
    }
}

void MoveSObject::move() {
    Mosh mosh(vSObject);
    mosh.moshnost();
    mosh.writeResult2();
}

std::vector<SObject> const MoveSObject::getVSObject() const {
    return vSObject;
}
