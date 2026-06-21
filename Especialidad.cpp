#include <iostream>
#include "Especialidad.h"

using namespace std;

//MAI
//CONSTRUCTOR - MAI
Especialidad::Especialidad()
: _IdEspecialidad(-1), Medico(){}

Especialidad::Especialidad(int IdEspecialidad){
	setEspecialidad(IdEspecialidad);
}

//SETTERS - MAI
void Especialidad::setIdEspecialidad()

//GETTERS - MAI
int Especialidad::getEspecialidad() const{return _IdEspecialidad;}

/*
IdEspecialidad
NombreEspecialidad
DescripcionEspecialidad
TipoFormacionEsp : 1 - Residencia; 2 - Concurrencia
*/
