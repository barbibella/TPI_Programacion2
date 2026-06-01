#include <iostream>
#include "Fecha.h"
using namespace std;


bool Fecha::validarFecha(int d, int m, int a){

    if ((a<ANIOACTUAL || a>ANIOFIN) || (m<1 || m>12) || (d<1 || d>31)){
        return false;
    }

    if(m==4 || m==6 || m==9 || m==11){
        if(d<1 || d>30){
            return false;
        }
    }

    if(m==2){
        if(d<1 || d>28){
            return false;
        }
    }

    return true;
}

void Fecha::Cargar(){
    cout<<"INGRESE FECHA DE NACIMIENTO:" <<endl;
    int d, m, a;
    cout<<"DIA ";
    cin>>d;
    cout<<"MES ";
    cin>>m;
    cout<<"ANIO ";
    cin>>a;

    while(!validarFecha(d, m, a)){
        cout<<"Fecha ingresada invalida, por favor ingrese nuevamente la fecha: "<<endl;
        cout<<"DIA ";
        cin>>d;
        cout<<"MES ";
        cin>>m;
        cout<<"ANIO ";
        cin>>a;
   }

    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::Mostrar(){
    cout << endl;
        cout << "Usted ingreso:" << endl;
        cout << dia << "/" << mes << "/" << anio << endl;
}

Fecha::Fecha(int d,int m, int a){
    dia=d;
    mes=m;
    anio=a;
}

