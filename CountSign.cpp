/*
 * MOVE.cpp
 *
 *  Created on: 06.12.2014
 *      Author: Евгения
 */

//#include "CountSign.h"
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <sstream>
//using namespace std;
//
//
//	float CountS::getSigma(){
//		return this->sigma1;
//	}
//
//	int PointMove::get_N(){
//		return N;
//	}
//
//	float RLS::getlyam(){
//		return this->lyam;
//	}
//
//	void CountS::nill_massive(){
//
//			for(int j=0;j<10000;j++){
//                Ux[j] = 0;
//    			Uy[j] = 0;
//    		    Ppr[j] = 0;
////				Rmassive[j]=0;
//			}
//	}
//	//Считаем Мощность
//
//	void CountS::Mosh(){
//		double   P, lyam;
//		short int Pper=1, Dper=1, Fpr=1, Fper=1, Dpr=1;
//        int count,numb, N;
//        double* Rmassive[numb] = new double[N+1];
//
//        for (int numb = 0; numb <= N; ++numb)
//        {
//
////    	   Rmassive[numb] = sqrt(pow((xmassive[index][numb] - Xrls),2.0) + pow((ymassive[index][numb] - Yrls),2.0) + pow((zmassive[index][numb] - Zrls),2.0));
//    	   Ppr[numb] =  (Pper*Dper*Dpr*Fpr*Fper*sigma1*lyam*lyam)/(pow(4.0*M_PI, 3.0)*(pow(Rmassive[numb], 4.0)));
//           Ux[numb] = sqrt(Ppr[numb])*sin(2*M_PI*Rmassive[numb]/lyam);
//           Uy[numb] = sqrt(Ppr[numb])*cos(2*M_PI*Rmassive[numb]/lyam);
//
//        }
//
//        ofstream fout("k.txt", ios_base::trunc);
//             	fout.width(2);
//             	fout<< "N"<<" ";
//             	fout.width(5);
//             	fout<<"t"<<" ";
//             	fout.width(10);
//             	fout<< "x"<<"  ";
//             	fout.width(10);
//             	fout<<"y"<<"  ";
//             	fout.width(5);
//             	fout<<"z"<<"  ";
//             	fout.width(5);
//             	fout<<" R"<< "  ";
////         	    fout.width(10);
////         	    fout<<" sumUx"<< "  ";
////         	    fout.width(10);
////         	    fout<<" sumUy"<< "  ";
//             	fout.width(10);
//             	fout<<"sigma"<< "  "<<endl;
//
//                 double* sumUx = new double[N+1];
//                 double* sumUy = new double[N+1];
//                 double* xmassive = new double[N+1];
//                 double* ymassive = new double[N+1];
//                 double* zmassive = new double[N+1];
//                 count = this->count;
//             	 sigma1 = this->sigma1;
//
//             	 for (int j=0;j<N;j++){
//             		 sumUx[j]=0;
//             		 sumUy[j]=0;
//             	 for (int t = 0; t < 1000; t+=30){
//             		 int i=t/30;
//             		 sumUx[j] += this->Ux[i][j];
//             		 sumUy[j] += this->Uy[i][j];
//             		 fout.width(2);
//             		fout << fixed;
//             		fout<< j<<" ";
//             		 fout.width(5);
//             	    fout<<t<<" ";
//             	    fout.width(10);
//             	    fout<<xmassive[i][j]<<"  ";
//             	    fout.width(10);
//             	    fout<<ymassive[i][j]<<std::setprecision(2)<<"  ";
//             	    fout.width(5);
//             	    fout<<zmassive[i][j]<<std::setprecision(2)<<"  ";
//             	    fout.width(5);
//             	    fout<<Rmassive[i][j]<<std::setprecision(2)<<"  ";
//             	    fout.width(10);
////             	    fout<<sumUx[j];
////             	    fout.width(12);
////             	    fout<<sumUy[j];
////             	    fout.width(10);
//             	    fout<< sigma1<< "  ";
//             	   fout<<endl;
//             	 }
//             	P = sumUx[j]*sumUx[j] + sumUy[j]*sumUy[j];
//             	             	 this->sumUx = sumUx[j];
//             	             	 this->sumUy = sumUy[j];
//             	             	 this->P = P;
////             	             	 this->N = count;
//             	             	iprOL[j] = Ppr[j]*(pow(4.0*M_PI, 3.0)*(pow(Rmassive[j], 4.0))) /(Pper*Dper*Dpr*Fpr*Fper*lyam*lyam);
//             	             	this->iprOL = iprOL;
//
////             	             	ipr1OL = count*sigma;
//
//             	 fout<<"  Pr = "<<this->P<<"  "<<"  iprOL = "<<this->iprOL<<endl;
//             	 }
//             	 fout.close();
//
//
////              	 cout<<"sumUx: "<<sumUx<<"sumUy: "<<sumUy<<"Pr: "<<Pr<<endl;
//             	     }
//
//

