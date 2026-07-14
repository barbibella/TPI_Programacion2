#include <iostream>
#include "Especialidad.h"

using namespace std;

//MAI
//CONSTRUCTOR - MAI
Especialidad::Especialidad()
: _idEspecialidad(-1), _idFormacion(-1), _nombreEspecialidad(""), _descripcionEspecialidad(""), _estado(2){}

Especialidad::Especialidad(int idEspecialidad, int idFormacion, string nombreEspecialidad, string descripcionEspecialidad, int estado)
{
	setIdEspecialidad(idEspecialidad);
	setNombreEspecialidad(nombreEspecialidad);
	setDescripcionEspecialidad(descripcionEspecialidad);
	setIdFormacion(idFormacion);
	setEstado(estado);
}


//SETTERS - MAI
void Especialidad::setIdEspecialidad(int idEspecialidad){
    _idEspecialidad = idEspecialidad;
}

void Especialidad::setNombreEspecialidad(string nombreEspecialidad){

    if(nombreEspecialidad.size() < 30){
        strcpy(_nombreEspecialidad, nombreEspecialidad.c_str());
    }
    else {
        strcpy(_nombreEspecialidad, "Nombre de especialidad fuera de rango.");
    };
}

void Especialidad::setDescripcionEspecialidad(string descripcionEspecialidad){
    if(descripcionEspecialidad.size() < 300){
        strcpy(_nombreEspecialidad, descripcionEspecialidad.c_str());
    }
    else {
        strcpy(_descripcionEspecialidad, "Descripcion de especialidad fuera de rango.");
    };
}

void Especialidad::setIdFormacion(int idFormacion){
    _idFormacion = idFormacion;
}

void Especialidad::setEstado(int estado){
    _estado = estado;
}

//GETTERS - MAI
int Especialidad::getIdEspecialidad() const{return _idEspecialidad;}
string Especialidad::getNombreEspecialidad() const {return _nombreEspecialidad;}
string Especialidad::getDescripcionEspecialidad() const {return _descripcionEspecialidad;}
string Especialidad::getFormacion() const{
string formacion[3] = { "", "Residencia", "Concurrencia"};
    return formacion[_idFormacion-1];
     }
string Especialidad::getEstado() const{
    string estado[2] = { "Activo", "Inactivo"};
    return estado[_estado-1];
     }
