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


bool isRec = false; //Это нужно для змеевидной траектории =)

MoveSObject::MoveSObject(SObject obj, RLS rls, bool snake) {

    vSObject.push_back(obj); //получили один готовый объект(тело) сразу поместили его в массив перемещений
//скорее всего в комментариях сказано не совсем то, что происходит на самом деле. например "вектор тела" может быть не вектором тела

    //вектор тела
    double vecObjX = obj.getObjX();
    double vecObjY = obj.getObjY();

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

    //Если Snake == false Выбираем обычное направление
    if (!snake) {
        if (obj.getObjX() < 0 && obj.getObjY() > 0) {
            Vx = obj.getVi() * cos(obj.getGamma() * (M_PI / 180) + degTheta * (M_PI / 180));
            Vy = obj.getVi() * sin(obj.getGamma() * (M_PI / 180) + degTheta * (M_PI / 180)) * (-1);
            Vz = 0;
        } else if (obj.getObjX() > 0 && obj.getObjY() > 0 && degTheta > 90) {
            degTheta = degTheta - 90;
            Vx = obj.getVi() * sin(obj.getGamma() * (M_PI / 180) + degTheta * (M_PI / 180)) * (-1);
            Vy = obj.getVi() * cos(obj.getGamma() * (M_PI / 180) + degTheta * (M_PI / 180)) * (-1);
            Vz = 0;
        } else {
            Vx = obj.getVi() * cos(obj.getGamma() * (M_PI / 180) + degTheta * (M_PI / 180));
            Vy = obj.getVi() * sin(obj.getGamma() * (M_PI / 180) + degTheta * (M_PI / 180));
            Vz = 0;
        }
    }
    int tend = 1000;
    int s = -50;
    //Предепреждение о движении
    if(snake)
        std::cout<<"Движение змейкой"<<std::endl;

    for (int t = 30; t < tend; t+=30) {
        //Змеевидное движение
        if (snake) {
            std::vector<double> cors = getCourse(obj, degTheta, s);
            s = getSnake(s, 50, -50);
            Vx = cors[0];
            Vy = cors[1];
            Vz = cors[2];
        }
        //находим расстояние на которое необходимо передвинуть объект
        double x = Vx * t;
        double y = Vy * t;
        double z = Vz * t;
        //строим новый треугольник учитывая новые координаты, чтобы найти гипотенузу.
        vecRlsX = rls.getXrls() - (x + vSObject[t/30-1].getObjX());
        vecRlsY = rls.getYrls() - (y + vSObject[t/30-1].getObjY());

        bool isFly = false;
        gipgip = sqrt(vecRlsX*vecRlsX+vecRlsY*vecRlsY);

        //если цель пролетела РЛС в файле это укажется благодаря ниженаписанной строко
        (vSObject[t/30-1].getR() < gipgip) ? isFly = true : isFly = false;

        //передаем в конструктор: старый объект, новое время,
        //новое расстояние до РЛС, пролетел ли объект и на сколько нужно подвинуть новый
        //получаем новый объект, с новыми данными и заносим его в массив передвижений
        vSObject.push_back(SObject(vSObject[t/30-1],t,gipgip,isFly,x,y,z));
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
std::vector<double> MoveSObject::getCourse(SObject obj, double degTheta,int snake){
    double Vx,Vy,Vz;
    std::vector<double> vecNapravl;
    if(obj.getObjX() < 0 && obj.getObjY() > 0){
        Vx = obj.getVi()*cos((obj.getGamma()+snake) * (M_PI /180) + degTheta * (M_PI /180));
        Vy = obj.getVi()*sin((obj.getGamma()+snake) * (M_PI /180) + degTheta * (M_PI /180)) * (-1);
        Vz = 0;
    } else if (obj.getObjX() > 0 && obj.getObjY() > 0 && degTheta > 90){
        degTheta = degTheta - 90;
        Vx = obj.getVi()*sin((obj.getGamma()+snake)* (M_PI /180) + degTheta * (M_PI /180)) * (-1);
        Vy = obj.getVi()*cos((obj.getGamma()+snake)* (M_PI /180) + degTheta * (M_PI /180)) * (-1);
        Vz = 0;
    } else {
        Vx = obj.getVi()*cos((obj.getGamma()+snake)* (M_PI /180) + degTheta * (M_PI /180));
        Vy = obj.getVi()*sin((obj.getGamma()+snake)* (M_PI /180) + degTheta * (M_PI /180));
        Vz = 0;
    }
    vecNapravl.push_back(Vx);
    vecNapravl.push_back(Vy);
    vecNapravl.push_back(Vz);
    return vecNapravl;
}
//Костыль
int MoveSObject::getSnake(int x,int xnach, int endx){
    if(x<xnach && !isRec){
//        ++x;
        x=x+10;
        if(x == xnach)
            isRec = true;

    }else if (x>endx && isRec){
//        --x;
        x-=10;
        if (x == endx)
            isRec = false;
    }
    return x;
}

















