#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;
// ===MAI===============================================================
Persona::Persona()
: _nombre(""),_apellido(""), _dni(""), _telefono(""), _estado(){}

//CONSTRUCTOR - Mai
Persona::Persona(string nombre, string apellido, string dni, string telefono, bool estado){
    setNombre(nombre);
    setApellido (apellido);
    setDni (dni);
    setTelefono (telefono);
    setEstado (estado);

    }

//SETTERS - Mai
void Persona::setNombre(string nombre){
    if (nombre.size()<30){
        strcpy(_nombre, nombre.c_str());
    }
    else { strcpy(_nombre, "nombre fuera de rango");
    }
}

void Persona::setApellido(string apellido){
    if(apellido.size()<30){
            strcpy(_apellido, apellido.c_str());
    }
    else{ strcpy(_apellido, "apellido fuera de rango");
    }
}

void Persona::setDni(string dni){
    if (dni.size()<15){
        strcpy(_dni, dni.c_str());
    }
    else { strcpy(_dni, "DNI fuera de rango");
    }
}

void Persona::setTelefono(string telefono){
    if (telefono.size()<20){
        strcpy(_telefono, telefono.c_str());
    }
    else { strcpy(_telefono, "telefono fuera de rango");
    }
}

void Persona::setEstado(bool estado){
    _estado = estado;
    }


//GETTERS - Mai
string Persona::getNombre() const { return _nombre;}
string Persona::getApellido() const { return _apellido;}
string Persona::getDni() const { return _dni;}
string Persona::getTelefono() const { return _telefono;}
bool Persona::getEstado() const { return _estado;}
