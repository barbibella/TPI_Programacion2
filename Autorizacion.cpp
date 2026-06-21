#include <iostream>
#include <cstring>
#include "Autorizacion.h"
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

    cout << "INGRESE EL COD DE AUTORIZACIÓN";
    cin >> codAutorizacion;

    cout << "INGRESE EL PORCENTAJE DE COBER";
    cin >> porcentajeCobertura;

    cout << "ESTA APROBADA? (1 si o 0 no ): ";
    cin >> aprobada;

    cin.ignore();

    cout << "Ingrese las observaciones (100 caract): ";
    cin.getline(observaciones, 100);

    cout << "Fecha de autorizacion:" << endl;
    fechaAutorizacion.Cargar();
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
}










