#pragma once
#include <iostream>
#include "OrdenMedica.h"

#include <string>
#include <cstring>

using namespace std;

OrdenMedica::OrdenMedica(){
}

OrdenMedica::OrdenMedica(int idOrden, string dniPaciente, int matriculaMedico, Fecha fechaOrden, int tipoOrden, int origen, bool estado){
    _idOrden = idOrden;
    strcpy(_dniPaciente, dniPaciente.c_str());
    _matriculaMedico = matriculaMedico;
    _fechaOrden = fechaOrden;
    _tipoOrden = tipoOrden;
    _origen = origen;
    _estado = estado;
}

// GETTERS

int OrdenMedica::getIdOrden(){
    return _idOrden;
}

string OrdenMedica::getDniPaciente(){
    string dniAux = _dniPaciente;
    return dniAux;
}

int OrdenMedica::getMatriculaMedico(){
    return _matriculaMedico;
}

Fecha OrdenMedica::getFechaOrden(){
    return _fechaOrden;
}

int OrdenMedica::getTipoOrden(){
    return _tipoOrden;
}

int OrdenMedica::getOrigen(){
    return _origen;
}

bool OrdenMedica::getEstado(){
    return _estado;
}

// SETTERS

void OrdenMedica::setIdOrden(int idOrden){
  _idOrden = idOrden;
}

void OrdenMedica::setDniPaciente(std::string dniPaciente){
  strcpy(_dniPaciente, dniPaciente.c_str());
}

void OrdenMedica::setMatriculaMedico(int matriculaMedico){
    _matriculaMedico = matriculaMedico;
}

void OrdenMedica::setFechaOrden(Fecha fechaOrden){
    _fechaOrden = fechaOrden;
}

void OrdenMedica::setTipoOrden(int tipoOrden){
    _tipoOrden = tipoOrden;
}

void OrdenMedica::setOrigen(int origen){
    _origen = origen;
}

void OrdenMedica::setEstado(bool estado){
    _estado = estado;
}

void OrdenMedica::cargar(){
    string dni;

    cout << "DNI paciente: ";
    cin >> dni;

    strcpy(_dniPaciente, dni.c_str());

    cout << "Matricula Medico: ";
    cin >> _matriculaMedico;

    cout << "Tipo orden: ";
    cin >> _tipoOrden;

    cout << "Origen: ";
    cin >> _origen;

    _fechaOrden.Cargar();

    _estado = true;
}

void OrdenMedica::mostrar(){
    cout << "===================================" << endl;

    cout << "ID Orden: " << _idOrden << endl;

    cout << "DNI: " << _dniPaciente << endl;

    cout << "Matricula: " << _matriculaMedico << endl;

    cout << "Fecha: ";
    _fechaOrden.Mostrar();

    cout << endl;

    cout << "Tipo Orden: " << _tipoOrden << endl;

    cout << "Origen: " << _origen << endl;

    cout << "Estado: ";

    if(_estado){
        cout << "Activo" << endl;
    }
    else{
        cout << "No Activo" << endl;
    }
}
