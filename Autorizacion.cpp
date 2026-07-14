#include <iostream>
#include <cstring>
#include "Autorizacion.h"
#include "OrdenMedicaArchivo.h"
#include "OrdenMedicaManager.h"
#include "AutorizacionArchivo.h"
#include "ObraSocialArchivo.h"
using namespace std;

Autorizacion::Autorizacion(){

    idOrden = 0;
    codAutorizacion = 0;
    porcentajeCobertura = 0;

    aprobada = true;

    strcpy(observaciones, "");
}




///////Gets

int Autorizacion::getIdOrden(){
    return idOrden;
}

int Autorizacion::getCodAutorizacion(){
    return codAutorizacion;
}

Fecha Autorizacion::getFechaAutorizacion(){
    return fechaAutorizacion;
}

float Autorizacion::getPorcentajeCobertura(){
    return porcentajeCobertura;
}

bool Autorizacion::getAprobada(){
    return aprobada;
}

const char* Autorizacion::getObservaciones(){
    return observaciones;
}


/////sets


void Autorizacion::setIdOrden(int id){

OrdenMedicaArchivo archOrden ;

if(archOrden.buscarId(id)==-1||id<0){
idOrden=0;
}
else {
idOrden = id;
}
}



void Autorizacion::setCodAutorizacion(int cod){
if(cod>0){
    codAutorizacion = cod;
}
}

void Autorizacion::setFechaAutorizacion(Fecha fecha){
    fechaAutorizacion = fecha;
}

void Autorizacion::setPorcentajeCobertura(float porcentaje){
if(porcentaje>0&&porcentaje<=100){
    porcentajeCobertura = porcentaje;
    }
}

void Autorizacion::setAprobada(bool estado){
if(estado==0||estado==1){
    aprobada = estado;
    }
}

void Autorizacion::setObservaciones(const char* obs){
 if(strlen(obs)<100){
    strcpy(observaciones, obs);
    }
    else {
    strcpy(observaciones,"");
    }
}


/////metodos (cargar y mostrar)

void Autorizacion::Cargar(){
int orden;

    cout << "INGRESE EL ID DE LA ORDEN: ";
    cin >> orden;
    cout << endl;
setIdOrden(orden);
while(idOrden==0){
    cout << "NO SE PUDO CARGAR EL ID, INGRESE NUEVAMENTE: ";
    cin>> orden;
setIdOrden(orden);
}

AutorizacionArchivo archAuto;
codAutorizacion=archAuto.proximoCodigo();


// cout << "COD DE AUTORIZACION : " << codAutorizacion << endl;

ObraSocialArchivo obr;
int obraSocial;
    cout << "INGRESE LA OBRA SOCIAL (1 a 10): ";
    cin >> obraSocial;

while(obraSocial<1||obraSocial>10||obr.obraSocialActiva(obraSocial)==false) {
    cout << "RE INGRESE LA OBRA SOCIAL POR FAVOR: ";
    cin >>obraSocial;
}
switch(obraSocial){
case 1:
    porcentajeCobertura=10;
    break;
case 2 : porcentajeCobertura=20;
    break;
case 3 : porcentajeCobertura=30;
    break;
case 4: porcentajeCobertura=40;
    break;
case 5: porcentajeCobertura=50;
    break;
case 6: porcentajeCobertura=60;
    break;
case 7: porcentajeCobertura=70;
    break;
case 8:  porcentajeCobertura=80;
    break;
case 9: porcentajeCobertura=90;
    break;
case 10: porcentajeCobertura=100;
break;
default :
    cout << endl << "ERROR" << endl;
                system("pause");
    break;


}

//// no hace falta mostrar cout << "PORCENTAJE DE COBERTURA: " << porcentajeCobertura << " %" << endl;
bool aprob;

    cout << "ESTA APROBADA? (1 si o 0 no ): ";
    cin >> aprob;
    while(aprob!=1||aprob!=0){
    cout << endl;
    cout << "INGRESE 1 SI ESTA APROBADA O 0 SI NO LO ESTA : ";
    cin >> aprob;
    }
    setAprobada(aprob);

    char obs[100];
    cout << "INGRESE LAS OBSERVACIONES: ";
    cin >> obs;
    while (strlen(obs) > 99) {
        cout << "INGRESE NUEVAMENTE LAS OBSERVACIONES (HASTA 100 CARACTERES)";
        cin >> obs;
    }
    setObservaciones(obs);

    cout << "Fecha de autorizacion:" << endl;
    fechaAutorizacion.CargarAut();
}

void Autorizacion::Mostrar(){

    cout << "ID DE LA ORDEN: " << idOrden << endl;
    cout << "EL CODIGO DE AUTORIZACION: " << codAutorizacion << endl;

    cout << "FECHA DE AUTORIZACION : ";
    fechaAutorizacion.Mostrar();

    cout << endl;

    cout << "PORCENTAJE DE COBERTURA: "
         << porcentajeCobertura << "%" << endl;

    cout << "ESTADO DE APROBACION: ";

    if(aprobada){
        cout << "SI";
    }
    else{
        cout << "NO";
    }

    cout << endl;

    cout << "OBSERVACIONES: " << observaciones << endl;
    cout << "-------------------------------------------" << endl;
}









