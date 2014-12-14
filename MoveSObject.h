/*
 * Класс описывающий движение
 *
 *
 *
 */

#include "Point.h"
#include "SObject.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <sstream>
#ifndef MOVE_H_
#define MOVE_H_

class MoveSObject {

private:

    std::vector<SObject> vSObject;		//массив перемещений объекта

public:

    MoveSObject(SObject obj, RLS rls, bool snake);		//конструктор класса
    void move();
    std::vector<SObject> const getVSObject() const;
    //Для получения курса с заданным углом
    std::vector<double> getCourse(SObject obj, double degTheta,int snake);
    //Костыль который возвращает числа от xnach до endx; x не может быть меньше меньшего числа. (вернее может, но суть теряется)
    // Пример:
    // int x = -5;
    // for(int i = 0; i<20;++i){
    // x = getSnake(x,5,-5);
    // cout<<x<<endl;
    //}
    // Результат будет: -5,-4,-3,-2,-1,0,1,2,3,4,5,4,3,2,1,0,-1,-2,-3,-4,-5
    int getSnake(int x,int xnach, int endx);

};

#endif /* MOVE_H_ */
