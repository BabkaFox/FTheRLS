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

    //гипотенуза
    double gipgip = sqrt(vecRlsX*vecRlsX+vecRlsY*vecRlsY);

    //находим угол в градусах
    double degTheta = acos(vecRlsX/gipgip)*180/M_PI;

//начинаем двигать цель
    double  Vx=0,Vy=0,Vz=0;


//    Vx = obj.getVi()*cos(obj.getGamma()+degTheta);   //курс
//    Vy = obj.getVi()*sin(obj.getGamma()+degTheta);
    Vz = 0;

    Vx = obj.getVi()*cos(degTheta * (M_PI /180));
    Vy = obj.getVi()*sin(degTheta * (M_PI /180));

    std::cout<<Vx<<" "<<Vy<<" "<<Vz<<std::endl;
    int tend = 1000;
    for (int t = 30; t < tend; t+=30) {

//        double x = (Vx*t+vSObject[t/30-1].getObjX());
//        double y = (Vy*t+vSObject[t/30-1].getObjY());
        double x = Vx * t + vSObject[t/30-1].getObjX();
        double y = Vy * t + vSObject[t/30-1].getObjY();

        double z = (Vz*t+vSObject[t/30-1].getObjZ());
//        std::cout<<"X: "<<x<<" Y: "<<y<<" Z: "<<z<<std::endl;
        //Содаем и заносим объекты
        vSObject.push_back(SObject(obj.getN(),obj.getVi(),obj.getGamma(),t,x,y,z,obj.getSizeObjX(),obj.getSizeObjX(),obj.getSizeObjX(),obj.getVPoint()));
        std::cout<<"X: "<<vSObject[t/30-1].getObjX()<<" Y: "<<vSObject[t/30-1].getObjY()<<" Z: "<<vSObject[t/30-1].getObjZ()<<std::endl;

//        std::cout<<vX;

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
