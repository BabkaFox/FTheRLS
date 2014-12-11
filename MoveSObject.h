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

    std::vector<SObject> vSObject;		//массив Точек

public:

    MoveSObject(SObject &obj1);		//конструктор класса
    void move();


//    std::vector<SObject> const getVSObject();

    std::vector<SObject> const getVSObject() const;
};

#endif /* MOVE_H_ */
