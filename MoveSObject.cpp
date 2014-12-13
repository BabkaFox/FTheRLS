/*
 * Класс описывающий движение
 *
 *
 *
 */

#include "Point.h"
#include "MoveSObject.h"
#include "Mosh.h"

# define M_PI 3.14159265358979323846  /* pi */



MoveSObject::MoveSObject(SObject obj, RLS rls) {

    vSObject.push_back(obj); //получили один готовый объект(тело) сразу поместили его в массив перемещений
//скорее всего в комментариях сказано не совсем то, что происходит на самом деле. например "вектор тела" может быть не вектором тела

    //вектор тела
    double vecObjX = obj.getObjX();
    double vecObjY = obj.getObjY();
//    double vecObjZ = obj.getObjZ();

    //строим треугольник
    double vecRlsX = rls.getXrls() - vecObjX;
    double vecRlsY = rls.getYrls() - vecObjY;
    //гипотенуза - расстояние от начала движения цели, до РЛС
    double gipgip = sqrt(vecRlsX*vecRlsX+vecRlsY*vecRlsY);

    //так как мы сразу не смогли найти расстояние. задаем его тут
    vSObject[0].setR(gipgip);
    //находим угол в градусах
    double degTheta = acos(vecRlsX/gipgip)*180/M_PI;
    //начинаем двигать цель
    double  Vx=0,Vy=0,Vz=0;

    //Выбираем направление
    if(obj.getObjX() < 0 && obj.getObjY() > 0){
        Vx = obj.getVi()*cos(obj.getGamma()* (M_PI /180) + degTheta * (M_PI /180));
        Vy = obj.getVi()*sin(obj.getGamma()* (M_PI /180) + degTheta * (M_PI /180)) * (-1);
        Vz = 0;
    } else if (obj.getObjX() > 0 && obj.getObjY() > 0 && degTheta > 90){
        degTheta = degTheta - 90;
        Vx = obj.getVi()*sin(obj.getGamma()* (M_PI /180) + degTheta * (M_PI /180)) * (-1);
        Vy = obj.getVi()*cos(obj.getGamma()* (M_PI /180) + degTheta * (M_PI /180)) * (-1);
        Vz = 0;
    } else {
        Vx = obj.getVi()*cos(obj.getGamma()* (M_PI /180) + degTheta * (M_PI /180));
        Vy = obj.getVi()*sin(obj.getGamma()* (M_PI /180) + degTheta * (M_PI /180));
        Vz = 0;
    }
    int tend = 1000;
    for (int t = 30; t < tend; t+=30) {
        double x = Vx * t + vSObject[t/30-1].getObjX();
        double y = Vy * t + vSObject[t/30-1].getObjY();
        double z = (Vz*t+vSObject[t/30-1].getObjZ());
        //строим новый треугольник, чтобы найти гипотенузу.
        vecRlsX = rls.getXrls() - x;
        vecRlsY = rls.getYrls() - y;

        bool isFly = false;
        gipgip = sqrt(vecRlsX*vecRlsX+vecRlsY*vecRlsY);
        (vSObject[t/30-1].getR() < gipgip) ? isFly = true : isFly = false;
        //Содаем и заносим объекты
        vSObject.push_back(SObject(obj.getN(),obj.getVi(),obj.getGamma(),t,gipgip,isFly,x,y,z,obj.getSizeObjX(),obj.getSizeObjX(),obj.getSizeObjX(),obj.getVPoint()));
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
