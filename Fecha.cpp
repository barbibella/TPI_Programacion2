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
    cout << "--- INGRESE FECHA DE NACIMIENTO ---" << endl;
    int d, m, a;

    int maxDia = 31;
    if(m == 4 || m == 6 || m == 9 || m == 11){
        maxDia = 30;
    }else if(m == 2){
        if((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
            maxDia = 29;
        }else{
            maxDia = 28;
        }
    }
    cout << "DIA (1 - " << maxDia << "): ";
    cin >> d;
    while(d < 1 || d > maxDia){
        cout << "Error: Dia invalido para el mes seleccionado. Ingrese nuevamente: ";
        cin >> d;
    }
    cout << "MES (1 - 12): ";
    cin >> m;
    while(m < 1 || m > 12){
        cout << "Error: El mes debe estar entre 1 y 12. Ingrese nuevamente: ";
        cin >> m;
    }
    cout << "ANIO (1900 - 2026): ";
    cin >> a;
    while(a < 1900 || a > 2026){
        cout << "Error: Anio invalido para nacimiento. Ingrese nuevamente: ";
        cin >> a;
    }
    setDia(d);
    setMes(m);
    setAnio(a);
}
/*void Fecha::Cargar(){
    cout<<"--- INGRESE FECHA DE NACIMIENTO ---" <<endl;
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
}*/

void Fecha::CargarFechaOrden(){
    cout<<"Ingrese la fecha de la orden medica:" <<endl;
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


void Fecha::CargarAut(){
    cout<<"INGRESE : "<< endl;
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
        cout << "Fecha:" << endl;
        cout << dia << "/" << mes << "/" << anio << endl;
}

Fecha::Fecha(int d,int m, int a){
    dia=d;
    mes=m;
    anio=a;
}
void Fecha::setDia(int d){
        if(d>=1 && d<=31) {
            dia=d;
        }
        else{
            dia=0;
        }
    }
void Fecha::setMes(int m){
        if(m>0 && m<=12){
                mes=m;
        }
        else{
            m=0;
        }
    }
void Fecha::setAnio(int a){
        if(a >= 1900 && a <= 2026){
                anio=a;
        }
    }
int Fecha::getDia(){
    return dia;}
int Fecha::getMes(){
    return mes;}
int Fecha::getAnio(){
    return anio;}
