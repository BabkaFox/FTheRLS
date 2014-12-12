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

    //вектор рлс
    double vecRlsX = rls.getXrls() - vecObjX;
    double vecRlsY = rls.getYrls() - vecObjY;
//    double vecRlsZ = rls.getZrls() - vecObjZ;

    //нормаль вектора объкта
    double vecObjXNorm = vecObjX/sqrt(vecObjX*vecObjX+vecObjY*vecObjY);
    double vecObjYNorm = vecObjY/sqrt(vecObjX*vecObjX+vecObjY*vecObjY);
//    double vecObjXNorm = vecObjX/sqrt(vecObjX*vecObjX+vecObjY*vecObjY+vecObjZ*vecObjZ);
//    double vecObjYNorm = vecObjY/sqrt(vecObjX*vecObjX+vecObjY*vecObjY+vecObjZ*vecObjZ);
//    double vecObjZNorm = vecObjZ/sqrt(vecObjX*vecObjX+vecObjY*vecObjY+vecObjZ*vecObjZ);

    //нормаль вектора РЛС
    double vecRlsXNorm = vecRlsX/sqrt(vecRlsX*vecRlsX+vecRlsY*vecRlsY);
    double vecRlsYNorm = vecRlsY/sqrt(vecRlsX*vecRlsX+vecRlsY*vecRlsY);
//    double vecRlsXNorm = vecRlsX/sqrt(vecRlsX*vecRlsX+vecRlsY*vecRlsY+vecRlsZ*vecRlsZ);
//    double vecRlsYNorm = vecRlsY/sqrt(vecRlsX*vecRlsX+vecRlsY*vecRlsY+vecRlsZ*vecRlsZ);
//    double vecRlsZNorm = vecRlsZ/sqrt(vecRlsX*vecRlsX+vecRlsY*vecRlsY+vecRlsZ*vecRlsZ);

    //Расчитываем угол направления движения к РЛС
    double theta = acos(vecObjXNorm*vecRlsXNorm+vecObjYNorm*vecRlsYNorm);
//    double theta = acos(vecObjXNorm*vecRlsXNorm+vecObjYNorm*vecRlsYNorm+vecObjZNorm*vecRlsZNorm);

    //переводим в градусы
    double degTheta = theta*180/M_PI;
    std::cout<<degTheta;
    //начинаем двигать цель
    double  Vx=0,Vy=0,Vz=0;


    Vx = obj.getVi()*cos(obj.getGamma()+degTheta);   //курс
    Vy = obj.getVi()*sin(obj.getGamma()+degTheta);
    Vz = 0;
    int tend = 1000;
    for (int t = 30; t < tend; t+=30) {

        double x = (Vx*t+vSObject[t/30-1].getObjX());
        double y = (Vy*t+vSObject[t/30-1].getObjY());
        double z = (Vz*t+vSObject[t/30-1].getObjZ());
//        std::cout<<"X: "<<x<<" Y: "<<y<<" Z: "<<z<<std::endl;
        //Содаем и заносим объекты
        vSObject.push_back(SObject(obj.getN(),obj.getVi(),obj.getGamma(),t,x,y,z,obj.getSizeObjX(),obj.getSizeObjX(),obj.getSizeObjX(),obj.getVPoint()));
//        std::cout<<"X: "<<vSObject[t/30-1].getObjX()<<" Y: "<<vSObject[t/30-1].getObjY()<<" Z: "<<vSObject[t/30-1].getObjZ()<<std::endl;

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
