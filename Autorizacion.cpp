#include <iostream>
#include <cstring>
#include "Autorizacion.h"
#include "OrdenMedicaArchivo.h"
#include "OrdenMedicaManager.h"
#include "AutorizacionArchivo.h"
using namespace std;

/////prueba de que se cambio algo

///////Cons

Autorizacion::Autorizacion(){

    idOrden = 0;
    codAutorizacion = 0;
    porcentajeCobertura = 0;

    aprobada = false;

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
    idOrden = id;
}



void Autorizacion::setCodAutorizacion(int cod){
    codAutorizacion = cod;
}


void Autorizacion::setFechaAutorizacion(Fecha fecha){
    fechaAutorizacion = fecha;
}

void Autorizacion::setPorcentajeCobertura(float porcentaje){
    porcentajeCobertura = porcentaje;
}

void Autorizacion::setAprobada(bool estado){
    aprobada = estado;
}

void Autorizacion::setObservaciones(const char* obs){
    strcpy(observaciones, obs);
}


/////metodos (cargar y mostrar)

void Autorizacion::Cargar(){

    cout << "INGRESE EL ID DE LA ORDEN: ";
    cin >> idOrden;
    cout << endl;

////validacion que exista el id de la orden

OrdenMedicaArchivo archOrden ;

while(archOrden.buscarId(idOrden)==-1){
 cout << "ID DE LA ORDEN INVALIDO, REINGRESE EL ID DE LA ORDEN: " << endl;
 cin >> idOrden;
}



AutorizacionArchivo archAuto;
codAutorizacion=archAuto.proximoCodigo();


    cout << "COD DE AUTORIZACION : " << codAutorizacion << endl;

int obraSocial;
    cout << "INGRESE LA OBRA SOCIAL (1 a 10): ";
    cin >> obraSocial;
while(obraSocial<1||obraSocial>10) {
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


    cout << "ESTA APROBADA? (1 si o 0 no ): ";
    cin >> aprobada;

    cin.ignore();

    cout << "Ingrese las observaciones (100 caract): ";
    cin.getline(observaciones, 100);

    cout << "Fecha de autorizacion:" << endl;
    fechaAutorizacion.CargarAut();
}

void Autorizacion::Mostrar(){

    cout << "ID DE LA ORDEN: " << idOrden << endl;
    cout << "EL CODIGO DE AUTORIZACION: " << codAutorizacion << endl;

    cout << "FECHA DE AUTORIZACION : ";
    fechaAutorizacion.Mostrar();

    cout << endl;

    cout << "PORCENTAJE DE COB: "
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









