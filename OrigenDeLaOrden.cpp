#pragma once
#include <iostream>
#include "OrigenDeLaOrden.h"

#include <string>
#include <cstring>

using namespace std;

OrigenDeLaOrden::OrigenDeLaOrden(){
}

OrigenDeLaOrden::OrigenDeLaOrden(int idOrigen, std::string descripcion, bool estado){
    _idOrigen = idOrigen;
    strcpy(_descripcion, descripcion.c_str());
    _estado = estado;
}

int OrigenDeLaOrden::getIdOrigen(){
    return _idOrigen;
}

string OrigenDeLaOrden::getDescripcion(){
    string descripcionAux = _descripcion;
    return descripcionAux;
}

bool OrigenDeLaOrden::getEstado(){
    return _estado;
}

void OrigenDeLaOrden::setIdOrigen(int idOrigen){
    _idOrigen = idOrigen;
}

void OrigenDeLaOrden::setDescripcion(std::string descripcion){
    strcpy(_descripcion, descripcion.c_str());
}

void OrigenDeLaOrden::setEstado(bool estado){
    _estado = estado;
}

void OrigenDeLaOrden::cargar(){
    string descripcion;

    cout << "Descripcion del origen de la orden: ";
    cin >> descripcion;

    strcpy(_descripcion, descripcion.c_str());

    _estado = true;
}

void OrigenDeLaOrden::mostrar(){
    cout << "===================================" << endl;

    cout << "ID tipo de orden: " << _idOrigen << endl;

    cout << "Descripcion: " << _descripcion << endl;

    cout << "Estado: ";

    if(_estado){
        cout << "Activo" << endl;
    }
    else{
        cout << "No Activo" << endl;
    }
}
