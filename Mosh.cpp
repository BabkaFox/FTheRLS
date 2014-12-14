/*
 * Point.cpp
 *
 *  Created on: 06.12.2014
 *      Author: �������
 */

#include "Mosh.h"
# define M_PI 3.14159265358979323846  /* pi */
using namespace std;

//конструктор
Mosh::Mosh(std::vector<SObject> obj){
    this->obj = obj; //Массив перемещений
}

void Mosh::moshnost(){
    double P = 0, iprOL = 0, lyam = 0.03;
    short int Pper=1, Dper=1, Fpr=1, Fper=1, Dpr=1;

    for (int j = 0; j < obj.size(); ++j) {
        double sumUx = 0, sumUy = 0;
        double R = obj[j].getR();
        for (int i = 0; i < obj[j].getVPoint().size(); ++i) {
            Ppr.push_back(0);
//            Ux.push_back(0);
//            Uy.push_back(0);
            double tempR =(obj[j].getVPoint()[i].getXi()*obj[j].getVPoint()[i].getXi())+(obj[j].getVPoint()[i].getYi()*obj[j].getVPoint()[i].getYi())+(obj[j].getVPoint()[i].getZi()*obj[j].getVPoint()[i].getZi());
            R=sqrt(tempR);
            double sigma = obj[j].getVPoint()[i].getSigma();
            Ppr[i] = (Pper*Dper*Dpr*Fpr*Fper*sigma*lyam*lyam)/(pow(4.0*M_PI, 3.0)*(pow(R, 4.0)));
//            Ux[i] = (double) (sqrt(Ppr[i])*sin(2*M_PI*R/lyam));
//            Uy[i] = (double) (sqrt(Ppr[i])*cos(2*M_PI*R/lyam));
            sumUx += sqrt(Ppr[i])*sin(2*M_PI*R/lyam);
            sumUy += sqrt(Ppr[i])*cos(2*M_PI*R/lyam);

        }

        P = sumUx*sumUx + sumUy*sumUy;
        this->P.push_back(P);

        iprOL = P*(pow(4.0*M_PI, 3.0)*(pow(R, 4.0))) /(Pper*Dper*Dpr*Fpr*Fper*lyam*lyam);
        this->iprOL.push_back(iprOL);

    }


}
//метод для записи в файл
void Mosh::writeResult(){

    ofstream fout("k.txt", ios_base::trunc);
    fout.width(2);    fout<<"N"<<" ";
    fout.width(7);    fout<<"t"<<" ";
    fout.width(10);   fout<<"x"<<"  ";
    fout.width(10);   fout<<"y"<<"  ";
    fout.width(10);   fout<<"z"<<"  ";
    fout.width(10);   fout<<" R"<< "  ";
    fout.width(10);   fout<<" sigma "<< "  ";
    fout.width(10);   fout<<" Ppr "<< "  "<<endl;       //добавил вот это

    for (int j = 0; j < obj.size(); ++j) {
        for (int i = 0; i < obj[j].getVPoint().size(); ++i) {

            fout.width(2);  fout<<fixed;fout << obj[j].getVPoint()[i].getNumber() << " ";
            fout.width(7);  fout<<obj[j].getVPoint()[i].getT()<< " ";
            fout.width(10); fout<<obj[j].getVPoint()[i].getXi()<<std::setprecision(2)<<"  ";
            fout.width(10); fout<<obj[j].getVPoint()[i].getYi()<<std::setprecision(2)<<"  ";
            fout.width(10); fout<<obj[j].getVPoint()[i].getZi()<<std::setprecision(2)<<"  ";
            fout.width(10); fout<<obj[j].getVPoint()[i].getRi()<<std::setprecision(8)<<"  ";
            fout.width(8);  fout<<obj[j].getVPoint()[i].getSigma()<<std::setprecision(30) <<"  ";  //тут setprecision(30) <-- кол-во знаков для PPr
            fout.width(8);  fout<<Ppr[i]<<std::setprecision(2) <<"  ";              //печатаем PPr
            fout<< endl;
        }
    }

//    fout<<std::setprecision(15);fout << "P = "<<P;fout<<std::setprecision(2);fout<<"  iprOL = "<< iprOL << endl;
    fout.close();
}
void Mosh::writeResult2(){

    ofstream fout("k.txt", ios_base::trunc);
    fout.width(6);    fout<<"t"<<"  ";
    fout.width(10);   fout<<"x"<<"  ";
    fout.width(10);   fout<<"y"<<"  ";
    fout.width(10);   fout<<"z"<<"  ";
    fout.width(10);   fout<<"R"<<"  ";
    fout.width(17);   fout<<"P"<<"  "<<endl;

    bool isWrote = false;
    for (int j = 0; j < obj.size(); ++j) {
        if (obj[j].getFly() && !isWrote) {isWrote = true; fout.width(75); fout<<"Наш поворот! ...был. Мы пролетели мимо!"<<endl;}
            fout.width(2);  fout<<fixed<<setprecision(2)<<"  ";
            fout.width(7);  fout<<obj[j].getT()<<std::setprecision(2)<<"  ";
            fout.width(10); fout<<obj[j].getObjX()<<std::setprecision(2)<<"  ";
            fout.width(10); fout<<obj[j].getObjY()<<std::setprecision(2)<<"  ";
            fout.width(10); fout<<obj[j].getObjZ()<<std::setprecision(2)<<"  ";
            fout.width(10); fout<<obj[j].getR()<<std::setprecision(30)<<"  ";
            fout.width(10); fout<<P[j]<<std::setprecision(2)<<"  ";
            fout<<endl;
    }
    fout.close();
}

//Тесты графика
void Mosh::writeResultTest(){
    ofstream fout("k.txt", ios_base::trunc);
    fout.width(4);   fout<<"x"<<"  ";
    fout.width(4);   fout<<"y"<<"  "<<endl;
    bool isWrote = false;
    for (int j = 0; j < obj.size(); ++j) {
        if (obj[j].getFly() && !isWrote) {isWrote = true; fout.width(75); fout<<"Наш поворот! ...был. Мы пролетели мимо!"<<endl;}
        fout.width(2);  fout<<fixed<<setprecision(2)<<"  ";
        fout.width(4); fout<<obj[j].getObjX()<<std::setprecision(2)<<";";
        fout.width(4); fout<<obj[j].getObjY()<<std::setprecision(2)<<" ";
        fout<<endl;
    }
    fout.close();
}