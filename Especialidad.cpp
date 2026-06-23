#include <iostream>
#include "Especialidad.h"

using namespace std;

//MAI
//CONSTRUCTOR - MAI
Especialidad::Especialidad()
: _idEspecialidad(-1), _idFormacion(-1), _nombreEspecialidad(""), _descripcionEspecialidad(""){}

Especialidad::Especialidad(int idEspecialidad, int idFormacion, string nombreEspecialidad, string descripcionEspecialidad)
{
	setIdEspecialidad(idEspecialidad);
	setNombreEspecialidad(nombreEspecialidad);
	setDescripcionEspecialidad(descripcionEspecialidad);
	setIdFormacion(idFormacion);
}


//SETTERS - MAI
void Especialidad::setIdEspecialidad(int idEspecialidad){
    _idEspecialidad = idEspecialidad;
}

void Especialidad::setNombreEspecialidad(string nombreEspecialidad){

    if(nombreEspecialidad.size() < 25){
        strcpy(_nombreEspecialidad, nombreEspecialidad.c_str());
    }
    else {
        strcpy(_nombreEspecialidad, "Nombre de especialidad fuera de rango.");
    };
}

void Especialidad::setDescripcionEspecialidad(string descripcionEspecialidad){
    if(descripcionEspecialidad.size() < 50){
        strcpy(_nombreEspecialidad, descripcionEspecialidad.c_str());
    }
    else {
        strcpy(_descripcionEspecialidad, "Descripcion de especialidad fuera de rango.");
    };
}

void Especialidad::setIdFormacion(int idFormacion){
    _idFormacion = idFormacion;
}

//GETTERS - MAI
int Especialidad::getEspecialidad() const{return _idEspecialidad;}
string Especialidad::getNombreEspecialidad() const {return _nombreEspecialidad;}
string Especialidad::getDescripcionEspecialidad() const {return _descripcionEspecialidad;}
string Especialidad::getFormacion() const{
    string formacion[3] = { "", "Residencia", "Concurrencia"};
    return formacion[_idFormacion-1];
     }
