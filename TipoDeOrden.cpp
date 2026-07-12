#pragma once
#include <iostream>
#include "TipoDeOrden.h"

#include <string>
#include <cstring>

using namespace std;

TipoDeOrden::TipoDeOrden(){
}

TipoDeOrden::TipoDeOrden(int idTipoOrden, std::string descripcion, bool estado){
    _idTipoOrden = idTipoOrden;
    strcpy(_descripcion, descripcion.c_str());
    _estado = estado;
}

int TipoDeOrden::getIdTipoOrden(){
    return _idTipoOrden;
}

string TipoDeOrden::getDescripcion(){
    string descripcionAux = _descripcion;
    return descripcionAux;
}

bool TipoDeOrden::getEstado(){
    return _estado;
}

void TipoDeOrden::setIdTipoOrden(int idTipoOrden){
    _idTipoOrden = idTipoOrden;
}

void TipoDeOrden::setDescripcion(std::string descripcion){
    strcpy(_descripcion, descripcion.c_str());
}

void TipoDeOrden::setEstado(bool estado){
    _estado = estado;
}

void TipoDeOrden::cargar(){

    cout << "Descripcion del tipo de orden: ";
    cin.ignore();
    cin.getline(_descripcion, 40);

    _estado = true;
}

void TipoDeOrden::mostrar(){
    cout << "===================================" << endl;

    cout << "ID tipo de orden: " << _idTipoOrden << endl;

    cout << "Descripcion: " << _descripcion << endl;

    cout << "Estado: ";

    if(_estado){
        cout << "Activo" << endl;
    }
    else{
        cout << "No Activo" << endl;
    }
}
